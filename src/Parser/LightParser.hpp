/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** PointLightParser.hpp
*/

#ifndef RAYTRACER_POINTLIGHTPARSER_HPP
#define RAYTRACER_POINTLIGHTPARSER_HPP

#include "IEntity.hpp"
#include "Parser.hpp"
#include <libconfig.h++>

namespace RayTracer::Light
{
    /**
     * @brief Class to parse the light
     * @details This class is used to parse the light, it's a static class
     */
    class LightParser
    {
        public:
            /**
             * @brief Get and parses the Light Position
             *
             * @param aPointLight The light to parse
             * @param aData The data to fill
             */
            static void getLightPosition(const libconfig::Setting &aPointLight,
                Entity::DataEntityMap &aData);
            /**
             * @brief Create and parses the Light
             *
             * @param aPointLight The light to parse
             * @param aData The data to use
             * @param aPluginManager The plugin manager to create the entity
             * @param aScene The scene to add the entity
             */
            static void createLight(const libconfig::Setting &aPointLight,
                Entity::DataEntityMap &aPrimitiveData,
                RayTracer::Plugin::PluginManager &aPluginManager, RayTracer::Scene::Scene &aScene);

        protected:
        private:
    };
} // namespace RayTracer::Light

#endif // RAYTRACER_POINTLIGHTPARSER_HPP
