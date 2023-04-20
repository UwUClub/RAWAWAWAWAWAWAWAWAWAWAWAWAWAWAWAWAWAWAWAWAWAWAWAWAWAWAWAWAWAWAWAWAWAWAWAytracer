/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Camera.cpp
*/

#include "Camera.hpp"

namespace RayTracer {
    Camera::Camera() : _resolution(0, 0), _position(0, 0, 0), _rotation(0, 0, 0), fieldOfView(0)
    {
    }

    void Camera::setPosition(const Point &position)
    {
        _position = position;
    }

    void Camera::setRotation(const RayTracer::Vector &rotation)
    {
        _rotation = rotation;
    }

    void Camera::setResolution(const std::pair<int, int> &resolution)
    {
        _resolution = resolution;
    }

    void Camera::setFieldOfView(float fov)
    {
        fieldOfView = fov;
    }

    void Camera::translate(const Vector &vector)
    {
        _position._x += vector._x;
        _position._y += vector._y;
        _position._z += vector._z;
    }

    void Camera::rotate(const Vector &vector)
    {
        _rotation._x += vector._x;
        _rotation._y += vector._y;
        _rotation._z += vector._z;
    }
} // RayTracer