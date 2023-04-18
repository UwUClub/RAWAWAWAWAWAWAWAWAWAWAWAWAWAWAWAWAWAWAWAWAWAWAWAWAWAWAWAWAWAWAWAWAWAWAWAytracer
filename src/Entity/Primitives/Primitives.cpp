/*
** EPITECH PROJECT, 2023
** RAWAWAWAytracer
** File description:
** Primitives
*/

#include "Primitives.hpp"

namespace RayTracer::Entity {
    Primitives::Primitives(Color color) : Entity(EntityType::PRIMITIVE), _color(color)
    {
    }

    Primitives::~Primitives()
    {
    }

    Color Primitives::getColor()
    {
        return _color;
    }
}
