/*
** EPITECH PROJECT, 2023
** RAWAWAWAytracer
** File description:
** Cone
*/

#include <cmath>
#include "Cone.hpp"

namespace RayTracer::Entity {
    Cone::Cone(const std::unordered_map<std::string, double> &dataMap) : Primitives({0, 0, 0}),
        _center(0, 0, 0)
    {
        _center._x = dataMap.at("x");
        _center._y = dataMap.at("y");
        _center._z = dataMap.at("z");
        _radius = dataMap.at("radius");
        _height = dataMap.at("height");
        setColor({dataMap.at("r"), dataMap.at("g"), dataMap.at("b")});
    }

    Cone::~Cone()
    {
    }

    std::optional<double> Cone::isTouched(Ray ray)
    {
        double slant = sqrt(pow(_radius, 2) / pow(_height,2));
        double alpha = (2 * asin (_radius / slant)) * M_PI / 180;
        double a = pow(ray._direction._x, 2) + pow(ray._direction._y, 2) - pow(ray._direction._z, 2) * pow(tan(alpha), 2);
        double b = 2 * (ray._direction._x * (ray._origin._x - _center._x) + ray._direction._y * (ray._origin._y - _center._y) - ray._direction._z * (ray._origin._z - _center._z) * pow(tan(alpha), 2));
        double c = pow(ray._origin._x - _center._x, 2) + pow(ray._origin._y - _center._y, 2) - pow(ray._origin._z - _center._z, 2) * pow(tan(alpha), 2);
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
        return t;
    }
}
