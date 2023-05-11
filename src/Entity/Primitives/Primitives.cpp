/*
** EPITECH PROJECT, 2023
** RAWAWAWAytracer
** File description:
** Primitives
*/

#include "Primitives.hpp"

namespace RayTracer::Entity
{
    Primitives::Primitives(const Color &color)
        : Entity(EntityType::PRIMITIVE)
        , _color(color)
    {
    }

    std::optional<Color> Primitives::getColor()
    {
        return _color;
    }

    void Primitives::setColor(const Color &color)
    {
        _color = color;
    }
} // namespace RayTracer::Entity
