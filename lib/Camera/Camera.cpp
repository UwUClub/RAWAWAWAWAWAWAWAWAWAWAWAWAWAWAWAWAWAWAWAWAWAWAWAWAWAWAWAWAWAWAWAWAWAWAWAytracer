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
        , _angles(0, 0, 0)
        , _fieldOfView(0)
    {
        if (dataMap.find("width") != dataMap.end())
            _resolution.first = dataMap.at("width");
        if (dataMap.find("height") != dataMap.end())
            _resolution.second = dataMap.at("height");
        if (dataMap.find("fov") != dataMap.end())
            _fieldOfView = dataMap.at("fov");
        if (dataMap.find("rotate_x") != dataMap.end())
            _angles._x = dataMap.at("rotate_x");
        if (dataMap.find("rotate_y") != dataMap.end())
            _angles._y = dataMap.at("rotate_y");
        if (dataMap.find("rotate_z") != dataMap.end())
            _angles._z = dataMap.at("rotate_z");
    }

    void Camera::setAngles(const Euler &aAngles)
    {
        _angles = aAngles;
    }

    void Camera::setResolution(const std::pair<int, int> &aResolution)
    {
        _resolution = aResolution;
    }

    void Camera::setFieldOfView(float aFov)
    {
        _fieldOfView = aFov;
    }

    std::vector<Ray> Camera::getCastedRays() const
    {
        const int myMinX = _position._x - _resolution.first / 2;
        const int myMaxX = _position._x + _resolution.first / 2;
        const int myMinY = _position._y - _resolution.second / 2;
        const int myMaxY = _position._y + _resolution.second / 2;
        std::vector<Ray> myRays = std::vector<Ray>();

        for (int myX = myMinX; myX <= myMaxX; myX++) {
            for (int myY = myMinY; myY <= myMaxY; myY++) {
                Point myOrigin(myX, myY, _position._z);
                myOrigin.rotate(_position, _angles);

                Vector myDirection(myX - _position._x, myY - _position._y, 1);
                myDirection = myDirection * _fieldOfView;
                myDirection.rotate(_angles);

                Ray myRay(myOrigin, myDirection);
                myRays.push_back(myRay);
            }
        }
        return myRays;
    }

} // namespace RayTracer::Entity
