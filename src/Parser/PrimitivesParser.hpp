/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** PrimitivesParser.hpp
*/

#ifndef RAYTRACER_PRIMITIVESPARSER_HPP
#define RAYTRACER_PRIMITIVESPARSER_HPP

#include "IEntity.hpp"
#include "Parser.hpp"

namespace RayTracer::Parser
{
    class PrimitivesParser
    {
        public:
            explicit PrimitivesParser() = default;
            ~PrimitivesParser() = default;

            /**
             * @brief Get the Primitive Position object
             * @param aPrimitive the primitive to parse
             * @param aData the data to fill
             */
            static void getPrimitivePosition(const libconfig::Setting &aPrimitive,
                Entity::DataEntityMap &aData);

            /**
             * @brief Get the Primitive Color object
             * @param aPrimitive the primitive to parse
             * @param aData the aData to fill
             */
            static void getPrimitiveColor(const libconfig::Setting &aPrimitive,
                Entity::DataEntityMap &aData);

            /**
             * @brief Get the Primitive Radius object
             * @param aPrimitive the aPrimitive to parse
             * @param aData the data to fill
             */
            static void getPrimitiveRadius(const libconfig::Setting &aPrimitive,
                Entity::DataEntityMap &aData);

            /**
             * @brief Get the Plane Axis object
             * @param aPlane the primitive to parse
             * @param aData the data to fill
             */
            static void getPlaneAxis(const libconfig::Setting &aPlane,
                Entity::DataEntityMap &aData);

            /**
             * @brief Get the Plane Position object
             * @param aPlane the primitive to parse
             * @param aData the data to fill
             */
            static void getPlanePosition(const libconfig::Setting &aPlane,
                Entity::DataEntityMap &aData);

            /**
             * @brief Get the Plane Normal object
             * @param aPlane the primitive to parse
             * @param aData the data to fill
             * @param aPluginManager the plugin manager to create the primitive
             * @param aScene the aScene to add the primitive
             */
            static void createPlane(const libconfig::Setting &aPlane,
                Entity::DataEntityMap &aPrimitiveData,
                RayTracer::Plugin::PluginManager &aPluginManager, RayTracer::Scene::Scene &aScene);

            /**
             * @brief Get the Sphere Position object
             * @param aSphere the primitive to parse
             * @param aData the data to fill
             * @param aPluginManager the plugin manager to create the primitive
             * @param aScene the aScene to add the primitive
             */
            static void createPrimitive(const libconfig::Setting &aSphere,
                Entity::DataEntityMap &aPrimitiveData,
                RayTracer::Plugin::PluginManager &aPluginManager, RayTracer::Scene::Scene &aScene);
    };
} // namespace RayTracer::Parser

#endif // RAYTRACER_PRIMITIVESPARSER_HPP
