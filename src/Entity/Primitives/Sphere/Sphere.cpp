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

    std::optional<double> Sphere::isTouched(Ray ray)
    {
        double a = pow(ray._direction._x, 2) + pow(ray._direction._y, 2) + pow(ray._direction._z, 2);
        double b = 2 * (ray._direction._x * (ray._origin.x - _center.x) + ray._direction._y * (ray._origin.y - _center.y) + ray._direction._z * (ray._origin.z - _center.z));
        double c = pow(ray._origin.x - _center.x, 2) + pow(ray._origin.y - _center.y, 2) + pow(ray._origin.z - _center.z, 2) - pow(_radius, 2);
        double delta = pow(b, 2) - 4 * a * c;
        double t = 0;

        if (delta < 0)
            return std::nullopt;
        else if (delta == 0)
            t = (-b / (2 * a));
        else {
            t = (-b + sqrt(delta)) / (2 * a);
            if (t > (-b - sqrt(delta)) / (2 * a)) {
                t = (-b - sqrt(delta) / (2 * a));
            }
        }
        if (t < 0)
            return std::nullopt;
        return t;
    }
} // namespace RayTracer
