//
// Created by patatofour on 17/04/23.
//

#include "Color.hpp"
#include "Entity/Entity.hpp"

namespace RayTracer::Entity
{
    Color::Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
        : Entity(EntityType::COLOR, Point(0, 0, 0))
        , _r(r)
        , _g(g)
        , _b(b)
        , _a(a)
    {
    }

    Color::~Color() = default;
} // namespace RayTracer::Entity
