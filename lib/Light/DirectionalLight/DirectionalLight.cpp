/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** DirectionalLight.cpp
*/

#include "DirectionalLight.hpp"

namespace RayTracer::Entity {
    DirectionalLight::DirectionalLight() : Entity(EntityType::LIGHT), _direction(0, 0, 0) {}

    void DirectionalLight::setDirection(const Vector &direction)
    {
        _direction = direction;
    }
}
