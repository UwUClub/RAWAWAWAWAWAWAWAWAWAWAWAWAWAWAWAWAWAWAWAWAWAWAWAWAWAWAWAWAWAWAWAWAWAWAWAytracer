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
        class LightParser {
            public:
                explicit LightParser() = default;
                ~LightParser() = default;

                static void getLightPosition(const libconfig::Setting &pointLight, std::unordered_map<std::string, double> &data);
                static void createLight(const libconfig::Setting &pointLight, std::unordered_map<std::string, double> &primitiveData,  RayTracer::Plugin::PluginManager &pluginManager, RayTracer::Scene::Scene &scene);
            protected:
            private:
        };
    } // RayTracer


#endif //RAYTRACER_POINTLIGHTPARSER_HPP