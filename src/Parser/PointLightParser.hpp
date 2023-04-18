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
        class PointLightParser {
            public:
                explicit PointLightParser() = default;
                ~PointLightParser() = default;

                static RayTracer::Point &getPointLightPosition(const libconfig::Setting &pointLight);
                static void createPointLight(const libconfig::Setting &pointLight, RayTracer::Scene::Scene &scene);
            protected:
            private:
        };
    } // RayTracer


#endif //RAYTRACER_POINTLIGHTPARSER_HPP
