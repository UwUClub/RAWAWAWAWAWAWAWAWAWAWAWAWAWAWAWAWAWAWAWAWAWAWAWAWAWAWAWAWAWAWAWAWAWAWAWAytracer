/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** CameraParser.hpp
*/

#ifndef RAYTRACER_CAMERAPARSER_HPP
    #define RAYTRACER_CAMERAPARSER_HPP

    #include "Parser.hpp"
    #include "Camera.hpp"
    #include <libconfig.h++>

    namespace RayTracer::Parser {
        /**
         * @brief Camera Parser, parse the camera from the config file
         */
        class CameraParser {
            public:
                explicit CameraParser() = default;
                ~CameraParser() = default;

                /**
                 * @brief Get the Camera Resolution object from the config file
                 * @param libconfig::Setting the camera setting from the config file
                 * @return Pair<int, int> a pair of int, the first one is the width, the second one is the height
                 */
                static std::pair<int, int> getCameraResolution(const libconfig::Setting &camera);

                /**
                 * @brief Get the Camera Field Of View object from the config file
                 * @param libconfig::Setting the camera setting from the config file
                 * @return Float the field of view of the camera
                 */
                static float getCameraFieldOfView(const libconfig::Setting &camera);

                /**
                 * @brief Get the Camera Position object from the config file
                 * @param libconfig::Setting the camera setting from the config file
                 * @return Point the position of the camera
                 */
                static RayTracer::Point &getCameraPosition(const libconfig::Setting &camera);

                /**
                 * @brief Get the Camera Rotation object from the config file
                 * @param libconfig::Setting the camera setting from the config file
                 * @return Vector the rotation of the camera
                 */
                static RayTracer::Vector getCameraRotation(const libconfig::Setting &camera);
        };
    } // RayTracer

#endif //RAYTRACER_CAMERAPARSER_HPP
