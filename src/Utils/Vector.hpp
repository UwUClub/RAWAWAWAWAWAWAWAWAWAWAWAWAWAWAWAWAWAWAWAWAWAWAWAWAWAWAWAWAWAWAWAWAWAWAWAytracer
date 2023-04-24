/*
** EPITECH PROJECT, 2023
** RAWAWAWAytracer
** File description:
** Vector
*/

#ifndef VECTOR_HPP_
#define VECTOR_HPP_

namespace RayTracer
{
    struct Vector {
        public:
            Vector() = default;
            Vector(double aX, double aY, double aZ);
            ~Vector() = default;

            auto operator<=>(const Vector &aOther) const;
            Vector operator+(const Vector &aOther) const;
            Vector operator-(const Vector &aOther) const;
            double operator|(const Vector &aOther) const;
            Vector operator*(double aOther) const;
            Vector operator*(const Vector &aOther) const;
            Vector operator/(double aOther) const;
            double _x;
            double _y;
            double _z;
            double _dist;
    };
} // namespace RayTracer

#endif /* !VECTOR_HPP_ */
