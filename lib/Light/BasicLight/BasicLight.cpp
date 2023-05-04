/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** PointLight.cpp
*/

#include "BasicLight.hpp"
#include "IEntity.hpp"

namespace RayTracer::Entity
{
    BasicLight::BasicLight(const DataEntityMap &aDataMap)
        : Entity(EntityType::LIGHT)
    {
        if (aDataMap.find("ambient") == aDataMap.end() ||
            aDataMap.find("diffuse") == aDataMap.end())
            throw std::runtime_error("Missing parameter for BasicLight");
        _ambient = aDataMap.at("ambient");
        _diffuse = aDataMap.at("diffuse");
    }
} // namespace RayTracer::Entity
