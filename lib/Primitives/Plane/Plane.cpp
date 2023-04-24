/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Plane.cpp
*/

#include "Plane.hpp"

namespace RayTracer::Primitives {
    Plane::Plane() : Entity::Entity(RayTracer::Entity::EntityType::PRIMITIVE), _axis('Z'), _position(0, 0, 0), _color(0, 0, 0)
    {
    }

    void Plane::setAxis(const std::string &aAxis)
    {
        _axis = aAxis[0];
    }

    void Plane::setColor(const RayTracer::Vector &aColor)
    {
        _color = aColor;
    }

}
