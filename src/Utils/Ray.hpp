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
            Entity::Color getClosestHit(Entity::IEntityVector entities);
    };
} // namespace RayTracer

#endif /* !RAY_HPP_ */
