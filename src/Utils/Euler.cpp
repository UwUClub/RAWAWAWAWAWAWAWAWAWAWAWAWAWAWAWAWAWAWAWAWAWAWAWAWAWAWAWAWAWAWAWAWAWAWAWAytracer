/*
** EPITECH PROJECT, 2023
** RAWAWAWAytracer
** File description:
** Euler
*/

#include "Euler.hpp"
#include <cmath>

namespace RayTracer
{
    Euler::Euler(double aX, double aY, double aZ)
        : _x(aX)
        , _y(aY)
        , _z(aZ)
    {
        _dist = sqrt(pow(aX, 2) + pow(aY, 2) + pow(aZ, 2));
    }

    Euler Euler::rad() const
    {
        return { _x * M_PI / 180, _y * M_PI / 180, _z * M_PI / 180 };
    }

    auto Euler::operator<=>(const Euler &aOther) const
    {
        return (_x == aOther._x && _y == aOther._y && _z == aOther._z);
    }

    Euler Euler::operator+(const Euler &aOther) const
    {
        return { _x + aOther._x, _y + aOther._y, _z + aOther._z };
    }

    Euler Euler::operator-(const Euler &aOther) const
    {
        return { _x - aOther._x, _y - aOther._y, _z - aOther._z };
    }

    double Euler::operator|(const Euler &aOther) const
    {
        return (_x * aOther._x + _y * aOther._y + _z * aOther._z);
    }

    Euler Euler::operator*(const Euler &aOther) const
    {
        return { _y * aOther._z - _z * aOther._y, _z * aOther._x - _x * aOther._z,
            _x * aOther._y - _y * aOther._x };
    }

    Euler Euler::operator*(double aOther) const
    {
        return { _x * aOther, _y * aOther, _z * aOther };
    }

    Euler Euler::operator/(double aOther) const
    {
        return { _x / aOther, _y / aOther, _z / aOther };
    }
} // namespace RayTracer
