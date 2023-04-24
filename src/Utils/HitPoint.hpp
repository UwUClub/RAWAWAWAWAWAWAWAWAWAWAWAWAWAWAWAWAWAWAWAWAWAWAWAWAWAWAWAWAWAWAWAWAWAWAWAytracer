/*
** EPITECH PROJECT, 2023
** RAWAWAWAytracer
** File description:
** HitPoint
*/

#include "Point.hpp"
#include "../../lib/Color/Color.hpp"

#ifndef HITPOINT_HPP_
#define HITPOINT_HPP_

namespace RayTracer {
    class HitPoint : public Point {
        public:
            HitPoint(double aX, double aY, double aZ, Entity::Color &aColor);
            ~HitPoint();
            Entity::Color calcColor(Entity::IEntityMap aEntities);
        protected:
        private:
            Entity::Color _color;
    };
} // namespace RayTracer


#endif /* !HITPOINT_HPP_ */
