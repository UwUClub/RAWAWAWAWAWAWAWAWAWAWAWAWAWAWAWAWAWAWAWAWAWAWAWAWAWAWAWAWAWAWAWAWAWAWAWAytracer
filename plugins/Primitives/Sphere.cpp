//
// Created by beafowl on 18/04/23.
//

#include "Sphere.hpp"

namespace RayTracer::Primitives {
    Sphere::Sphere() : _position(0, 0, 0), _radius(0), _color(0, 0, 0) {}

    void Sphere::setPosition(const RayTracer::Vector &position)
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
        _position._x += vector._x;
        _position._y += vector._y;
        _position._z += vector._z;
    }

    void Sphere::translate(Vector &vector)
    {
        _position._x += vector._x;
        _position._y += vector._y;
        _position._z += vector._z;
    }
}