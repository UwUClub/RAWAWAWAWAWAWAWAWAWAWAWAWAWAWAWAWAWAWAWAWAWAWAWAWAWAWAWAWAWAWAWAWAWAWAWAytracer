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
        class PlaneParser {
            public:
                explicit PlaneParser() = default;
                ~PlaneParser() = default;

                static std::string getPlaneAxis(const libconfig::Setting &plane);
                static RayTracer::Point &getPlanePosition(const libconfig::Setting &plane, const std::string &axis);
                static RayTracer::Vector getPlaneColor(const libconfig::Setting &plane);
                static void createPlane(const libconfig::Setting &plane, RayTracer::Scene::Scene &scene);
            protected:
            private:
        };
    } // RayTracer

#endif //RAYTRACER_PLANEPARSER_HPP
