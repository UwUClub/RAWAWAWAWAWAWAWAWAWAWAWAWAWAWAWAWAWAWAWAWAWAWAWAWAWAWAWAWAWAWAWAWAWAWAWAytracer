/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** DirectionalLight.cpp
*/

#include "DirectionalLight.hpp"
#include "IEntity.hpp"

namespace RayTracer::Entity
{
    DirectionalLight::DirectionalLight(const DataEntityMap &aDataMap)
        : Entity(EntityType::LIGHT)
        , _direction(0, 0, 0)
    {
        if (aDataMap.find("x") != aDataMap.end())
            _direction._x = aDataMap.at("x");
        if (aDataMap.find("y") != aDataMap.end())
            _direction._y = aDataMap.at("y");
        if (aDataMap.find("z") != aDataMap.end())
            _direction._z = aDataMap.at("z");
    }

    void DirectionalLight::setDirection(const Vector &aDirection)
    {
        _direction = aDirection;
    }
} // namespace RayTracer::Entity
