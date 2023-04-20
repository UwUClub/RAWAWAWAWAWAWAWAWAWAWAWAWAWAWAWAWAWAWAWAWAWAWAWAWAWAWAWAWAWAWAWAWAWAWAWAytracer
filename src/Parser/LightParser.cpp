/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** PointLightParser.cpp
*/

#include "LightParser.hpp"
#include "Parser.hpp"
#include <cctype>
#include <cstring>

namespace RayTracer::Light {
    void LightParser::getLightPosition(const libconfig::Setting &primitive, std::unordered_map<std::string, double> &data)
    {
        float x;
        float y;
        float z;

        if (!primitive.exists("x") || !primitive.exists("y") || !primitive.exists("z"))
            throw RayTracer::Parser::Parser::ParserException("Light is missing parameters (x, y, z).");
        primitive.lookupValue("x", x);
        primitive.lookupValue("y", y);
        primitive.lookupValue("z", z);
        data.insert(std::make_pair("x", x));
        data.insert(std::make_pair("y", y));
        data.insert(std::make_pair("z", z));
    }

    void LightParser::createLight(const libconfig::Setting &light, std::unordered_map<std::string, double> &lightData,  RayTracer::Plugin::PluginManager &pluginManager, RayTracer::Scene::Scene &scene)
    {
        for (int i = 0; i < light.getLength(); i++) {
            if (!light[i].exists("x") && !light[i].exists("y") && !light[i].exists("z"))
                throw Parser::Parser::ParserException("PointLight is missing parameters (x, y ,z).");
            getLightPosition(light[i], lightData);
            std::string lightName;
            if (std::strcmp(light.getName(), "point") == 0) {
                lightName = "PointLight";
            }
            std::cout << lightName << std::endl;
            auto lightEntity = pluginManager.createEntity(lightName, lightData);
            scene.addEntity(lightName + std::to_string(i), lightEntity);
        }

    }
} // RayTracer