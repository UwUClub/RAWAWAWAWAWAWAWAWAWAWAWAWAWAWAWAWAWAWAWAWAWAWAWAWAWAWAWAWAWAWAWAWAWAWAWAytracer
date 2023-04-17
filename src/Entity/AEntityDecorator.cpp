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

    EntityType AEntityDecorator::getType() const
    {
        return _entity->getType();
    }

    void AEntityDecorator::translate(Vector &vector)
    {
        _entity->translate(vector);
    }

    void AEntityDecorator::rotate(Vector &vector)
    {
        _entity->rotate(vector);
    }
} // namespace RayTracer::Entity
