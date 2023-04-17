//
// Created by patatofour on 17/04/23.
//

#include "AEntityDecorator.hpp"

namespace RayTracer::Entity
{
    AEntityDecorator::AEntityDecorator(IEntityPtr entity)
        : _entity(std::move(entity))
    {
    }
} // namespace RayTracer::Entity
