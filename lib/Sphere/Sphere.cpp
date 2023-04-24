/*
** EPITECH PROJECT, 2023
** RAWAWAWAytracer
** File description:
** Sphere
*/

#include <cmath>
#include "Sphere.hpp"

namespace RayTracer::Entity {
    Sphere::Sphere(Point center, double radius, Color color) : Primitives(color),
        _center(center), _radius(radius)
    {
    }

    Sphere::~Sphere()
    {
    }

    std::optional<double> Sphere::isTouched(Ray aRay)
    {
        double a = pow(aRay._direction._x, 2) + pow(aRay._direction._y, 2) + pow(aRay._direction._z, 2);
        double b = 2 * (aRay._direction._x * (aRay._origin._x - _center._x) + aRay._direction._y * (aRay._origin._y - _center._y) + aRay._direction._z * (aRay._origin._z - _center._z));
        double c = pow(aRay._origin._x - _center._x, 2) + pow(aRay._origin._y - _center._y, 2) + pow(aRay._origin._z - _center._z, 2) - pow(_radius, 2);
        double myDelta = pow(b, 2) - 4 * a * c;
        double t = 0;

        if (myDelta < 0)
            return std::nullopt;
        else if (myDelta == 0)
            t = (-b / (2 * a));
        else {
            t = (-b + sqrt(myDelta)) / (2 * a);
            if (t > (-b - sqrt(myDelta)) / (2 * a)) {
                t = (-b - sqrt(myDelta) / (2 * a));
            }
        }
        if (t <= 0)
            return std::nullopt;
        return t;
    }
} // namespace aRayTracer
