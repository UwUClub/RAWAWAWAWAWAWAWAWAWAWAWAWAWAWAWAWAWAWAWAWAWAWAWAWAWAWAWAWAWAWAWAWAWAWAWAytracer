//
// Created by valegox on 25/04/23.
//

#include "Renderer.hpp"

namespace RayTracer::Renderer
{
    Renderer::Renderer(RendererType aType)
        : _type(aType)
        , _position(Point(0, 0, 0))
        , _angle(Euler(0, 0, 0))
    {
    }

    Renderer::~Renderer() = default;

    std::vector<Pixel> const Renderer::getPixels()
    {
        return _pixels;
    }

    void enderer::setPixels(const std::vector<Pixel> aPixels)
    {
        _pixels = aPixels;
    }
} // namespace RayTracer::Renderer
