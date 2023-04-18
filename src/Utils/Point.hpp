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
            Point(double x, double y, double z)
                : x(x)
                , y(y)
                , z(z) {};
            ~Point() = default;
            Point operator+(const Vector &other) const;
            double x;
            double y;
            double z;
    };
} // namespace RayTracer

#endif /* !POINT_HPP_ */
