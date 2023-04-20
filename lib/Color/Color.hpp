//
// Created by patatofour on 17/04/23.
//

#ifndef RAYTRACER_COLOR_HPP
#define RAYTRACER_COLOR_HPP

#include "Entity.hpp"
#include <cstdint>

namespace RayTracer::Entity
{
    /**
     * @brief The Color class
     */
    class Color : public Entity
    {
        public:
            /**
             * @brief Construct a new Color object
             * @param aR The red value
             * @param aG The green value
             * @param aB The blue value
             * @param aA The alpha value
             */
            Color(uint8_t aR, uint8_t aG, uint8_t aB, uint8_t aA = 255);
            ~Color() override;

            /**
             * @brief The Red value of the color
             */
            uint8_t _r;
            /**
             * @brief The Green value of the color
             */
            uint8_t _g;
            /**
             * @brief The Blue value of the color
             */
            uint8_t _b;
            /**
             * @brief The Alpha value of the color
             */
            uint8_t _a;
    };
} // namespace RayTracer::Entity

#endif // RAYTRACER_COLOR_HPP
