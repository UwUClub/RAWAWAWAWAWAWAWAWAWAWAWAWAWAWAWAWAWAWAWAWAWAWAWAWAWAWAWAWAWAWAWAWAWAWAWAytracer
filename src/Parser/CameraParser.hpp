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

                static void getCameraResolution(const libconfig::Setting &camera, std::unordered_map<std::string, double> &data);
                static void getCameraFieldOfView(const libconfig::Setting &camera, std::unordered_map<std::string, double> &data);
                static void getCameraPosition(const libconfig::Setting &camera, std::unordered_map<std::string, double> &data);
                static void getCameraRotation(const libconfig::Setting &camera, std::unordered_map<std::string, double> &data);
            protected:
            private:
        };
    } // RayTracer

#endif //RAYTRACER_CAMERAPARSER_HPP
