/*
** EPITECH PROJECT, 2023
** RAWAWAWAytracer
** File description:
** Vector
*/

#include "Vector.hpp"
#include <cmath>

namespace RayTracer
{
    Vector::Vector(double aX, double aY, double aZ)
        : _x(aX)
        , _y(aY)
        , _z(aZ)
        , _dist((sqrt(pow(aX, 2) + pow(aY, 2) + pow(aZ, 2))))
    {
    }

    auto Vector::operator<=>(const Vector &aOther) const
    {
        return (_x == aOther._x && _y == aOther._y && _z == aOther._z);
    }

    Vector Vector::operator+(const Vector &aOther) const
    {
        return { _x + aOther._x, _y + aOther._y, _z + aOther._z };
    }

    Vector Vector::operator-(const Vector &aOther) const
    {
        return { _x - aOther._x, _y - aOther._y, _z - aOther._z };
    }

    double Vector::operator|(const Vector &aOther) const
    {
        return (_x * aOther._x + _y * aOther._y + _z * aOther._z);
    }

    Vector Vector::operator*(const Vector &aOther) const
    {
        return { _y * aOther._z - _z * aOther._y, _z * aOther._x - _x * aOther._z,
            _x * aOther._y - _y * aOther._x };
    }

    Vector Vector::operator*(const double aOther) const
    {
        return { _x * aOther, _y * aOther, _z * aOther };
    }

    Vector Vector::operator/(const double aOther) const
    {
        return { _x / aOther, _y / aOther, _z / aOther };
    }
} // namespace RayTracer
