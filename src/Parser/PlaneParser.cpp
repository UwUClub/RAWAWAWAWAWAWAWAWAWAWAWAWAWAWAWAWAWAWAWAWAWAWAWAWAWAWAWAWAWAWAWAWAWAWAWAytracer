/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** PlaneParser.cpp
*/

#include "PlaneParser.hpp"

namespace RayTracer::Parser {
    std::string PlaneParser::getPlaneAxis(const libconfig::Setting &plane)
    {
        std::string axis;

        if (!plane.exists("axis"))
            throw Parser::ParserException("Sphere is missing parameters (radius).");
        plane.lookupValue("axis", axis);
        if (axis != "X" && axis != "Y" && axis != "Z")
            throw Parser::ParserException("Axis must be x, y or z.");
        return axis;
    }

    int PlaneParser::getPlanePosition(const libconfig::Setting &plane)
    {
        int pos;

        if (!plane.exists("position"))
            throw Parser::ParserException("Sphere is missing parameters (radius).");
        plane.lookupValue("position", pos);
        return pos;
    }

    RayTracer::Vector PlaneParser::getPlaneColor(const libconfig::Setting &plane)
    {
        RayTracer::Vector color(0, 0, 0);
        const libconfig::Setting &colorSetting = plane["color"];

        if (!colorSetting.exists("r") || !colorSetting.exists("g") || !colorSetting.exists("b"))
            throw Parser::ParserException("Sphere is missing parameters (r, g, b).");
        colorSetting.lookupValue("r", color._x);
        colorSetting.lookupValue("g", color._y);
        colorSetting.lookupValue("b", color._z);
        return color;
    }

    void PlaneParser::createPlane(const libconfig::Setting &plane, RayTracer::Scene::Scene &scene)
    {
        std::cout << "Create plane" << std::endl;
        for (int i = 0; i < plane.getLength(); i++) {
            if (!plane[i].exists("axis") || !plane[i].exists("position") || !plane[i].exists("color"))
                throw Parser::ParserException("Missing plane parameters");
            auto *p = new Primitives::Plane();
            p->setAxis(getPlaneAxis(plane[i]));
            p->setPosition(getPlanePosition(plane[i]));
            p->setColor(getPlaneColor(plane[i]));
            RayTracer::Entity::IEntityPtr p_ptr = std::unique_ptr<Primitives::Plane>(p);
            scene.addEntity(&"plane" [i], p_ptr);
        }
    }
} // RayTracer
