/*
** EPITECH PROJECT, 2023
** RAWAWAWAytracer
** File description:
** Ray
*/

#include "IEntity.hpp"
#include "Ray.hpp"
#include "HitPoint.hpp"

namespace RayTracer
{
    Ray::Ray(const Point aOrigin, const Vector aDirection)
        : _origin(aOrigin)
        , _direction(aDirection)
    {
    }

    Ray::~Ray()
    {
    }

    std::optional<HitPoint> Ray::getClosestHit(const std::unordered_map<std::string, std::vector<std::unique_ptr<Entity::IEntity>>> &aEntities)
    {
        Color myColor = { 0, 0, 0 };
        double myClosest = 0;
        std::optional<double> myNewDist;

        for (auto &myEntity : aEntities) {
            if (myEntity.first == "Camera" || myEntity.first == "DirectionalLight"
                || myEntity.first == "PointLight") {
                continue;
            }
            for (auto &myPrimitive : myEntity.second) {
                Entity::IEntity *prim = myPrimitive.get();
                myNewDist = prim->isTouched(*this);
                if (myClosest == 0
                    || (myNewDist != std::nullopt && myNewDist.value() < myClosest)) {
                    myClosest = myNewDist.value();
                    myColor = prim->getColor().value();
                }
            }
        }
        if (myClosest == 0)
            return std::nullopt;
        Vector myPoint = this->_direction * myClosest;
        HitPoint myHitPoint = {myPoint._x + this->_origin._x, myPoint._y + this->_origin._y, myPoint._z + this->_origin._z, myColor};
        return myHitPoint;
    }
} // namespace RayTracer
