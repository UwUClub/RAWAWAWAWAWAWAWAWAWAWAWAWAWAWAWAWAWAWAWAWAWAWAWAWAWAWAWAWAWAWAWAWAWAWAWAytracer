//
// Created by patatofour on 17/04/23.
//

#include "Entity.hpp"

namespace RayTracer::Entity
{
    Entity::Entity(EntityType type)
        : _type(type)
    {
    }

    Entity::~Entity() = default;

    EntityType Entity::getType() const
    {
        return _type;
    }
} // namespace RayTracer::Entity
