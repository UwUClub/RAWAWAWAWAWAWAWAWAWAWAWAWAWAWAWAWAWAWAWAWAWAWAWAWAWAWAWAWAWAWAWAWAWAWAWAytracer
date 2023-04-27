/*
** EPITECH PROJECT, 2023
** RAWAWAWAytracer
** File description:
** Color
*/

#include <iostream>

#ifndef COLOR_HPP_
#define COLOR_HPP_

namespace RayTracer
{
    struct Color {
        public:
            /**
             * @brief Construct a new Color object
             *
             * @param aR The red value of the color
             * @param aG The green value of the color
             * @param aB The blue value of the color
             */
            Color(const int aR, const int aG, const int aB);
            ~Color() = default;

            int _r;
            int _g;
            int _b;
    };
} // namespace RayTracer

#endif /* !COLOR_HPP_ */
