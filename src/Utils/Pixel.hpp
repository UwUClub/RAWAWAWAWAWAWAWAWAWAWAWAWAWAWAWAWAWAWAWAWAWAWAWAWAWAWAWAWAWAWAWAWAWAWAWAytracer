/*
** EPITECH PROJECT, 2023
** RAWAWAWAytracer
** File description:
** Pixel
*/

#ifndef PIXEL_HPP_
#define PIXEL_HPP_

#include "Point.hpp"
#include "Color.hpp"

namespace RayTracer
{
    /**
     * @brief The Pixel class
     */
    struct Pixel {
        public:
            /**
             * @brief Construct a new Pixel object
             */
            Pixel(const Point aPosition, const Color aColor);
            /**
             * @brief Destroy the Pixel object
             */
            ~Pixel() = default;
            /**
             * @brief The position of the Pixel on the screen
             */
            Point _position;
            /**
             * @brief The color value of the Pixel
             */
            Color _color;
    };
} // namespace RayTracer

#endif /* !PIXEL_HPP_ */
