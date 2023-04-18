//
// Created by beafowl on 18/04/23.
//

#ifndef RAYTRACER_SPHEREPARSER_HPP
    #define RAYTRACER_SPHEREPARSER_HPP

    #include "Parser.hpp"
    #include "Sphere.hpp"
    #include <libconfig.h++>

    namespace RayTracer::Parser {
        /**
         * @brief Sphere Parser, parse the sphere from the config file
         */
        class SphereParser {
            public:
                SphereParser() = default;
                ~SphereParser() = default;

                /**
                 * @brief Create a Sphere object and add it to the scene
                 * @param libconfig::Setting the sphere setting from the config file
                 * @param RayTracer::Scene::Scene the scene to add the sphere to
                 */
                static void createSphere(const libconfig::Setting &sphere, RayTracer::Scene::Scene &scene);

                /**
                 * @brief Get the Sphere Position object from the config file
                 * @param libconfig::Setting the sphere setting from the config file
                 * @return Point the position of the sphere
                 */
                static RayTracer::Point &getSpherePosition(const libconfig::Setting &sphere);

                /**
                 * @brief Get the Sphere Radius object from the config file
                 * @param libconfig::Setting the sphere setting from the config file
                 * @return int the radius of the sphere (int)
                 */
                static int getSphereRadius(const libconfig::Setting &sphere);

                /**
                 * @brief Get the Sphere Color object from the config file
                 * @param libconfig::Setting the sphere setting from the config file
                 * @return Vector the color of the sphere
                 */
                static RayTracer::Vector getSphereColor(const libconfig::Setting &sphere);
        };
    } // RayTracer

#endif //RAYTRACER_SPHEREPARSER_HPP
