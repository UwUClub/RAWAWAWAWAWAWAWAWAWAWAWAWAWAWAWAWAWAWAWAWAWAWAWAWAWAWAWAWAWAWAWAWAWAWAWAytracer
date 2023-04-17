/*
** EPITECH PROJECT, 2023
** RAWAWAWAytracer
** File description:
** Vector
*/

#include <cmath>
#include "Vector.hpp"

Vector::Vector(double x, double y, double z) : _x(x), _y(y), _z(z)
{
    _dist = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

Vector::~Vector()
{
}

auto Vector::operator<=>(const Vector &other) const
{
    return (_x == other._x && _y == other._y && _z == other._z);
}

Vector Vector::operator+(const Vector &other) const
{
    return Vector(_x + other._x, _y + other._y, _z + other._z);
}

Vector Vector::operator-(const Vector &other) const
{
    return Vector(_x - other._x, _y - other._y, _z - other._z);
}

double Vector::operator|(const Vector &other) const
{
    return (_x * other._x + _y * other._y + _z * other._z);
}

Vector Vector::operator*(const Vector &other) const
{
    return Vector(_y * other._z - _z * other._y, _z * other._x - _x * other._z, _x * other._y - _y * other._x);
}

Vector Vector::operator*(const double other) const
{
    return Vector(_x * other, _y * other, _z * other);
}

Vector Vector::operator/(const double other) const
{
    return Vector(_x / other, _y / other, _z / other);
}

