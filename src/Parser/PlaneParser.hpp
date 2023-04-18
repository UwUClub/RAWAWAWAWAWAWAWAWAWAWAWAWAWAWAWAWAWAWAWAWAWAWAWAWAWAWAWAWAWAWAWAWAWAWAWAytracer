/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** PlaneParser.hpp
*/

#ifndef RAYTRACER_PLANEPARSER_HPP
    #define RAYTRACER_PLANEPARSER_HPP

    #include "Parser.hpp"
    #include "Plane.hpp"
    #include <libconfig.h++>


    namespace RayTracer::Parser {
        /**
         * @brief Plane Parser, parse the plane from the config file
         */
        class PlaneParser {
            public:
                explicit PlaneParser() = default;
                ~PlaneParser() = default;

                /**
                 * @brief Get the Plane Axis object
                 * @param libconfig::Setting the plane setting from the config file
                 * @return String string of "x", "y" or "z" (String)
                 */
                static std::string getPlaneAxis(const libconfig::Setting &plane);

                /**
                 * @brief Get the Plane Position object
                 * @param libconfig::Setting the plane setting from the config file
                 * @param std::string the axis of the plane
                 * @return Point the position of the plane
                 */
                static RayTracer::Point &getPlanePosition(const libconfig::Setting &plane, const std::string &axis);

                /**
                 * @brief Get the Plane Color object
                 * @param libconfig::Setting the plane setting from the config file
                 * @return Vector the vector color of the plane
                 */
                static RayTracer::Vector getPlaneColor(const libconfig::Setting &plane);

                /**
                 * @brief Create a Plane object and add it to the scene
                 * @param libconfig::Setting plane setting from the config file
                 * @param RayTracer::Scene::Scene scene to add the plane to
                 */
                static void createPlane(const libconfig::Setting &plane, RayTracer::Scene::Scene &scene);
        };
    } // RayTracer

#endif //RAYTRACER_PLANEPARSER_HPP
