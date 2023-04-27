/*
** EPITECH PROJECT, 2023
** RAWAWAWAytracer
** File description:
** Plane
*/

#include "Plane.hpp"
#include "IEntity.hpp"

namespace RayTracer::Entity
{
    Plane::Plane(const DataEntityMap &aDataMap)
        : Primitives({ 0, 0, 0 })
    {
        if (aDataMap.at("axis") == 0) {
            _normal = Vector(1, 0, 0);
            _center = Point(aDataMap.at("pos"), 0, 0);
        } else if (aDataMap.at("axis") == 1) {
            _normal = Vector(0, 1, 0);
            _center = Point(0, aDataMap.at("pos"), 0);
        } else if (aDataMap.at("axis") == 2) {
            _normal = Vector(0, 0, 1);
            _center = Point(0, 0, aDataMap.at("pos"));
        } else
            throw std::invalid_argument("Invalid axis");
        setColor({ int(aDataMap.at("r")), int(aDataMap.at("g")), int(aDataMap.at("b")) });
    }

    std::optional<double> Plane::isTouched(const Ray &aRay)
    {
        double myT = 0;
        double myRayDotNormal = aRay._direction | _normal;
        if (myRayDotNormal <= 0.0000001)
            return std::nullopt;

        Vector myRayToCenter = Vector(aRay._origin._x - _center._x, aRay._origin._y - _center._y,
            aRay._origin._z - _center._z);

        myT = (_normal | myRayToCenter) / myRayDotNormal;
        if (myT <= 0)
            return std::nullopt;
        return myT;
    }
} // namespace RayTracer::Entity