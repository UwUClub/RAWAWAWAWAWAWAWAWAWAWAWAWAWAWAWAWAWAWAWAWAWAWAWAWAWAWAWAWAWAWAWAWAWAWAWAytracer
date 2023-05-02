/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Camera.cpp
*/

#include "Camera.hpp"
#include "IEntity.hpp"

namespace RayTracer::Entity
{
    Camera::Camera(const DataEntityMap &dataMap)
        : Entity(EntityType::CAMERA)
        , _resolution(0, 0)
        , _rotation(0, 0, 0)
        , _fieldOfView(0)
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

    void Camera::setRotation(const Vector &aRotation)
    {
        _rotation = aRotation;
    }

    void Camera::setResolution(const std::pair<int, int> &aResolution)
    {
        _resolution = aResolution;
    }

    void Camera::setFieldOfView(float aFov)
    {
        _fieldOfView = aFov;
    }

    std::vector<Ray> &Camera::getCastedRays() const
    {
        int myMinX = _position._x - _resolution.first / 2;
        int myMaxX = _position._x + _resolution.first / 2;
        int myMinY = _position._y - _resolution.second / 2;
        int myMaxY = _position._y + _resolution.second / 2;
        std::vector<Ray> myRays = std::vector<Ray>();

        for (int myX = myMinX; myX <= myMaxX; myX++) {
            for (int myY = myMinY; myY <= myMaxY; myY++) {
                Point myOrigin(myX, myY, _position._z);

                Vector myDirection(myX - _position._x, myY - _position._y, 1);
                myDirection = myDirection * _fieldOfView;

                Ray myRay();
                // myRays.push_back(myRay);
            }
        }
        return myRays;
    }

} // namespace RayTracer::Entity
