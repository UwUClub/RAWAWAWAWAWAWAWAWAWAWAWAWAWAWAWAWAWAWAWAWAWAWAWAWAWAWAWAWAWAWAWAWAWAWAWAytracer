/*
** EPITECH PROJECT, 2023
** RAWAWAWAytracer
** File description:
** Cylinder
*/

#include <cmath>
#include "Cylinder.hpp"

namespace RayTracer::Entity {
    Cylinder::Cylinder(const std::unordered_map<std::string, double> &dataMap) : Primitives({0, 0, 0}),
        _center(0, 0, 0)
    {
        _center._x = dataMap.at("x");
        _center._y = dataMap.at("y");
        _center._z = dataMap.at("z");
        _radius = dataMap.at("radius");
        _height = dataMap.at("height");
        setColor({int(dataMap.at("r")), int(dataMap.at("g")), int(dataMap.at("b"))});
    }

    Cylinder::~Cylinder()
    {
    }

    std::optional<double> Cylinder::isTouched(Ray aRay)
    {
        double a = pow(aRay._direction._x, 2) + pow(aRay._direction._y, 2);
        double b = 2 * (aRay._direction._x * (aRay._origin._x - _center._x) + aRay._direction._y * (aRay._origin._y - _center._y));
        double c = pow(aRay._origin._x - _center._x, 2) + pow(aRay._origin._y - _center._y, 2) - pow(_radius, 2);
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
}
