/*
** EPITECH PROJECT, 2023
** RAWAWAWAytracer
** File description:
** Plane
*/

#include "Plane.hpp"

namespace RayTracer::Entity {
    Plane::Plane(const std::unordered_map<std::string, double> &dataMap) : Primitives({0, 0, 0})
    {
        if (dataMap.at("axis") == 0) {
            _normal = Vector (1, 0, 0);
            _center = Point (dataMap.at("pos"), 0, 0);
        } else if (dataMap.at("axis") == 1) {
            _normal = Vector (0, 1, 0);
            _center = Point (0, dataMap.at("pos"), 0);
        } else if (dataMap.at("axis") == 2) {
            _normal = Vector (0, 0, 1);
            _center = Point (0, 0, dataMap.at("pos"));
        } else
            throw std::invalid_argument("Invalid axis");
        setColor({int(dataMap.at("r")), int(dataMap.at("g")), int(dataMap.at("b"))});
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