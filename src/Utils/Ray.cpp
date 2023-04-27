/*
** EPITECH PROJECT, 2023
** RAWAWAWAytracer
** File description:
** Ray
*/

#include "Ray.hpp"
#include "Primitives.hpp"

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

    Color Ray::getClosestHit(const Entity::IEntityMap &aEntities)
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
                Entity::Primitives *prim = static_cast<Entity::Primitives *>(myPrimitive.get());
                myNewDist = prim->isTouched(*this);
                if (myClosest == 0
                    || (myNewDist != std::nullopt && myNewDist.value() < myClosest)) {
                    myClosest = myNewDist.value();
                    myColor = prim->getColor();
                }
            }
        }
        return myColor;
    }
} // namespace RayTracer
