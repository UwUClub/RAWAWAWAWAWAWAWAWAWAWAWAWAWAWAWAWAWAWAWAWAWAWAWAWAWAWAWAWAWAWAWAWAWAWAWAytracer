//
// Created by patatofour on 17/04/23.
//

#include "Utils/Point.hpp"
#include "Utils/Euler.hpp"
#include "Entity.hpp"

namespace RayTracer::Entity
{
    Entity::Entity(EntityType type)
        : _type(type), _position(Point(0, 0, 0)), _angle(Euler(0, 0, 0))
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

    void Entity::setAngle(Euler &angle)
    {
        _angle = angle;
    }

    void Entity::translate(Vector &vector)
    {
        _position = _position + aVector;
    }

    void Entity::rotate(Euler &angle)
    {
        _angle = _angle + angle;
    }

} // namespace RayTracer::Entity
