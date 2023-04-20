/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Plane.cpp
*/

#include "Plane.hpp"

namespace RayTracer::Primitives {
    Plane::Plane() : _axis('Z'), _position(0, 0, 0), _color(0, 0, 0)
    {
    }

    void Plane::setPosition(const Point &position)
    {
        _position = position;
    }

    void Plane::setAxis(const std::string &axis)
    {
        _axis = axis[0];
    }

    void Plane::setColor(const RayTracer::Vector &color)
    {
        _color = color;
    }

    [[nodiscard]] Entity::EntityType Plane::getType() const
    {
        return Entity::EntityType::PRIMITIVE;
    }

    void Plane::rotate(const Vector &vector)
    {
        (void)(vector);
        if (_axis == 'X')
            _axis = 'Y';
        else if (_axis == 'Y')
            _axis = 'Z';
        else if (_axis == 'Z')
            _axis = 'X';
        else
            _axis = 'Z';
    }

    void Plane::translate(const Vector &vector)
    {
        _position._x += vector._x;
        _position._y += vector._y;
        _position._z += vector._z;
    }
}
