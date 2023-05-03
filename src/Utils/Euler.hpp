/*
** EPITECH PROJECT, 2023
** RAWAWAWAytracer
** File description:
** Euler
*/

#ifndef Euler_HPP_
#define Euler_HPP_

#include <iostream>

namespace RayTracer
{
    struct Euler {
        public:
            /**
             * @brief Construct a new Euler object
             *
             * @param x The x value of the euler
             * @param y The y value of the euler
             * @param z The z value of the euler
             */
            Euler(double aX, double aY, double aZ);
            ~Euler() = default;

            /**
             * @brief Get the radian value of the euler
             *
             * @return Euler The radian value of the euler
             */
            [[nodiscard]] Euler rad() const;

            auto operator<=>(const Euler &aOther) const;
            Euler operator+(const Euler &aOther) const;
            Euler operator-(const Euler &aOther) const;
            double operator|(const Euler &aOther) const;
            Euler operator*(double aOther) const;
            Euler operator*(const Euler &aOther) const;
            Euler operator/(double aOther) const;
            double _x;
            double _y;
            double _z;
            double _dist;
    };
} // namespace RayTracer

#endif /* !EULER_HPP_ */
