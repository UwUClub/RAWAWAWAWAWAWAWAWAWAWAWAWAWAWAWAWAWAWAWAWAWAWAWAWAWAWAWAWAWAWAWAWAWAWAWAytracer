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

    Point Point::rotate(Point aOrigin, Vector aRotation, double aAngle)
    {
        double myAngleCos = cos(aAngle);
        double myAngleSin = sin(aAngle);
        double myPrevX = _x;
        double myPrevY = _y;
        double myPrevZ = _z;

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
