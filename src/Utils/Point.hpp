/*
** EPITECH PROJECT, 2023
** RAWAWAWAytracer
** File description:
** Point
*/

#ifndef POINT_HPP_
#define POINT_HPP_

#include "Vector.hpp"

namespace RayTracer
{
    /**
     * @brief The Point class
     */
    struct Point {
        public:
            Point() = default;
            /**
             * @brief Construct a new Point object
             * @param aX The x value
             * @param aY The y value
             * @param aZ The z value
             */
            Point(double aX, double aY, double aZ);
            /**
             * @brief Destroy the Point object
             */
            ~Point() = default;
            /**
             * @brief Rotate the Point around an origin
             * @param aOrigin The origin point
             */
            Point rotate(Point aOrigin, Vector aRotation, double aAngle);
            Point operator+(const Vector &aOther) const;
            /**
             * @brief The x value of the point
             */
            double _x;
            /**
             * @brief The y value of the point
             */
            double _y;
            /**
             * @brief The z value of the point
             */
            double _z;
    };
} // namespace RayTracer

#endif /* !POINT_HPP_ */
