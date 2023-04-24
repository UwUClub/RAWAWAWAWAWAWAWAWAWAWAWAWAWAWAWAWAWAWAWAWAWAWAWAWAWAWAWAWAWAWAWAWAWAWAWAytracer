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

    void Camera::setRotation(const RayTracer::Vector &aRotation)
    {
        _rotation = aRotation;
    }

    void Camera::setResolution(const std::pair<int, int> &aResolution)
    {
        _resolution = aResolution;
    }

    void Camera::setFieldOfView(float aFov)
    {
        fieldOfView = aFov;
    }
} // RayTracer