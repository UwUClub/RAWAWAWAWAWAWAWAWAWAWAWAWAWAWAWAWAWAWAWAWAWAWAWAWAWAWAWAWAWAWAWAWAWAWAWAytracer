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
    struct Point {
        public:
            Point(double aX, double aY, double aZ);
            ~Point() = default;
            Point operator+(const Vector &aOther) const;
            double _x;
            double _y;
            double _z;
    };
} // namespace RayTracer

#endif /* !POINT_HPP_ */
