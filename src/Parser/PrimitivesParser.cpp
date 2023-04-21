/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** PrimitivesParser.cpp
*/

#include <cstring>
#include "PrimitivesParser.hpp"

namespace RayTracer::Parser {
    void PrimitivesParser::getPrimitivePosition(const libconfig::Setting &primitive, std::unordered_map<std::string, double> &data)
    {
        float x;
        float y;
        float z;

        if (!primitive.exists("x") || !primitive.exists("y") || !primitive.exists("z"))
            throw Parser::ParserException("Primitive is missing parameters (x, y, z).");
        primitive.lookupValue("x", x);
        primitive.lookupValue("y", y);
        primitive.lookupValue("z", z);
        data.insert(std::make_pair("x", x));
        data.insert(std::make_pair("y", y));
        data.insert(std::make_pair("z", z));
    }

    void PrimitivesParser::getPrimitiveColor(const libconfig::Setting &primitive, std::unordered_map<std::string, double> &data)
    {
        float r;
        float g;
        float b;

        const libconfig::Setting &color = primitive["color"];
        if (!color.exists("r") || !color.exists("g") || !color.exists("b"))
            throw Parser::ParserException("Color is missing parameters (r, g, b).");
        primitive.lookupValue("r", r);
        primitive.lookupValue("g", g);
        primitive.lookupValue("b", b);
        data.insert(std::make_pair("r", r));
        data.insert(std::make_pair("g", g));
        data.insert(std::make_pair("b", b));
    }

    void PrimitivesParser::getPrimitiveRadius(const libconfig::Setting &primitive, std::unordered_map<std::string, double> &data)
    {
        double radius;

        if (!primitive.exists("r"))
            throw Parser::ParserException("Primitive is missing parameters (radius).");
        primitive.lookupValue("r", radius);
        data.insert(std::make_pair("radius", radius));
    }

    void PrimitivesParser::getPlaneAxis(const libconfig::Setting &plane, std::unordered_map<std::string, double> &data)
    {
        std::string axisString;
        double axis;

        if (!plane.exists("axis"))
            throw Parser::ParserException("Plane is missing parameters (axis).");
        plane.lookupValue("axis", axisString);
        if (axisString == "X")
            axis = 0;
        else if (axisString == "Y")
            axis = 1;
        else if (axisString == "Z")
            axis = 2;
        else
            throw Parser::ParserException("Plane axis is invalid.");
        data.insert(std::make_pair("axis", axis));
    }

    void PrimitivesParser::getPlanePosition(const libconfig::Setting &plane, std::unordered_map<std::string, double> &data)
    {
        float position;

        if (!plane.exists("position"))
            throw Parser::ParserException("Plane is missing parameters (position, normal).");
        plane.lookupValue("position", position);
        data.insert(std::make_pair("position", position));
    }

    void PrimitivesParser::createPlane(const libconfig::Setting &plane, std::unordered_map<std::string, double> &primitiveData, RayTracer::Plugin::PluginManager &pluginManager, RayTracer::Scene::Scene &scene)
    {
        std::cout << "Create plane" << std::endl;
        for (int i = 0; i < plane.getLength(); i++) {
            getPlaneAxis(plane[i], primitiveData);
            getPlanePosition(plane[i], primitiveData);
            getPrimitiveColor(plane[i], primitiveData);
            auto primitiveEntity = pluginManager.createEntity("Plane", primitiveData);
            scene.addEntity("Plane", primitiveEntity);
        }
    }

    void PrimitivesParser::createPrimitive(const libconfig::Setting &primitive, std::unordered_map<std::string, double> &primitiveData, RayTracer::Plugin::PluginManager &pluginManager, RayTracer::Scene::Scene &scene)
    {
        std::cout << "Create primitive" << std::endl;
        std::cout << primitive[0].getLength() << std::endl;
        std::cout << primitive[1].getLength() << std::endl;
        for (int i = 0; i < primitive.getLength(); i++) {
            getPrimitivePosition(primitive[i], primitiveData);
            getPrimitiveRadius(primitive[i], primitiveData);
            getPrimitiveColor(primitive[i], primitiveData);
            auto primitiveEntity = pluginManager.createEntity(primitive.getName(), primitiveData);
            scene.addEntity(primitive.getName(), primitiveEntity);
        }
        std::cout << "Sphere created" << std::endl;
    }
}
