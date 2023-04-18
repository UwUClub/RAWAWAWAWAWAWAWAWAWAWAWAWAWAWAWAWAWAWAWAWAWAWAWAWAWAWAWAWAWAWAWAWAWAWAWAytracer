/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** SphereParser.cpp
*/

#include "SphereParser.hpp"

namespace RayTracer::Parser {
    RayTracer::Vector SphereParser::getSpherePosition(const libconfig::Setting &sphere) {
        RayTracer::Vector pos(0, 0, 0);

        if (!sphere.exists("x") || !sphere.exists("y") || !sphere.exists("z"))
            throw Parser::ParserException("Sphere is missing parameters (x, y, z).");
        sphere.lookupValue("x", pos._x);
        sphere.lookupValue("y", pos._y);
        sphere.lookupValue("z", pos._z);
        return pos;
    }

    int SphereParser::getSphereRadius(const libconfig::Setting &sphere) {
        int radius;

        if (!sphere.exists("r"))
            throw Parser::ParserException("Sphere is missing parameters (radius).");
        sphere.lookupValue("r", radius);
        return radius;
    }

    RayTracer::Vector SphereParser::getSphereColor(const libconfig::Setting &sphere) {
        RayTracer::Vector color(0, 0, 0);
        const libconfig::Setting &colorSetting = sphere["color"];

        if (!colorSetting.exists("r") || !colorSetting.exists("g") || !colorSetting.exists("b"))
            throw Parser::ParserException("Sphere is missing parameters (r, g, b).");
        colorSetting.lookupValue("r", color._x);
        colorSetting.lookupValue("g", color._y);
        colorSetting.lookupValue("b", color._z);
        return color;
    }

    void SphereParser::createSphere(const libconfig::Setting &sphere, RayTracer::Scene::Scene &scene)
    {
        std::cout << "Create sphere" << std::endl;
        for (int i = 0; i < sphere.getLength(); i++) {
            if (!sphere[i].exists("x") && !sphere[i].exists("y") && !sphere[i].exists("z") && !sphere[i].exists("r") &&
            !sphere[i].exists("color"))
                throw Parser::ParserException("Missing sphere parameters");
            auto *s = new Primitives::Sphere();
            s->setPosition(getSpherePosition(sphere[i]));
            s->setRadius(getSphereRadius(sphere[i]));
            s->setColor(getSphereColor(sphere[i]));
            RayTracer::Entity::IEntityPtr s_ptr = std::unique_ptr<Primitives::Sphere>(s);
            scene.addEntity(&"sphere" [i], s_ptr);
        }
    }
}// RayTracer

