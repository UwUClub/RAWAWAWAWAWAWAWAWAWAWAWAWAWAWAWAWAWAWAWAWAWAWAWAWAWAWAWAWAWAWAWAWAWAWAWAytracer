/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Sphere.cpp
*/

#include "Sphere.hpp"

namespace RayTracer::Primitives {
    Sphere::Sphere() : Entity::Entity(RayTracer::Entity::EntityType::PRIMITIVE), _position(0, 0, 0), _radius(0), _color(0, 0, 0) {}

    void Sphere::setRadius(int aRadius)
    {
        _radius = aRadius;
    }

    void Sphere::setColor(const RayTracer::Vector &aColor)
    {
        _color = aColor;
    }

}