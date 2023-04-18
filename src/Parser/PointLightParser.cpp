/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** PointLightParser.cpp
*/

#include "PointLightParser.hpp"

namespace RayTracer::Light {
    RayTracer::Vector PointLightParser::getPointLightPosition(const libconfig::Setting &pointLight)
    {
        RayTracer::Vector position(0, 0, 0);

        pointLight.lookupValue("x", position._x);
        pointLight.lookupValue("y", position._y);
        pointLight.lookupValue("z", position._z);
        return position;
    }

    void PointLightParser::createPointLight(const libconfig::Setting &pointLight, RayTracer::Scene::Scene &scene)
    {
        std::cout << "Create pointLight" << std::endl;
        for (int i = 0; i < pointLight.getLength(); i++) {
            if (!pointLight[i].exists("x") && !pointLight[i].exists("y") && !pointLight[i].exists("z"))
                throw Parser::Parser::ParserException("PointLight is missing parameters (x, y ,z).");
            auto *s = new PointLight();
            s->setPosition(getPointLightPosition(pointLight));
            RayTracer::Entity::IEntityPtr s_ptr = std::unique_ptr<PointLight>(s);
            scene.addEntity(&"pointLight" [i], s_ptr);
        }

    }
} // RayTracer
