/*
** EPITECH PROJECT, 2023
** RAWAWAWAytracer
** File description:
** Pixel
*/

#ifndef PIXEL_HPP_
#define PIXEL_HPP_

#include "Point.hpp"
#include "Entity.hpp"
#include "Color.hpp"

namespace RayTracer::Renderer
{
    struct Pixel {
        public:
            Pixel(Point aPosition, Entity::Color aColor);
            ~Pixel() = default;
            Point _position;
            Entity::Color _color;
    };
} // namespace RayTracer

#endif /* !PIXEL_HPP_ */
