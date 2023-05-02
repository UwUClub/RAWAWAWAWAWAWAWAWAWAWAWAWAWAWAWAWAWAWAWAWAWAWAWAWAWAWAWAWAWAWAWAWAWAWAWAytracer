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

    void Vector::rotate(Euler aEuler)
    {
        this->rotate(Vector(1, 0, 0), aEuler._x);
        this->rotate(Vector(0, 1, 0), aEuler._y);
        this->rotate(Vector(0, 0, 1), aEuler._z);
    }

    void Vector::rotate(Vector aRotation, double aAngle)
    {
        double myAngleCos = cos(aAngle);
        double myAngleSin = sin(aAngle);
        double myPrevX = _x;
        double myPrevY = _y;
        double myPrevZ = _z;

        _x = (myAngleCos + (1 - myAngleCos) * pow(aRotation._x, 2)) * myPrevX + ((1 - myAngleCos) * aRotation._x * aRotation._y - myAngleSin * aRotation._z) * myPrevY + ((1 - myAngleCos) * aRotation._x * aRotation._z + myAngleSin * aRotation._y) * myPrevZ;
        _y = ((1 - myAngleCos) * aRotation._x * aRotation._y + myAngleSin * aRotation._z) * myPrevX + (myAngleCos + (1 - myAngleCos) * pow(aRotation._y, 2)) * myPrevY + ((1 - myAngleCos) * aRotation._y * aRotation._z - myAngleSin * aRotation._x) * myPrevZ;
        _z = ((1 - myAngleCos) * aRotation._x * aRotation._z - myAngleSin * aRotation._y) * myPrevX + ((1 - myAngleCos) * aRotation._y * aRotation._z + myAngleSin * aRotation._x) * myPrevY + (myAngleCos + (1 - myAngleCos) * pow(aRotation._z, 2)) * myPrevZ;
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
