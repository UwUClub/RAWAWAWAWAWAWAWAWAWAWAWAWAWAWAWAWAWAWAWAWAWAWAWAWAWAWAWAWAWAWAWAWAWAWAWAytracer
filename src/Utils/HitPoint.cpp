/*
** EPITECH PROJECT, 2023
** RAWAWAWAytracer
** File description:
** HitPoint
*/

#include "HitPoint.hpp"

namespace RayTracer {
    HitPoint::HitPoint(double aX, double aY, double aZ, Entity::Color &aColor)
        : Point(aX, aY, aZ)
        , _color(aColor)
    {
    }

    HitPoint::~HitPoint()
    {
    }

    Entity::Color calcColor(Entity::IEntityMap aEntities)
    {
    }
}