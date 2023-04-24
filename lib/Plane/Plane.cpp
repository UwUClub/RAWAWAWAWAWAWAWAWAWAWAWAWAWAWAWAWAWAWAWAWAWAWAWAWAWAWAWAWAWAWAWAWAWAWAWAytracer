/*
** EPITECH PROJECT, 2023
** RAWAWAWAytracer
** File description:
** Plane
*/

#include "Plane.hpp"

namespace RayTracer::Entity {
    Plane::Plane(double pos, std::string axis, Color color) : Primitives(color)
    {
        if (axis == "x") {
            _normal = Vector (1, 0, 0);
            _center = Point (pos, 0, 0);
        } else if (axis == "y") {
            _normal = Vector (0, 1, 0);
            _center = Point (0, pos, 0);
        } else if (axis == "z") {
            _normal = Vector (0, 0, 1);
            _center = Point (0, 0, pos);
        } else
            throw std::invalid_argument("Invalid axis");
    }

    Plane::~Plane()
    {
    }
    
    std::optional<double> Plane::isTouched(Ray ray)
    {
        double t = 0;
        double rayDotNormal = ray._direction|_normal;
        if (rayDotNormal <= 0.0000001)
            return std::nullopt;
        Vector rayToCenter = Vector (ray._origin._x - _center._x, ray._origin._y - _center._y, ray._origin._z - _center._z);
        t = (_normal|rayToCenter) /rayDotNormal;
        if (t <= 0)
            return std::nullopt;
        return t;
    }
}