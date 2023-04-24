/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Sphere.cpp
*/

#include "Sphere.hpp"

namespace RayTracer::Primitives {
    Sphere::Sphere(const std::unordered_map<std::string, double> &dataMap) : Entity::Entity(RayTracer::Entity::EntityType::PRIMITIVE), _position(0, 0, 0),_color(0, 0, 0)
    {
        _position._x = dataMap.at("x");
        _position._y = dataMap.at("y");
        _position._z = dataMap.at("z");
        _radius = dataMap.at("r");

    }

    void Sphere::setRadius(int aRadius)
    {
        _radius = aRadius;
    }

    void Sphere::setColor(const RayTracer::Vector &aColor)
    {
        _color = aColor;
    }
}
