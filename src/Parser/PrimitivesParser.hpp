/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** PrimitivesParser.hpp
*/

#ifndef RAYTRACER_PRIMITIVESPARSER_HPP
    #define RAYTRACER_PRIMITIVESPARSER_HPP

    #include "Parser.hpp"
    
    namespace RayTracer::Parser {
        class PrimitivesParser {
            public:
                explicit PrimitivesParser() = default;
                ~PrimitivesParser() = default;

                /**
                 * @brief Get the Primitive Position object
                 * @param libconfig::Setting the primitive to parse
                 * @param std::unordered_map<std::string, float> the data to fill
                 */
                static void getPrimitivePosition(const libconfig::Setting &primitive, std::unordered_map<std::string, double> &data);

                /**
                 * @brief Get the Primitive Color object
                 * @param libconfig::Setting the primitive to parse
                 * @param std::unordered_map<std::string, float> the data to fill
                 */
                static void getPrimitiveColor(const libconfig::Setting &primitive, std::unordered_map<std::string, double> &data);

                /**
                 * @brief Get the Primitive Radius object
                 * @param libconfig::Setting the primitive to parse
                 * @param std::unordered_map<std::string, float> the data to fill
                 */
                static void getPrimitiveRadius(const libconfig::Setting &primitive, std::unordered_map<std::string, double> &data);

                /**
                 * @brief Get the Plane Axis object
                 * @param libconfig::Setting the primitive to parse
                 * @param std::unordered_map<std::string, float> the data to fill
                 */
                static void getPlaneAxis(const libconfig::Setting &plane, std::unordered_map<std::string, double> &data);

                /**
                 * @brief Get the Plane Position object
                 * @param libconfig::Setting the primitive to parse
                 * @param std::unordered_map<std::string, float> the data to fill
                 */
                static void getPlanePosition(const libconfig::Setting &plane, std::unordered_map<std::string, double> &data);

                /**
                 * @brief Get the Plane Normal object
                 * @param libconfig::Setting the primitive to parse
                 * @param std::unordered_map<std::string, float> the data to fill
                 * @param RayTracer::Plugin::PluginManager the plugin manager to create the primitive
                 * @param RayTracer::Scene::Scene the scene to add the primitive
                 */
                static void createPlane(const libconfig::Setting &plane, std::unordered_map<std::string, double> &primitiveData, RayTracer::Plugin::PluginManager &pluginManager, RayTracer::Scene::Scene &scene);

                /**
                 * @brief Get the Sphere Position object
                 * @param libconfig::Setting the primitive to parse
                 * @param std::unordered_map<std::string, float> the data to fill
                 * @param RayTracer::Plugin::PluginManager the plugin manager to create the primitive
                 * @param RayTracer::Scene::Scene the scene to add the primitive
                 */
                 static void createPrimitive(const libconfig::Setting &sphere, std::unordered_map<std::string, double> &primitiveData, RayTracer::Plugin::PluginManager &pluginManager, RayTracer::Scene::Scene &scene);
        };
    } // RayTracer


#endif //RAYTRACER_PRIMITIVESPARSER_HPP
