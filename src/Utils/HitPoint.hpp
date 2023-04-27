/*
** EPITECH PROJECT, 2023
** RAWAWAWAytracer
** File description:
** HitPoint
*/

#include "Color.hpp"
#include "IEntity.hpp"
#include "Point.hpp"

#ifndef HITPOINT_HPP_
#define HITPOINT_HPP_

namespace RayTracer
{
    class HitPoint : public Point
    {
        public:
            /**
             * @brief Construct a new Hit Point object
             *
             * @param aX The x position of the hit point
             * @param aY The y position of the hit point
             * @param aZ The z position of the hit point
             * @param aColor The color of the hit point
             */
            HitPoint(double aX, double aY, double aZ, Color &aColor);
            /**
             * @brief Destroy the Hit Point object
             *
             */
            ~HitPoint();
            /**
             * @brief Calculate the color of the hit point
             *
             * @param aEntities The entities to check
             * @return Color The color of the hit point
             */
            Color calcColor(const Entity::IEntityMap &aEntities);

        protected:
        private:
            Color _color;
    };
} // namespace RayTracer

#endif /* !HITPOINT_HPP_ */
