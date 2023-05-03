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
        int myWdth = 0;
        int myHeight = 0;
        const libconfig::Setting &myResolution = aCamera["resolution"];

        if (!myResolution.exists("width") || !myResolution.exists("height"))
            throw Parser::ParserException("Camera is missing parameters (width, height).");
        myResolution.lookupValue("width", myWdth);
        myResolution.lookupValue("height", myHeight);
        auto myDoubleHeight = static_cast<double>(myHeight);
        auto myDoubleWdth = static_cast<double>(myWdth);
        aData.insert(std::make_pair("width", myDoubleWdth));
        aData.insert(std::make_pair("height", myDoubleHeight));
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
        int myX = 0;
        int myY = 0;
        int myZ = 0;
        const libconfig::Setting &myPosition = aCamera["position"];

        if (!myPosition.exists("x") || !myPosition.exists("y") || !myPosition.exists("z"))
            throw Parser::ParserException("Camera is missing parameters (x, y, z).");
        myPosition.lookupValue("x", myX);
        myPosition.lookupValue("y", myY);
        myPosition.lookupValue("z", myZ);
        auto myDoubleX = static_cast<double>(myX);
        auto myDoubleY = static_cast<double>(myY);
        auto myDoubleZ = static_cast<double>(myZ);
        aData.insert(std::make_pair("x", myDoubleX));
        aData.insert(std::make_pair("y", myDoubleY));
        aData.insert(std::make_pair("z", myDoubleZ));
    }

    void CameraParser::getCameraRotation(const libconfig::Setting &aCamera,
        Entity::DataEntityMap &aData)
    {
        int myX;
        int myY;
        int myZ;
        const libconfig::Setting &myRotation = aCamera["rotation"];

        if (!myRotation.exists("x") || !myRotation.exists("y") || !myRotation.exists("z"))
            throw Parser::ParserException("Camera is missing parameters (x, y, z).");
        myRotation.lookupValue("x", myX);
        myRotation.lookupValue("y", myY);
        myRotation.lookupValue("z", myZ);
        auto myDoubleX = static_cast<double>(myX);
        auto myDoubleY = static_cast<double>(myY);
        auto myDoubleZ = static_cast<double>(myZ);
        std::cout << myDoubleX << std::endl;
        std::cout << myDoubleY << std::endl;
        std::cout << myDoubleZ << std::endl;
        aData.insert(std::make_pair("rotate_x", myDoubleX));
        aData.insert(std::make_pair("rotate_y", myDoubleY));
        aData.insert(std::make_pair("rotate_z", myDoubleZ));
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
