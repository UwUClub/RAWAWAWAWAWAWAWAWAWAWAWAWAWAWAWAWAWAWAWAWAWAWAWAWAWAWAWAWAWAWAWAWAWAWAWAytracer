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
        if (dataMap.find("x") != dataMap.end())
            _position._x = dataMap.at("x");
        if (dataMap.find("y") != dataMap.end())
            _position._y = dataMap.at("y");
        if (dataMap.find("z") != dataMap.end())
            _position._z = dataMap.at("z");
    }

    void Camera::setAngles(const Euler &aAngles)
    {
        _angles = aAngles;
    }

    resolution Camera::getResolution() const
    {
        return _resolution;
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

        for (int myY = myMaxY; myY > myMinY; myY--) {
            for (int myX = myMinX; myX < myMaxX; myX++) {
                Point myOrigin(myX, myY, _position._z);
                //myOrigin.rotate(_position, _angles);
                Vector myDirection(myX + (myX - _position._x), myY + (myY - _position._y), _fieldOfView);
                //myDirection.rotate(_angles);
                Ray myRay(myOrigin, myDirection);
                myRays.push_back(myRay);
            }
        }
        return myRays;
    }

} // namespace RayTracer::Entity
