/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** PointLight.cpp
*/

#include "PointLight.hpp"
#include "IEntity.hpp"

namespace RayTracer::Entity
{
    PointLight::PointLight(const DataEntityMap &aDataMap)
        : Entity(EntityType::LIGHT)
        , _position(0, 0, 0)
    {
        if (aDataMap.find("x") != aDataMap.end())
            _position._x = aDataMap.at("x");
        if (aDataMap.find("y") != aDataMap.end())
            _position._y = aDataMap.at("y");
        if (aDataMap.find("z") != aDataMap.end())
            _position._z = aDataMap.at("z");
    }
} // namespace RayTracer::Entity
