/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Parser.cpp
*/

#include "Parser.hpp"

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
        }
    }

    Parser::~Parser()
    {

    }

    RayTracer::Camera Parser::CreateCamera()
    {
        const libconfig::Setting &root = _cfg.getRoot();
        if (!root.exists("camera") || !root["camera"].isGroup())
            throw ParserException("No 'camera' setting in configuration file.");
        const libconfig::Setting &camera = root["camera"];
        if (!camera.exists("x") || !camera.exists("y") || !camera.exists("fov"))
            throw ParserException("Camera is missing parameters (x, y, fov).");
        RayTracer::Camera cam;
        int x;
        int y;
        float fov;
        std::string resolution;

        camera.lookupValue("resolution", resolution);
        std::cout << resolution << std::endl;
        camera.lookupValue("y", y);
        camera.lookupValue("fov", fov);
        cam.setResolution(std::make_pair(x, y));
        cam.setFieldOfView(fov);
        return cam;
    }
    
} // RayTracer