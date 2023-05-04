/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** PrimitivesParser.cpp
*/

#include "PrimitivesParser.hpp"
#include "IEntity.hpp"
#include <cstring>

namespace RayTracer::Parser
{
    void PrimitivesParser::getPrimitivePosition(const libconfig::Setting &aPrimitive,
        Entity::DataEntityMap &aData)
    {
        int myX = 0;
        int myY = 0;
        int myZ = 0;

        if (!aPrimitive.exists("x") || !aPrimitive.exists("y") || !aPrimitive.exists("z"))
            throw Parser::ParserException("Primitive is missing parameters (x, y, z).");
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

    void PrimitivesParser::getPrimitiveColor(const libconfig::Setting &aPrimitive,
        Entity::DataEntityMap &aData)
    {
        int myR = 0;
        int myG = 0;
        int myB = 0;
        const libconfig::Setting &myColor = aPrimitive["color"];

        if (!myColor.exists("r") || !myColor.exists("g") || !myColor.exists("b"))
            throw Parser::ParserException("Color is missing parameters (r, g, b).");
        aPrimitive.lookupValue("r", myR);
        aPrimitive.lookupValue("g", myG);
        aPrimitive.lookupValue("b", myB);
        auto myDoubleR = static_cast<double>(myR);
        auto myDoubleG = static_cast<double>(myG);
        auto myDoubleB = static_cast<double>(myB);
        aData.insert(std::make_pair("r", myDoubleR));
        aData.insert(std::make_pair("g", myDoubleG));
        aData.insert(std::make_pair("b", myDoubleB));
    }

    void PrimitivesParser::getPrimitiveRadius(const libconfig::Setting &aPrimitive,
        Entity::DataEntityMap &aData)
    {
        int myRadius = 0;

        if (!aPrimitive.exists("r"))
            throw Parser::ParserException("Primitive is missing parameters (radius).");
        aPrimitive.lookupValue("r", myRadius);
        auto myDoubleRadius = static_cast<double>(myRadius);
        aData.insert(std::make_pair("radius", myDoubleRadius));
    }

    void PrimitivesParser::getPlaneAxis(const libconfig::Setting &aPlane,
        Entity::DataEntityMap &aData)
    {
        std::string myAxisString;
        double myAxis = 0;

        if (!aPlane.exists("axis"))
            throw Parser::ParserException("Plane is missing parameters (axis).");
        aPlane.lookupValue("axis", myAxisString);
        if (myAxisString == "X")
            myAxis = 0;
        else if (myAxisString == "Y")
            myAxis = 1;
        else if (myAxisString == "Z")
            myAxis = 2;
        else
            throw Parser::ParserException("Plane axis is invalid.");
        aData.insert(std::make_pair("axis", myAxis));
    }

    void PrimitivesParser::getPlanePosition(const libconfig::Setting &aPlane,
        Entity::DataEntityMap &aData)
    {
        int myPosition = 0;

        if (!aPlane.exists("position"))
            throw Parser::ParserException("Plane is missing parameters (position, normal).");
        aPlane.lookupValue("position", myPosition);
        auto myDoublePosition = static_cast<double>(myPosition);
        aData.insert(std::make_pair("position", myDoublePosition));
    }

    void PrimitivesParser::createPlane(const libconfig::Setting &aPlane,
        Entity::DataEntityMap &aPrimitiveData, RayTracer::Plugin::PluginManager &aPluginManager,
        RayTracer::Scene::Scene &aScene)
    {
        for (int i = 0; i < aPlane.getLength(); i++) {
            getPlaneAxis(aPlane[i], aPrimitiveData);
            getPlanePosition(aPlane[i], aPrimitiveData);
            getPrimitiveColor(aPlane[i], aPrimitiveData);
            auto myPrimitiveEntity = aPluginManager.createEntity("Plane", aPrimitiveData);
            aScene.addEntity("Plane", myPrimitiveEntity);
        }
    }

    void PrimitivesParser::createPrimitive(const libconfig::Setting &aSphere,
        std::unordered_map<std::string, double> &aPrimitiveData,
        RayTracer::Plugin::PluginManager &aPluginManager, RayTracer::Scene::Scene &aScene)
    {
        for (int i = 0; i < aSphere.getLength(); i++) {
            getPrimitivePosition(aSphere[i], aPrimitiveData);
            getPrimitiveRadius(aSphere[i], aPrimitiveData);
            getPrimitiveColor(aSphere[i], aPrimitiveData);
            auto myPrimitiveEntity = aPluginManager.createEntity(aSphere.getName(), aPrimitiveData);
            aScene.addEntity(aSphere.getName(), myPrimitiveEntity);
        }
    }
} // namespace RayTracer::Parser
