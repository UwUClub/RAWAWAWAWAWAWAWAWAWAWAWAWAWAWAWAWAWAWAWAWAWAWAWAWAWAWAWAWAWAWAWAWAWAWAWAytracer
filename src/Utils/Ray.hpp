/*
** EPITECH PROJECT, 2023
** RAWAWAWAytracer
** File description:
** Ray
*/

#include "IEntity.hpp"
#include "Point.hpp"
#include "Vector.hpp"
#include "Color.hpp"

#ifndef RAY_HPP_
#define RAY_HPP_

namespace RayTracer {
    struct Ray {
        public:
            Ray(Point origin, Vector direction);
            ~Ray();
            Point _origin;
            Vector _direction;
            Color getClosestHit(Entity::IEntityMap entities);
    };
} // namespace RayTracer

#endif /* !RAY_HPP_ */
