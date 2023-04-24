//
// Created by patatofour on 17/04/23.
//

#include "Entity.hpp"

namespace RayTracer::Entity
{
    Entity::Entity(EntityType aType)
        : _type(aType)
        , _position(Point(0, 0, 0))
        , _angle(Euler(0, 0, 0))
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

    Euler const &Entity::getAngle()
    {
        return _angle;
    }

    void Entity::setAngle(const Euler &aAngle)
    {
        _angle = aAngle;
    }

    void Entity::translate(const Vector &aVector)
    {
        _position = _position + aVector;
    }

    void Entity::rotate(const Euler &aAngle)
    {
        _angle = _angle + aAngle;
    }

} // namespace RayTracer::Entity
