/*
** EPITECH PROJECT, 2023
** RAWAWAWAytracer
** File description:
** HitPoint
*/

#include "Ray.hpp"
#include "HitPoint.hpp"
#include "PointLight.hpp"
namespace RayTracer
{
    HitPoint::HitPoint(double aX, double aY, double aZ, Color &aColor)
        : Point(aX, aY, aZ)
        , _color(aColor)
    {
    }

    HitPoint::~HitPoint()
    {
    }

    Color HitPoint::calcColor(const Entity::IEntityMap &aEntities)
    {
        Ray myRay = Ray({_x, _y, _z}, {0, 0, 0});
        for (auto &myEntity : aEntities) {
            if (myEntity.first == "PointLight") {
                for (auto &myLights : myEntity.second) {
                    Entity::PointLight *myLight = static_cast<Entity::PointLight *>(myLights.get());
                    myRay._direction._x = myLight->getPosition()._x - _x;
                    myRay._direction._y = myLight->getPosition()._y - _y;
                    myRay._direction._z = myLight->getPosition()._z - _z;
                    std::optional<HitPoint> myHitPoint = myRay.getClosestHit(aEntities);
                    if (myHitPoint == std::nullopt) {
                        return _color;
                    } else {
                        return {0, 0, 0};
                    }
                }
            }
        }
    }
} // namespace RayTracer
