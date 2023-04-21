/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Parser.cpp
*/

#include <cstring>
#include "Parser.hpp"
#include "CameraParser.hpp"
#include "PrimitivesParser.hpp"
#include "LightParser.hpp"

namespace RayTracer::Parser {
    Parser::Parser(char **av, RayTracer::Scene::Scene &scene, RayTracer::Plugin::PluginManager &pluginManager) : _cfg()
    {
        try {
            _cfg.readFile(av[1]);
        } catch (const libconfig::FileIOException &fioex) {
            throw ParserException("I/O error while reading file.");
        } catch (const libconfig::ParseException &pex) {
            std::string error = "Parse error at ";
            error += pex.getFile();
            error += ":";
            error += std::to_string(pex.getLine());
            error += " - ";
            error += pex.getError();
            throw ParserException(error);
        } try {
            CreateCamera(scene, pluginManager);
            CreatePrimitive(scene, pluginManager);
            CreateLight(scene, pluginManager);
        } catch (const ParserException &e) {
            std::cerr << e.what() << std::endl;
        }
    }

    void Parser::CreateCamera(RayTracer::Scene::Scene &scene, RayTracer::Plugin::PluginManager &pluginManager)
    {
        std::unordered_map<std::string, double> cameraData;
        const libconfig::Setting &root = _cfg.getRoot();
        if (!root.exists("camera") || !root["camera"].isGroup())
            throw ParserException("No 'camera' setting in configuration file.");
        const libconfig::Setting &camera = root["camera"];
        if (!camera.exists("resolution") || !camera.exists("position") || !camera.exists("rotation") || !camera.exists("fieldOfView"))
            throw ParserException("Camera is missing parameters (resolution, position, rotation, fieldOfView).");

        CameraParser::createCamera(camera, cameraData, pluginManager, scene);
    }

    void Parser::CreatePrimitive(RayTracer::Scene::Scene &scene, RayTracer::Plugin::PluginManager &pluginManager)
    {
        std::unordered_map<std::string, double> primitiveData;
        const libconfig::Setting &root = _cfg.getRoot();
        if (!root.exists("primitives") || !root["primitives"].isGroup())
            throw ParserException("No 'primitives' setting in configuration file.");
        const libconfig::Setting &primitives = root["primitives"];

        for (int i = 0; i < primitives.getLength(); i++) {
            std::cout << "primitive name " << primitives[i].getName() << std::endl;
            if (std::strcmp(primitives[i].getName(), "Planes") == 0) {
                PrimitivesParser::createPlane(primitives["Planes"], primitiveData, pluginManager, scene);
            } else {
                for (int y = 0; y < primitives[i].getLength() && std::strcmp(primitives[i].getName(), "Planes") == 0; y++)
                    PrimitivesParser::createPrimitive(primitives[y], primitiveData, pluginManager, scene);
            }
        }
    }

    void Parser::CreateLight(RayTracer::Scene::Scene &scene, RayTracer::Plugin::PluginManager &pluginManager)
    {
        std::unordered_map<std::string, double> lightData;
        const libconfig::Setting &root = _cfg.getRoot();
        if (!root.exists("lights") || !root["lights"].isGroup())
            throw ParserException("No 'lights' setting in configuration file.");
        const libconfig::Setting &lights = root["lights"];

        if (lights.exists("point") && lights["point"].isList())
            Light::LightParser::createLight(lights["point"], lightData,pluginManager, scene);
    }
} // RayTracer