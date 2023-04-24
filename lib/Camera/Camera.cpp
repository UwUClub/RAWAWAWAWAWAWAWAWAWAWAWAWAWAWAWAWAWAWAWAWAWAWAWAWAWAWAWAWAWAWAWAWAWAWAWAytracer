/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Camera.cpp
*/

#include "Camera.hpp"

namespace RayTracer::Entity {
    Camera::Camera() : Entity(EntityType::CAMERA), _resolution(0, 0), _rotation(0, 0, 0), fieldOfView(0)
    {
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