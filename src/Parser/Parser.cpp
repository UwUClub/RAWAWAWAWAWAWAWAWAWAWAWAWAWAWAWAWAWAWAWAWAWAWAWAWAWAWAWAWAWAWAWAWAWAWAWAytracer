/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Parser.cpp
*/

#include "Parser.hpp"
#include "CameraParser.hpp"
#include "SphereParser.hpp"
#include "PlaneParser.hpp"
#include "PointLightParser.hpp"

namespace RayTracer::Parser {
    Parser::Parser(char **av, RayTracer::Scene::Scene &scene) : _cfg(), _scene(scene)
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
        const libconfig::Setting &root = _cfg.getRoot();
        if (!root.exists("camera") || !root["camera"].isGroup())
            throw ParserException("No 'camera' setting in configuration file.");
        const libconfig::Setting &camera = root["camera"];
        if (!camera.exists("resolution") || !camera.exists("position") || !camera.exists("rotation") || !camera.exists("fieldOfView"))
            throw ParserException("Camera is missing parameters (resolution, position, rotation, fieldOfView).");
        RayTracer::Camera cam;

        cam.setResolution(CameraParser::getCameraResolution(camera));
        cam.setPosition(CameraParser::getCameraPosition(camera));
        cam.setRotation(CameraParser::getCameraRotation(camera));
        cam.setFieldOfView(CameraParser::getCameraFieldOfView(camera));
        RayTracer::Entity::IEntityPtr cam_ptr = std::make_unique<RayTracer::Camera>(cam);
        _scene.addEntity("camera", cam_ptr);
    }

    void Parser::CreatePrimitive(RayTracer::Scene::Scene &scene)
    {
        const libconfig::Setting &root = _cfg.getRoot();
        if (!root.exists("primitives") || !root["primitives"].isGroup())
            throw ParserException("No 'primitives' setting in configuration file.");
        const libconfig::Setting &primitives = root["primitives"];
        if (!primitives.exists("spheres") || !primitives.exists("planes"))
            throw ParserException("Primitives is missing parameters (spheres, planes, cylinders, cones).");

        if (primitives.exists("spheres") && primitives["spheres"].isList())
            SphereParser::createSphere(primitives["spheres"], scene);
        if (primitives.exists("planes") && primitives["planes"].isList())
            PlaneParser::createPlane(primitives["planes"], scene);
    }

    void Parser::CreateLight(RayTracer::Scene::Scene &scene)
    {
        const libconfig::Setting &root = _cfg.getRoot();
        if (!root.exists("lights") || !root["lights"].isGroup())
            throw ParserException("No 'lights' setting in configuration file.");
        const libconfig::Setting &lights = root["lights"];
        if (!lights.exists("point") || !lights.exists("directional"))
            throw ParserException("Lights is missing parameters (point, directional).");

        if (lights.exists("point") && lights["point"].isList())
            Light::PointLightParser::createPointLight(lights["point"], scene);
    }
} // RayTracer