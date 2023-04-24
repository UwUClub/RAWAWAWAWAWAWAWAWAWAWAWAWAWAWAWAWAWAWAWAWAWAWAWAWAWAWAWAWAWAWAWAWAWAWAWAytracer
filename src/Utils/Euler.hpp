/*
** EPITECH PROJECT, 2023
** RAWAWAWAytracer
** File description:
** Euler
*/

#include <iostream>

#ifndef Euler_HPP_
#define Euler_HPP_

namespace RayTracer
{
    struct Euler {
        public:
            Euler(double x, double y, double z);
            ~Euler() = default;

            [[nodiscard]] Euler rad() const;

            auto operator<=>(const Euler &other) const;
            Euler operator+(const Euler &other) const;
            Euler operator-(const Euler &other) const;
            double operator|(const Euler &other) const;
            Euler operator*(double other) const;
            Euler operator*(const Euler &other) const;
            Euler operator/(double other) const;
            double _x;
            double _y;
            double _z;
            double _dist;
    };
} // namespace RayTracer

#endif /* !EULER_HPP_ */
