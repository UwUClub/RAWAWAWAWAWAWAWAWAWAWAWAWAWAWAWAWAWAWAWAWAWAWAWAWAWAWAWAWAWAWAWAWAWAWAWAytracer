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
        int myX = 0;
        int myY = 0;
        int myZ = 0;

        if (!aPrimitive.exists("x") || !aPrimitive.exists("y") || !aPrimitive.exists("z"))
            throw RayTracer::Parser::Parser::ParserException(
                "Light is missing parameters (x, y, z).");
        aPrimitive.lookupValue("x", myX);
        aPrimitive.lookupValue("y", myY);
        aPrimitive.lookupValue("z", myZ);
        auto myDoubleX = static_cast<double>(myX);
        auto myDoubleY = static_cast<double>(myY);
        auto myDoubleZ = static_cast<double>(myZ);
        aData.insert(std::make_pair("x", myDoubleX));
        aData.insert(std::make_pair("y", myDoubleY));
        aData.insert(std::make_pair("z", myDoubleZ));
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

    void LightParser::createBasicLight(const libconfig::Setting &aLight, Entity::DataEntityMap &aLightData,
                                       RayTracer::Plugin::PluginManager &aPluginManager, RayTracer::Scene::Scene &aScene)
    {
        double myAmbient = 0;
        double myDiffuse = 0;

        aLight.lookupValue("ambient", myAmbient);
        aLight.lookupValue("diffuse", myDiffuse);
        aLightData.insert(std::make_pair("ambient", myAmbient));
        aLightData.insert(std::make_pair("diffuse", myDiffuse));
        auto myLightEntity = aPluginManager.createEntity("BasicLight", aLightData);
        aScene.addEntity("BasicLight", myLightEntity);
    }
} // namespace RayTracer::Light
