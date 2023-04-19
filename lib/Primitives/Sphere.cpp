/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Sphere.cpp
*/

#include "Sphere.hpp"

namespace RayTracer::Primitives {
    Sphere::Sphere() : _position(0, 0, 0), _radius(0), _color(0, 0, 0) {}

    void Sphere::setPosition(RayTracer::Point &position)
    {
        _position = position;
    }

    void Sphere::setRadius(int radius)
    {
        _radius = radius;
    }

    void Sphere::setColor(const RayTracer::Vector &color)
    {
        _color = color;
    }

    Entity::EntityType Sphere::getType() const
    {
        return Entity::EntityType::PRIMITIVE;
    }

    void Sphere::rotate(Vector &vector)
    {
        _position.x += vector._x;
        _position.y += vector._y;
        _position.z += vector._z;
    }

    void Sphere::translate(Vector &vector)
    {
        _position.x += vector._x;
        _position.y += vector._y;
        _position.z += vector._z;
    }
}