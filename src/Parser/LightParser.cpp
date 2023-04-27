/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** PointLightParser.cpp
*/

#include "LightParser.hpp"
#include "IEntity.hpp"
#include "Parser.hpp"
#include <cstring>

namespace RayTracer::Light
{
    void LightParser::getLightPosition(const libconfig::Setting &aPrimitive,
        Entity::DataEntityMap &aData)
    {
        float myX = 0;
        float myY = 0;
        float myZ = 0;

        if (!aPrimitive.exists("x") || !aPrimitive.exists("y") || !aPrimitive.exists("z"))
            throw RayTracer::Parser::Parser::ParserException(
                "Light is missing parameters (x, y, z).");
        aPrimitive.lookupValue("x", myX);
        aPrimitive.lookupValue("y", myY);
        aPrimitive.lookupValue("z", myZ);
        aData.insert(std::make_pair("x", myX));
        aData.insert(std::make_pair("y", myY));
        aData.insert(std::make_pair("z", myZ));
    }

    void LightParser::createLight(const libconfig::Setting &aLight,
        Entity::DataEntityMap &aLightData, RayTracer::Plugin::PluginManager &aPluginManager,
        RayTracer::Scene::Scene &aScene)
    {
        for (int i = 0; i < aLight.getLength(); i++) {
            if (!aLight[i].exists("x") && !aLight[i].exists("y") && !aLight[i].exists("z"))
                throw Parser::Parser::ParserException(
                    "PointLight is missing parameters (x, y ,z).");
            getLightPosition(aLight[i], aLightData);
            auto myLightEntity = aPluginManager.createEntity(aLight.getName(), aLightData);
            aScene.addEntity(aLight.getName(), myLightEntity);
        }
    }
} // namespace RayTracer::Light
