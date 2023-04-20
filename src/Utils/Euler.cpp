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
    Euler::Euler(double x, double y, double z)
        : _x(x)
        , _y(y)
        , _z(z)
    {
        _dist = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
    }

    Euler Euler::rad() const
    {
        return { _x * M_PI / 180, _y * M_PI / 180, _z * M_PI / 180 };
    }

    auto Euler::operator<=>(const Euler &other) const
    {
        return (_x == other._x && _y == other._y && _z == other._z);
    }

    Euler Euler::operator+(const Euler &other) const
    {
        return { _x + other._x, _y + other._y, _z + other._z };
    }

    Euler Euler::operator-(const Euler &other) const
    {
        return { _x - other._x, _y - other._y, _z - other._z };
    }

    double Euler::operator|(const Euler &other) const
    {
        return (_x * other._x + _y * other._y + _z * other._z);
    }

    Euler Euler::operator*(const Euler &other) const
    {
        return { _y * other._z - _z * other._y, _z * other._x - _x * other._z,
            _x * other._y - _y * other._x };
    }

    Euler Euler::operator*(const double other) const
    {
        return { _x * other, _y * other, _z * other };
    }

    Euler Euler::operator/(const double other) const
    {
        return { _x / other, _y / other, _z / other };
    }
} // namespace RayTracer
