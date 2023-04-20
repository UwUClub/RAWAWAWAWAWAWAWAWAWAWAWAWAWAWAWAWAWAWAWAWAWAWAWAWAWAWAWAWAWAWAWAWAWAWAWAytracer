//
// Created by patatofour on 17/04/23.
//

#include "Entity.hpp"

namespace RayTracer::Entity
{
    Entity::Entity(EntityType aType)
        : _type(aType)
        , _position(Point(0, 0, 0))
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

    void Entity::setPosition(const Point &aPoint)
    {
        _position = aPoint;
    }

    void Entity::translate(const Vector &aVector)
    {
        _position = _position + aVector;
    }
} // namespace RayTracer::Entity
