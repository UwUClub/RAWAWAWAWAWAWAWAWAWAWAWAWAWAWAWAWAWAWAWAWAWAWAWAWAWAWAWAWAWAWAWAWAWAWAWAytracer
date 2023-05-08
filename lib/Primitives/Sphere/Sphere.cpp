/*
** EPITECH PROJECT, 2023
** RAWAWAWAytracer
** File description:
** Sphere
*/

#include "Sphere.hpp"
#include "IEntity.hpp"
#include <cmath>

namespace RayTracer::Entity
{
    Sphere::Sphere(const DataEntityMap &aDataMap)
        : Primitives({ 0, 0, 0 })
        , _center(0, 0, 0)
    {
        _center._x = aDataMap.at("x");
        _center._y = aDataMap.at("y");
        _center._z = aDataMap.at("z");
        _radius = aDataMap.at("radius");
        setColor({ int(aDataMap.at("r")), int(aDataMap.at("g")), int(aDataMap.at("b")) });
    }

    std::optional<double> Sphere::isTouched(const Ray &aRay)
    {
        double myA
            = pow(aRay._direction._x, 2) + pow(aRay._direction._y, 2) + pow(aRay._direction._z, 2);
        double myB = 2
                     * (aRay._direction._x * (aRay._origin._x - _center._x)
                         + aRay._direction._y * (aRay._origin._y - _center._y)
                         + aRay._direction._z * (aRay._origin._z - _center._z));
        double myC = pow(aRay._origin._x - _center._x, 2) + pow(aRay._origin._y - _center._y, 2)
                     + pow(aRay._origin._z - _center._z, 2) - pow(_radius, 2);
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
        if (myT <= 0)
            return std::nullopt;
        return myT;
    }

    Vector Sphere::getNormal(const Point &aPoint)
    {
        Vector myNormal = Vector(aPoint._x - _center._x, aPoint._y - _center._y,
            aPoint._z - _center._z);
        myNormal._x /= myNormal._dist;
        myNormal._y /= myNormal._dist;
        myNormal._z /= myNormal._dist;
        return myNormal;
    }
} // namespace RayTracer::Entity
