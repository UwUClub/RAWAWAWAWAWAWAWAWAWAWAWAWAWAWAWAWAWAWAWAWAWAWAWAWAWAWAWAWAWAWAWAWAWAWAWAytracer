/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** PointLightParser.hpp
*/

#ifndef RAYTRACER_POINTLIGHTPARSER_HPP
    #define RAYTRACER_POINTLIGHTPARSER_HPP

    #include "Parser.hpp"
    #include "PointLight.hpp"
    #include <libconfig.h++>


    namespace RayTracer::Light {
        /**
         * @brief Point Light Parser, parse the point light from the config file
         */
        class PointLightParser {
            public:
                explicit PointLightParser() = default;
                ~PointLightParser() = default;

                /**
                 * @brief Get the Point Light Position object
                 * @param libconfig::Setting the point light setting from the config file
                 * @return Point the position of the point light (Point)
                 */
                static RayTracer::Point &getPointLightPosition(const libconfig::Setting &pointLight);

                /**
                 * @brief Create a Point Light object and add it to the scene
                 * @param libconfig::Setting the point light setting from the config file
                 * @param RayTracer::Scene::Scene the scene to add the point light to
                 */
                static void createPointLight(const libconfig::Setting &pointLight, RayTracer::Scene::Scene &scene);
        };
    } // RayTracer

#endif //RAYTRACER_POINTLIGHTPARSER_HPP
