/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Parser.cpp
*/

#include "Parser.hpp"
#include "CameraParser.hpp"
#include "PrimitivesParser.hpp"
#include "LightParser.hpp"

namespace RayTracer::Parser {
    Parser::Parser(char **av, RayTracer::Scene::Scene &scene, RayTracer::Plugin::PluginManager &pluginManager) : _cfg(), _scene(scene), _pluginManager(pluginManager)
    {
        try {
            _cfg.readFile(av[1]);
        }
        catch (const libconfig::FileIOException &fioex) {
            throw ParserException("I/O error while reading file.");
        }
        catch (const libconfig::ParseException &pex) {
            std::string error = "Parse error at ";
            error += pex.getFile();
            error += ":";
            error += std::to_string(pex.getLine());
            error += " - ";
            error += pex.getError();
            throw ParserException(error);
        } try {
            CreateCamera();
            CreatePrimitive(scene);
            CreateLight(scene);
        } catch (const ParserException &e) {
            std::cerr << e.what() << std::endl;
        }
    }

    void Parser::CreateCamera()
    {
        std::unordered_map<std::string, double> cameraData;
        const libconfig::Setting &root = _cfg.getRoot();
        if (!root.exists("camera") || !root["camera"].isGroup())
            throw ParserException("No 'camera' setting in configuration file.");
        const libconfig::Setting &camera = root["camera"];
        if (!camera.exists("resolution") || !camera.exists("position") || !camera.exists("rotation") || !camera.exists("fieldOfView"))
            throw ParserException("Camera is missing parameters (resolution, position, rotation, fieldOfView).");

        CameraParser::getCameraResolution(camera, cameraData);
        CameraParser::getCameraPosition(camera, cameraData);
        CameraParser::getCameraRotation(camera, cameraData);
        CameraParser::getCameraFieldOfView(camera, cameraData);

        auto camEntity = _pluginManager.createEntity("camera", cameraData);
        _scene.addEntity("camera", camEntity);
    }

    void Parser::CreatePrimitive(RayTracer::Scene::Scene &scene)
    {
        std::unordered_map<std::string, double> primitiveData;
        const libconfig::Setting &root = _cfg.getRoot();
        if (!root.exists("primitives") || !root["primitives"].isGroup())
            throw ParserException("No 'primitives' setting in configuration file.");
        const libconfig::Setting &primitives = root["primitives"];
        if (!primitives.exists("spheres") || !primitives.exists("planes") || !primitives.exists("cylinders") || !primitives.exists("cones"))
            throw ParserException("Primitives is missing parameters (spheres, planes, cylinders, cones).");

        if (primitives.exists("planes") && primitives["planes"].isList())
            PrimitivesParser::createPlane(primitives["planes"], primitiveData, _pluginManager,scene);
        else {
            for (int i = 0; i < primitives.getLength(); i++)
                PrimitivesParser::createPrimitive(primitives[i], primitiveData, _pluginManager, scene);
        }
    }

    void Parser::CreateLight(RayTracer::Scene::Scene &scene)
    {
        std::unordered_map<std::string, double> lightData;
        const libconfig::Setting &root = _cfg.getRoot();
        if (!root.exists("lights") || !root["lights"].isGroup())
            throw ParserException("No 'lights' setting in configuration file.");
        const libconfig::Setting &lights = root["lights"];
        if (!lights.exists("point") || !lights.exists("directional"))
            throw ParserException("Lights is missing parameters (point, directional).");

        if (lights.exists("point") && lights["point"].isList())
            Light::LightParser::createLight(lights["point"], lightData,_pluginManager, scene);
    }
} // RayTracer