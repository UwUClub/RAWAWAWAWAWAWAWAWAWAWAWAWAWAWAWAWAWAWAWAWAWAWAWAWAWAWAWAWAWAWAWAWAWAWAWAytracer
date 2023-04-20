//
// Created by patatofour on 17/04/23.
//

#include "Color.hpp"

namespace RayTracer::Entity
{
    Color::Color(uint8_t aR, uint8_t aG, uint8_t aB, uint8_t aA)
        : Entity(EntityType::COLOR)
        , _r(aR)
        , _g(aG)
        , _b(aB)
        , _a(aA)
    {
    }

    Color::~Color() = default;
} // namespace RayTracer::Entity
