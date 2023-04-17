//
// Created by patatofour on 17/04/23.
//

#ifndef RAYTRACER_COLOR_HPP
#define RAYTRACER_COLOR_HPP

#include "Entity.hpp"
#include <cstdint>

namespace RayTracer::Entity
{
    class Color : public Entity
    {
        public:
            Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255);
            ~Color() override;

            uint8_t _r;
            uint8_t _g;
            uint8_t _b;
            uint8_t _a;
    };
} // namespace RayTracer::Entity

#endif // RAYTRACER_COLOR_HPP
