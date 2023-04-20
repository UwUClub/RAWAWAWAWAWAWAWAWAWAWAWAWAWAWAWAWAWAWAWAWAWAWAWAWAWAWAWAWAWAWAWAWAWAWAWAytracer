/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Sphere.cpp
*/

#include "Sphere.hpp"

namespace RayTracer::Primitives {
    Sphere::Sphere() : Entity::Entity(RayTracer::Entity::EntityType::PRIMITIVE), _position(0, 0, 0), _radius(0), _color(0, 0, 0) {}

    void Sphere::setRadius(int radius)
    {
        _radius = radius;
    }

    void Sphere::setColor(const RayTracer::Vector &color)
    {
        _color = color;
    }

}