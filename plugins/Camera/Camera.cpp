/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Camera.cpp
*/

#include "Camera.hpp"

namespace RayTracer::Camera {
    Camera::Camera() : _resolution(0, 0), _position(0, 0, 0), _rotation(0, 0, 0), fieldOfView(0)
    {
    }

    void Camera::setPosition(const RayTracer::Vector &position)
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

} // RayTracer