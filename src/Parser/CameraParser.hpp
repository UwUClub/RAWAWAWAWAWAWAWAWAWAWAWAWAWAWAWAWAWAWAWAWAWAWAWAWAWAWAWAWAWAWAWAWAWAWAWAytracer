/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** CameraParser.hpp
*/

#ifndef RAYTRACER_CAMERAPARSER_HPP
#define RAYTRACER_CAMERAPARSER_HPP

#include "IEntity.hpp"
#include "Parser.hpp"
#include "PluginManager.hpp"
#include <libconfig.h++>

namespace RayTracer::Parser
{
    /**
     * @brief Class to parse the aCamera
     * @details This class is used to parse the aCamera, it's a static class
     */
    class CameraParser
    {
        public:
            /**
             * @brief Get and parses the Camera Resolution
             *
             * @param aCamera The camera to parse
             * @param aData The data to fill
             */
            static void getCameraResolution(const libconfig::Setting &aCamera,
                Entity::DataEntityMap &aData);
            /**
             * @brief Get and parses the Camera Field of View
             *
             * @param aCamera The camera to parse
             * @param aData The data to fill
             */
            static void getCameraFieldOfView(const libconfig::Setting &aCamera,
                Entity::DataEntityMap &aData);
            /**
             * @brief Get the Camera Position object
             *
             * @param aCamera The camera to parse
             * @param aData The data to fill
             */
            static void getCameraPosition(const libconfig::Setting &aCamera,
                Entity::DataEntityMap &aData);
            /**
             * @brief Get the Camera Rotation object
             *
             * @param aCamera The camera to parse
             * @param aData The data to fill
             */
            static void getCameraRotation(const libconfig::Setting &aCamera,
                Entity::DataEntityMap &aData);
            /**
             * @brief Create a Camera object
             *
             * @param aCamera The camera to parse
             * @param aPrimitiveData The data to use
             * @param aPluginManager The plugin manager to create the entity
             * @param aScene The scene to add the entity
             */
            static void createCamera(const libconfig::Setting &aCamera,
                Entity::DataEntityMap &aPrimitiveData,
                RayTracer::Plugin::PluginManager &aPluginManager, RayTracer::Scene::Scene &aScene);
    };
} // namespace RayTracer::Parser

#endif // RAYTRACER_CAMERAPARSER_HPP
