/*
** EPITECH PROJECT, 2023
** RAWAWAWAytracer
** File description:
** Point
*/

#include "Point.hpp"

namespace RayTracer
{
    Point Point::operator+(const Vector &other) const
    {
        return { x + other._x, y + other._y, z + other._z };
    }
} // namespace RayTracer
