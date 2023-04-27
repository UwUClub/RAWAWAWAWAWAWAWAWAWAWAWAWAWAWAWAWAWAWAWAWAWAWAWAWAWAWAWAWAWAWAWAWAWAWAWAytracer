/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** CameraParser.cpp
*/

#include "CameraParser.hpp"
#include "IEntity.hpp"

namespace RayTracer::Parser
{
    void CameraParser::getCameraResolution(const libconfig::Setting &aCamera,
        Entity::DataEntityMap &aData)
    {
        float myWdth = 0;
        float myHeight = 0;
        const libconfig::Setting &myResolution = aCamera["resolution"];

        if (!myResolution.exists("width") || !myResolution.exists("height"))
            throw Parser::ParserException("Camera is missing parameters (width, height).");
        myResolution.lookupValue("width", myWdth);
        myResolution.lookupValue("height", myHeight);
        aData.insert(std::make_pair("width", myWdth));
        aData.insert(std::make_pair("height", myHeight));
    }

    void CameraParser::getCameraFieldOfView(const libconfig::Setting &aCamera,
        Entity::DataEntityMap &aData)
    {
        float myFov = 0;

        if (!aCamera.exists("fieldOfView"))
            throw Parser::ParserException("Camera is missing parameters (fieldOfView).");
        aCamera.lookupValue("fieldOfView", myFov);
        aData.insert(std::make_pair("fov", myFov));
    }

    void CameraParser::getCameraPosition(const libconfig::Setting &aCamera,
        Entity::DataEntityMap &aData)
    {
        float myX = 0;
        float myY = 0;
        float myZ = 0;
        const libconfig::Setting &myPosition = aCamera["position"];

        if (!myPosition.exists("x") || !myPosition.exists("y") || !myPosition.exists("z"))
            throw Parser::ParserException("Camera is missing parameters (x, y, z).");
        myPosition.lookupValue("x", myX);
        myPosition.lookupValue("y", myY);
        myPosition.lookupValue("z", myZ);
        aData.insert(std::make_pair("x", myX));
        aData.insert(std::make_pair("y", myY));
        aData.insert(std::make_pair("z", myZ));
    }

    void CameraParser::getCameraRotation(const libconfig::Setting &aCamera,
        Entity::DataEntityMap &aData)
    {
        float myX;
        float myY;
        float myZ;
        const libconfig::Setting &myRotation = aCamera["rotation"];

        if (!myRotation.exists("x") || !myRotation.exists("y") || !myRotation.exists("z"))
            throw Parser::ParserException("Camera is missing parameters (x, y, z).");
        myRotation.lookupValue("x", myX);
        myRotation.lookupValue("y", myY);
        myRotation.lookupValue("z", myZ);
        aData.insert(std::make_pair("rotate_x", myX));
        aData.insert(std::make_pair("rotate_y", myY));
        aData.insert(std::make_pair("rotate_z", myZ));
    }

    void CameraParser::createCamera(const libconfig::Setting &aCamera,
        Entity::DataEntityMap &aCameraData, RayTracer::Plugin::PluginManager &aPluginManager,
        RayTracer::Scene::Scene &aScene)
    {
        getCameraPosition(aCamera, aCameraData);
        getCameraRotation(aCamera, aCameraData);
        getCameraResolution(aCamera, aCameraData);
        getCameraFieldOfView(aCamera, aCameraData);
        auto myCameraEntity = aPluginManager.createEntity("Camera", aCameraData);
        aScene.addEntity("Camera", myCameraEntity);
    }
} // namespace RayTracer::Parser
