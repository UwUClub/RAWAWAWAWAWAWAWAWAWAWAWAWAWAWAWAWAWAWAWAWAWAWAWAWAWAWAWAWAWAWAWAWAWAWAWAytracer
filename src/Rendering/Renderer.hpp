//
// Created by valegox on 25/04/23.
//

#ifndef RAYTRACER_RENDERER_HPP
#define RAYTRACER_RENDERER_HPP

#include "Pixel.hpp"
#include <vector>

namespace RayTracer::Renderer
{
    /**
     * @brief The Renderer class
     */
    class Renderer
    {
        public:
            /**
             * @brief Construct a new Renderer object
             * @param type The type of the Renderer
             */
            Renderer(std::vector<Pixel> aPixels);
            ~Renderer() override;

            /**
             * @brief Get pixels
             * @return The pixels
             */
            std::vector<Pixel> const &getPixels();

            /**
             * @brief Set pixels
             * @param pixels The pixels
             */
            void setPixels(const std::vector<Pixel> &aPixels);

        private:
            std::vector<Pixel> _pixels;
    };
} // namespace RayTracer::Renderer

#endif // RAYTRACER_RENDERER_HPP
