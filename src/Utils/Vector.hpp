/*
** EPITECH PROJECT, 2023
** RAWAWAWAytracer
** File description:
** Vector
*/

#include <iostream>

#ifndef VECTOR_HPP_
#define VECTOR_HPP_

namespace RayTracer
{
    struct Vector {
        public:
            Vector(double x, double y, double z);
            ~Vector() = default;
            
            auto operator<=>(const Vector &other) const;
            Vector operator+(const Vector &other) const;
            Vector operator-(const Vector &other) const;
            double operator|(const Vector &other) const;
            Vector operator*(const double other) const;
            Vector operator*(const Vector &other) const;
            Vector operator/(const double other) const;
            double _x;
            double _y;
            double _z;
            double _dist;
    };
} // namespace RayTracer

#endif /* !VECTOR_HPP_ */
