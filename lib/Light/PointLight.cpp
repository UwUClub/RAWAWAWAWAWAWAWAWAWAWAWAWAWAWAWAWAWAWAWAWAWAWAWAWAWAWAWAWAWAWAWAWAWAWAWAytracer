/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** PointLight.cpp
*/

#include "PointLight.hpp"

namespace RayTracer::Light {
    PointLight::PointLight() : Light(), _position(0, 0, 0) {}

    void PointLight::setPosition(const Point &position)
    {
        _position = position;
    }

    Entity::EntityType PointLight::getType() const
    {
        return Entity::EntityType::LIGHT;
    }

    void PointLight::translate(const RayTracer::Vector &vector)
    {
        _position._x += vector._x;
        _position._y += vector._y;
        _position._z += vector._z;
    }

    void PointLight::rotate(const RayTracer::Vector &vector)
    {
        _position._x += vector._x;
        _position._y += vector._y;
        _position._z += vector._z;
    }
}
