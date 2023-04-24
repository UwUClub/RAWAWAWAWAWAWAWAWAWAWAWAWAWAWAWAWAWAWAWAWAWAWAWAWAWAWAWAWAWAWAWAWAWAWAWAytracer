/*
** EPITECH PROJECT, 2023
** RAWAWAWAytracer
** File description:
** Ray
*/

#include "Ray.hpp"
#include "../Entity/Primitives/Primitives.hpp"

namespace RayTracer {
    Ray::Ray(Point origin, Vector direction) : _origin(origin), _direction(direction)
    {
    }

    Ray::~Ray()
    {
    }

    Entity::Color Ray::getClosestHit(Entity::IEntityMap entities)
    {
        Entity::Color color = {0, 0, 0, 255};
        double closest = 0;
        std::optional<double> newDist;
    
        for (auto &entity : entities["Primitives"]) {
            Entity::Primitives *prim = static_cast<Entity::Primitives *>(entity.get());
            newDist = prim->isTouched(*this);
            if (closest == 0 || (newDist != std::nullopt && newDist.value() < closest)) {
                closest = newDist.value();
                color = prim->getColor();
            }
        }
        return color;
    }
} // namespace RayTracer