/*
** EPITECH PROJECT, 2023
** RAWAWAWAytracer
** File description:
** Cone
*/

#include "Cone.hpp"
#include "IEntity.hpp"
#include <cmath>

namespace RayTracer::Entity
{
    Cone::Cone(const DataEntityMap &aDataMap)
        : Primitives({ 0, 0, 0 })
        , _center(0, 0, 0)
    {
        _center._x = aDataMap.at("x");
        _center._y = aDataMap.at("y");
        _center._z = aDataMap.at("z");
        _radius = aDataMap.at("radius");
        _height = aDataMap.at("height");
        setColor({ int(aDataMap.at("r")), int(aDataMap.at("g")), int(aDataMap.at("b")) });
    }

    std::optional<double> Cone::isTouched(const Ray &ray)
    {
        double mySlant = sqrt(pow(_radius, 2) / pow(_height, 2));
        double myAlpha = (2 * asin(_radius / mySlant)) * M_PI / 180;
        double myA = pow(ray._direction._x, 2) + pow(ray._direction._y, 2)
                     - pow(ray._direction._z, 2) * pow(tan(myAlpha), 2);
        double myB
            = 2
              * (ray._direction._x * (ray._origin._x - _center._x)
                  + ray._direction._y * (ray._origin._y - _center._y)
                  - ray._direction._z * (ray._origin._z - _center._z) * pow(tan(myAlpha), 2));
        double myC = pow(ray._origin._x - _center._x, 2) + pow(ray._origin._y - _center._y, 2)
                     - pow(ray._origin._z - _center._z, 2) * pow(tan(myAlpha), 2);
        double myDelta = pow(myB, 2) - 4 * myA * myC;
        double myT = 0;

        if (myDelta < 0)
            return std::nullopt;
        else if (myDelta == 0)
            myT = (-myB / (2 * myA));
        else {
            myT = (-myB + sqrt(myDelta)) / (2 * myA);
            if (myT > (-myB - sqrt(myDelta)) / (2 * myA)) {
                myT = (-myB - sqrt(myDelta) / (2 * myA));
            }
        }
        return myT;
    }
} // namespace RayTracer::Entity
