/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** PointLight.cpp
*/

#include "PointLight.hpp"

namespace RayTracer::Light {
    PointLight::PointLight() : Light(), _position(0, 0, 0) {}

    void PointLight::setPosition(Point &position)
    {
        _position = position;
    }

    Entity::EntityType PointLight::getType() const
    {
        return Entity::EntityType::LIGHT;
    }

    void PointLight::translate(RayTracer::Vector &vector)
    {
        _position.x += vector._x;
        _position.y += vector._y;
        _position.z += vector._z;
    }

    void PointLight::rotate(RayTracer::Vector &vector)
    {
        _position.x += vector._x;
        _position.y += vector._y;
        _position.z += vector._z;
    }
}
