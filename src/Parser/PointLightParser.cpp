/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** PointLightParser.cpp
*/

#include "PointLightParser.hpp"

namespace RayTracer::Light {
    RayTracer::Point &PointLightParser::getPointLightPosition(const libconfig::Setting &pointLight)
    {
        RayTracer::Point position(0, 0, 0);
        auto pos_ptr = std::make_shared<Point>(position);

        pointLight.lookupValue("x", pos_ptr->x);
        pointLight.lookupValue("y", pos_ptr->y);
        pointLight.lookupValue("z", pos_ptr->z);
        return *pos_ptr;
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
