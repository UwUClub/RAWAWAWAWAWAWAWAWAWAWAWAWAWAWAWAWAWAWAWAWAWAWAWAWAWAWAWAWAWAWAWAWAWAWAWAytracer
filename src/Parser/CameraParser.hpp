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
        class CameraParser {
            public:
                explicit CameraParser() = default;
                ~CameraParser() = default;

                static std::pair<int, int> getCameraResolution(const libconfig::Setting &camera);
                static float getCameraFieldOfView(const libconfig::Setting &camera);
                static RayTracer::Point &getCameraPosition(const libconfig::Setting &camera);
                static RayTracer::Vector getCameraRotation(const libconfig::Setting &camera);
            protected:
            private:
        };
    } // RayTracer

#endif //RAYTRACER_CAMERAPARSER_HPP
