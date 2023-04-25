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
            Color(const int aR, const int aG, const int aB);
            ~Color() = default;

            int _r;
            int _g;
            int _b;
    };
} // namespace RayTracer

#endif /* !COLOR_HPP_ */
