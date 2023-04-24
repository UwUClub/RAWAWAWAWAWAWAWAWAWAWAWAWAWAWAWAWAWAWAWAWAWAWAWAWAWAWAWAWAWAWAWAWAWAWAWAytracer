/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Camera.cpp
*/

#include "Camera.hpp"

namespace RayTracer::Entity {
    Camera::Camera(const std::unordered_map<std::string, double> &dataMap) : Entity(EntityType::CAMERA), _resolution(0, 0), _rotation(0, 0, 0), _fieldOfView(0)
    {
        if (dataMap.find("width") != dataMap.end())
            _resolution.first = dataMap.at("width");
        if (dataMap.find("height") != dataMap.end())
            _resolution.second = dataMap.at("height");
        if (dataMap.find("fov") != dataMap.end())
            _fieldOfView = dataMap.at("fov");
        if (dataMap.find("rotate_x") != dataMap.end())
            _rotation._x = dataMap.at("rotate_x");
        if (dataMap.find("rotate_y") != dataMap.end())
            _rotation._y = dataMap.at("rotate_y");
        if (dataMap.find("rotate_z") != dataMap.end())
            _rotation._z = dataMap.at("rotate_z");
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
        _fieldOfView = fov;
    }
} // RayTracer