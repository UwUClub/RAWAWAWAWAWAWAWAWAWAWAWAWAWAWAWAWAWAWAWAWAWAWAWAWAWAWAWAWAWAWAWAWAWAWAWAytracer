//
// Created by patatofour on 17/04/23.
//

#include "Entity.hpp"

namespace RayTracer::Entity
{
    Entity::Entity(EntityType type, Point position)
        : _type(type), _position(position)
    {
    }

    Entity::~Entity() = default;

    EntityType Entity::getType() const
    {
        return _type;
    }

    void Entity::translate(Vector &vector) {
        _position = _position + vector;
    }
} // namespace RayTracer::Entity
