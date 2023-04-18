/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** CameraParser.cpp
*/

#include "CameraParser.hpp"

namespace RayTracer::Parser {
    std::pair<int, int> CameraParser::getCameraResolution(const libconfig::Setting &camera) {
        std::pair<int, int> res;
        const libconfig::Setting &resolution = camera["resolution"];

        if (!resolution.exists("width") || !resolution.exists("height"))
            throw Parser::ParserException("Camera is missing parameters (width, height).");
        resolution.lookupValue("width", res.first);
        resolution.lookupValue("height", res.second);
        return res;
    }

    float CameraParser::getCameraFieldOfView(const libconfig::Setting &camera) {
        float fov;

        if (!camera.exists("fieldOfView"))
            throw Parser::ParserException("Camera is missing parameters (fieldOfView).");
        camera.lookupValue("fieldOfView", fov);
        return fov;
    }

    RayTracer::Point &CameraParser::getCameraPosition(const libconfig::Setting &camera) {
        RayTracer::Point pos(0, 0, 0);
        auto pos_ptr = std::make_shared<Point>(pos);
        const libconfig::Setting &position = camera["position"];

        if (!position.exists("x") || !position.exists("y") || !position.exists("z"))
            throw Parser::ParserException("Camera is missing parameters (x, y, z).");
        position.lookupValue("x", pos_ptr->x);
        position.lookupValue("y", pos_ptr->y);
        position.lookupValue("z", pos_ptr->z);
        return *pos_ptr;
    }

    RayTracer::Vector CameraParser::getCameraRotation(const libconfig::Setting &camera) {
        RayTracer::Vector rot(0, 0, 0);
        const libconfig::Setting &rotation = camera["rotation"];

        std::cout << "Create camera" << std::endl;
        if (!rotation.exists("x") || !rotation.exists("y") || !rotation.exists("z"))
            throw Parser::ParserException("Camera is missing parameters (x, y, z).");
        rotation.lookupValue("x", rot._x);
        rotation.lookupValue("y", rot._y);
        rotation.lookupValue("z", rot._z);
        return rot;
    }
} // RayTracer