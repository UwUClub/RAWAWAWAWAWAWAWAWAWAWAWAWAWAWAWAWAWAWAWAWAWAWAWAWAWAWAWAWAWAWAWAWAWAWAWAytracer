/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** PointLight.cpp
*/

#include "PointLight.hpp"

namespace RayTracer::Entity {
    PointLight::PointLight(const std::unordered_map<std::string, double> &dataMap) : Entity(EntityType::LIGHT), _position(0, 0, 0)
    {
        if (dataMap.find("x") != dataMap.end())
            _position._x = dataMap.at("x");
        if (dataMap.find("y") != dataMap.end())
            _position._y = dataMap.at("y");
        if (dataMap.find("z") != dataMap.end())
            _position._z = dataMap.at("z");
    }
}
