//
// Created by patatofour on 17/04/23.
//

#include "Entity.hpp"

namespace RayTracer::Entity
{
    Entity::Entity(EntityType aType)
        : _type(aType)
        , _position(Point(0, 0, 0))
        , _rotation(Vector(1, 0, 0))
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

    Vector const &Entity::getRotation()
    {
        return _rotation;
    }

    void Entity::setRotation(const Vector &aRotation)
    {
        _rotation = aRotation;
    }

    void Entity::translate(const Vector &aVector)
    {
        _position = _position + aVector;
    }

    void Entity::rotate(const Vector &aRotation)
    {
        _rotation = _rotation + aRotation;
    }

} // namespace RayTracer::Entity
