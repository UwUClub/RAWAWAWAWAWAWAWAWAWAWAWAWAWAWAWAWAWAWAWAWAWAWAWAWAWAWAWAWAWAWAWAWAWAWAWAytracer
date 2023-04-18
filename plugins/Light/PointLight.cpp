//
// Created by beafowl on 18/04/23.
//

#include "PointLight.hpp"

namespace RayTracer::Light {
    PointLight::PointLight() : Light(), _position(0.0f, 0.0f, 0.0f) {}

    void PointLight::setPosition(const RayTracer::Vector &position)
    {
        _position = position;
    }

    Entity::EntityType PointLight::getType() const
    {
        return Entity::EntityType::LIGHT;
    }

    void PointLight::translate(RayTracer::Vector &vector)
    {
        _position._x += vector._x;
        _position._y += vector._y;
        _position._z += vector._z;
    }

    void PointLight::rotate(RayTracer::Vector &vector)
    {
        _position._x += vector._x;
        _position._y += vector._y;
        _position._z += vector._z;
    }
}
