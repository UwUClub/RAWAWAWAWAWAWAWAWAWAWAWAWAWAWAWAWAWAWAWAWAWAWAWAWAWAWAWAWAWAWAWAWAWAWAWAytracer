//
// Created by valegox on 25/04/23.
//

#include "Renderer.hpp"

namespace RayTracer::Renderer
{
    Renderer::Renderer(const std::vector<Pixel> aPixels)
        : _pixels(aPixels)
    {
    }

    std::vector<Pixel> const &Renderer::getPixels()
    {
        return _pixels;
    }

    void Renderer::setPixels(const std::vector<Pixel> &aPixels)
    {
        _pixels = aPixels;
    }
} // namespace RayTracer::Renderer
