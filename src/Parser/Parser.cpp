/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Parser.cpp
*/

#include "Parser.hpp"

namespace RayTracer::Parser {
    Parser::Parser(int ac, char **av)
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

    RayTracer::Camera::Camera Parser::getCamera()
    {
        RayTracer::Camera::Camera camera;
        const libconfig::Setting &root = _cfg.getRoot();
        const libconfig::Setting &cameraSetting = root["camera"];
        cameraSetting.lookupValue("position", camera.position);
        cameraSetting.lookupValue("rotation", camera.rotation);
        cameraSetting.lookupValue("fov", camera.fov);
        return camera;
    }
    
} // RayTracer