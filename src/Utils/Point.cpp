/*
** EPITECH PROJECT, 2023
** RAWAWAWAytracer
** File description:
** Point
*/

#include "Point.hpp"

namespace RayTracer
{
    Point::Point(double aX, double aY, double aZ)
        : _x(aX)
        , _y(aY)
        , _z(aZ)
    {
    }

    Point Point::operator+(const Vector &aOther) const
    {
        return { _x + aOther._x, _y + aOther._y, _z + aOther._z };
    }
} // namespace RayTracer
