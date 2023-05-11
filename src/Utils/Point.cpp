/*
** EPITECH PROJECT, 2023
** RAWAWAWAytracer
** File description:
** Point
*/

#include "Point.hpp"
#include <cmath>

namespace RayTracer
{
    Point::Point(double aX, double aY, double aZ)
        : _x(aX)
        , _y(aY)
        , _z(aZ)
    {
    }

    void Point::rotate(Point aOrigin, Euler aAngles)
    {
        this->rotate(aOrigin, Vector(1, 0, 0), aAngles._x);
        this->rotate(aOrigin, Vector(0, 1, 0), aAngles._y);
        this->rotate(aOrigin, Vector(0, 0, 1), aAngles._z);
    }

    void Point::rotate(Point aOrigin, Vector aRotation, double aAngle)
    {
        const double myAngleCos = cos(aAngle);
        const double myAngleSin = sin(aAngle);
        const double myPrevX = _x;
        const double myPrevY = _y;
        const double myPrevZ = _z;

        _x -= aOrigin._x;
        _y -= aOrigin._y;
        _z -= aOrigin._z;
        _x = (myAngleCos + (1 - myAngleCos) * pow(aRotation._x, 2)) * myPrevX + ((1 - myAngleCos) * aRotation._x * aRotation._y - myAngleSin * aRotation._z) * myPrevY + ((1 - myAngleCos) * aRotation._x * aRotation._z + myAngleSin * aRotation._y) * myPrevZ;
        _y = ((1 - myAngleCos) * aRotation._x * aRotation._y + myAngleSin * aRotation._z) * myPrevX + (myAngleCos + (1 - myAngleCos) * pow(aRotation._y, 2)) * myPrevY + ((1 - myAngleCos) * aRotation._y * aRotation._z - myAngleSin * aRotation._x) * myPrevZ;
        _z = ((1 - myAngleCos) * aRotation._x * aRotation._z - myAngleSin * aRotation._y) * myPrevX + ((1 - myAngleCos) * aRotation._y * aRotation._z + myAngleSin * aRotation._x) * myPrevY + (myAngleCos + (1 - myAngleCos) * pow(aRotation._z, 2)) * myPrevZ;
        _x += aOrigin._x;
        _y += aOrigin._y;
        _z += aOrigin._z;
    }

    Point Point::operator+(const Vector &aOther) const
    {
        return { _x + aOther._x, _y + aOther._y, _z + aOther._z };
    }
} // namespace RayTracer
