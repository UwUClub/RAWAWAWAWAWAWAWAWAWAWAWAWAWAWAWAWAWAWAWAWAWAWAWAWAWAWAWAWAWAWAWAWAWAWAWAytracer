/*
** EPITECH PROJECT, 2023
** RAWAWAWAytracer
** File description:
** HitPoint
*/

#include "Point.hpp"
#include "Color.hpp"
#include "IEntity.hpp"

#ifndef HITPOINT_HPP_
#define HITPOINT_HPP_

namespace RayTracer {
    class HitPoint : public Point {
        public:
            HitPoint(double aX, double aY, double aZ, Color &aColor);
            ~HitPoint();
            Color calcColor(Entity::IEntityMap aEntities);
        protected:
        private:
            Color _color;
    };
} // namespace RayTracer


#endif /* !HITPOINT_HPP_ */
