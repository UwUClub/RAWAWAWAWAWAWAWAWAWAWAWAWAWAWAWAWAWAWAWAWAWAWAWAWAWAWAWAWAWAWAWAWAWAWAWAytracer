/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** DirectionalLight.cpp
*/

#include "DirectionalLight.hpp"

namespace RayTracer::Entity {
    DirectionalLight::DirectionalLight(const std::unordered_map<std::string, double> &dataMap) : Entity(EntityType::LIGHT), _direction(0, 0, 0)
    {
        if (dataMap.find("x") != dataMap.end())
            _direction._x = dataMap.at("x");
        if (dataMap.find("y") != dataMap.end())
            _direction._y = dataMap.at("y");
        if (dataMap.find("z") != dataMap.end())
            _direction._z = dataMap.at("z");
    }

    void DirectionalLight::setDirection(const Vector &aDirection)
    {
        _direction = aDirection;
    }
}
