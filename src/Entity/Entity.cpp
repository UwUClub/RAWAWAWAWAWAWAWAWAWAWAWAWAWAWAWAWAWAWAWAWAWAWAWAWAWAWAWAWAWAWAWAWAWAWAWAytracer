//
// Created by patatofour on 17/04/23.
//

#include "Utils/Point.hpp"
#include "Entity.hpp"

namespace RayTracer::Entity
{
    Entity::Entity(EntityType type)
        : _type(type), _position(Point(0, 0, 0))
    {
    }

    Entity::~Entity() = default;

    EntityType Entity::getType() const
    {
        return _type;
    }

    Point const &Entity::getPosition()
    {
        return _position;
    }

    void Entity::setPosition(Point &point)
    {
        _position = point;
    }

    void Entity::translate(Vector &vector)
    {
        _position = _position + vector;
    }
} // namespace RayTracer::Entity
