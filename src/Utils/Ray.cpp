/*
** EPITECH PROJECT, 2023
** RAWAWAWAytracer
** File description:
** Ray
*/

#include "Ray.hpp"
#include "Primitives.hpp"

namespace RayTracer {
    Ray::Ray(Point origin, Vector direction) : _origin(origin), _direction(direction)
    {
    }

    Ray::~Ray()
    {
    }

    Color Ray::getClosestHit(Entity::IEntityMap entities)
    {
        Color color = {0, 0, 0};
        double closest = 0;
        std::optional<double> newDist;
    
        for (auto &entity : entities) {
            if (entity.first == "Sphere" || entity.first == "Plane" || entity.first == "Cylinder" || entity.first == "Cone") {
                for (auto &entity2 : entity.second) {
                    Entity::Primitives *prim = static_cast<Entity::Primitives *>(entity2.get());
                    newDist = prim->isTouched(*this);
                    if (closest == 0 || (newDist != std::nullopt && newDist.value() < closest)) {
                        closest = newDist.value();
                        color = prim->getColor();
                    }
                }
            }
        }
        return color;
    }
} // namespace RayTracer