/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Plane.cpp
*/

#include "Plane.hpp"

namespace RayTracer::Primitives {
    Plane::Plane(const std::unordered_map<std::string, double>& dataMap) : Entity::Entity(RayTracer::Entity::EntityType::PRIMITIVE), _position(0, 0, 0), _color(0, 0, 0)
    {
        _position._x = dataMap.at("x");
        _position._y = dataMap.at("y");
        _position._z = dataMap.at("z");
        if (dataMap.at("axis") == 0)
            _axis = 'x';
        else if (dataMap.at("axis") == 1)
            _axis = 'y';
        else if (dataMap.at("axis") == 2)
            _axis = 'z';
    }

    void Plane::setAxis(const std::string &axis)
    {
        _axis = axis[0];
    }

    void Plane::setColor(const RayTracer::Vector &color)
    {
        _color = color;
    }
}
