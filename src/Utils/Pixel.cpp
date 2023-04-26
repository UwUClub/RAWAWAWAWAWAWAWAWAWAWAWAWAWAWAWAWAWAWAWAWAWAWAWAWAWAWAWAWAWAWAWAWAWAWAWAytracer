/*
** EPITECH PROJECT, 2023
** RAWAWAWAytracer
** File description:
** Pixel
*/

#include "Pixel.hpp"

namespace RayTracer
{
    Pixel::Pixel(const Point aPosition, const Color aColor)
        : _position(aPosition)
        , _color(aColor)
    {
    }
} // namespace RayTracer
