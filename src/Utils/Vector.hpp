/*
** EPITECH PROJECT, 2023
** RAWAWAWAytracer
** File description:
** Vector
*/

#ifndef VECTOR_HPP_
#define VECTOR_HPP_

#include "Euler.hpp"

namespace RayTracer
{
    /**
     * @brief The Vector class
     */
    struct Vector {
        public:
            Vector() = default;
            /**
             * @brief Construct a new Vector object
             * @param aX The x value
             * @param aY The y value
             * @param aZ The z value
             */
            Vector(double aX, double aY, double aZ);
            /**
             * @brief Destroy the Vector object
             */
            ~Vector() = default;
            /**
             * @brief Rotate the vector object
             * @param aEuler The angle values
             */
            void rotate(Euler aEuler);
            /**
             * @brief Rotate the vector object
             * @param aRotation The rotation vector
             * @param aAngle The angle in degree
             */
            void rotate(Vector aRotation, double aAngle);

            auto operator<=>(const Vector &aOther) const;
            Vector operator+(const Vector &aOther) const;
            Vector operator-(const Vector &aOther) const;
            double operator|(const Vector &aOther) const;
            Vector operator*(double aOther) const;
            Vector operator*(const Vector &aOther) const;
            Vector operator/(double aOther) const;
            /**
             * @brief The x value of the vector
             */
            double _x;
            /**
             * @brief The y value of the vector
             */
            double _y;
            /**
             * @brief The z value of the vector
             */
            double _z;
            /**
             * @brief The distance of the vector
             */
            double _dist;
    };
} // namespace RayTracer

#endif /* !VECTOR_HPP_ */
