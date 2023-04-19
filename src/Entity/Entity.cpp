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

    void Entity::setPosition(Point &point)
    {
        _position = point;
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
        _position = _position + vector;
    }

    void Entity::rotate(Euler &angle)
    {
        _angle = _angle + angle;
    }

} // namespace RayTracer::Entity
