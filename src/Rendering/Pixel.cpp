/*
** EPITECH PROJECT, 2023
** RAWAWAWAytracer
** File description:
** Pixel
*/

#include "Pixel.hpp"

namespace RayTracer::Renderer
{
    Pixel::Pixel(Point aPosition, Entity::Color aColor)
        : _position(aPosition)
        , _color(aColor)
    {
    }
} // namespace RayTracer
