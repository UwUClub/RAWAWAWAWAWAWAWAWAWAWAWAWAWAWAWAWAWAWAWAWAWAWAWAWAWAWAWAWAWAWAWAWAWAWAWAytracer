/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** PointLight.cpp
*/

#include "PointLight.hpp"

namespace RayTracer::Entity {
    PointLight::PointLight() : Entity(EntityType::LIGHT), _position(0, 0, 0)
    {
    }

}
