/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** CameraParser.cpp
*/

#include "CameraParser.hpp"

namespace RayTracer::Parser {
    void CameraParser::getCameraResolution(const libconfig::Setting &camera, std::unordered_map<std::string, double> &data)
    {
        float width;
        float height;
        const libconfig::Setting &resolution = camera["resolution"];

        if (!resolution.exists("width") || !resolution.exists("height"))
            throw Parser::ParserException("Camera is missing parameters (width, height).");
        resolution.lookupValue("width", width);
        resolution.lookupValue("height", height);
        data.insert(std::make_pair("width", width));
        data.insert(std::make_pair("height", height));
    }

    void CameraParser::getCameraFieldOfView(const libconfig::Setting &camera, std::unordered_map<std::string, double> &data)
    {
        float fov;

        if (!camera.exists("fieldOfView"))
            throw Parser::ParserException("Camera is missing parameters (fieldOfView).");
        camera.lookupValue("fieldOfView", fov);
        data.insert(std::make_pair("fov", fov));
    }

    void CameraParser::getCameraPosition(const libconfig::Setting &camera, std::unordered_map<std::string, double> &data)
    {
        float x;
        float y;
        float z;
        const libconfig::Setting &position = camera["position"];

        if (!position.exists("x") || !position.exists("y") || !position.exists("z"))
            throw Parser::ParserException("Camera is missing parameters (x, y, z).");
        position.lookupValue("x", x);
        position.lookupValue("y", y);
        position.lookupValue("z", z);
        data.insert(std::make_pair("x", x));
        data.insert(std::make_pair("y", y));
        data.insert(std::make_pair("z", z));
    }

    void CameraParser::getCameraRotation(const libconfig::Setting &camera, std::unordered_map<std::string, double> &data)
    {
        float x;
        float y;
        float z;
        const libconfig::Setting &rotation = camera["rotation"];

        if (!rotation.exists("x") || !rotation.exists("y") || !rotation.exists("z"))
            throw Parser::ParserException("Camera is missing parameters (x, y, z).");
        rotation.lookupValue("x", x);
        rotation.lookupValue("y", y);
        rotation.lookupValue("z", z);
        data.insert(std::make_pair("rotate_x", x));
        data.insert(std::make_pair("rotate_y", y));
        data.insert(std::make_pair("rotate_z", z));
    }

    void CameraParser::createCamera(const libconfig::Setting &camera, std::unordered_map<std::string, double> &cameraData, RayTracer::Plugin::PluginManager &pluginManager, RayTracer::Scene::Scene &scene)
    {
        getCameraPosition(camera, cameraData);
        getCameraRotation(camera, cameraData);
        getCameraResolution(camera, cameraData);
        getCameraFieldOfView(camera, cameraData);
        auto cameraEntity = pluginManager.createEntity("Camera", cameraData);
        scene.addEntity("Camera", cameraEntity);
    }
} // RayTracer