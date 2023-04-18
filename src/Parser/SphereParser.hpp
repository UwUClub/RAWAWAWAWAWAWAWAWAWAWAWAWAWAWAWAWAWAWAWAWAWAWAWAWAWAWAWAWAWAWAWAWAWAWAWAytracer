//
// Created by beafowl on 18/04/23.
//

#ifndef RAYTRACER_SPHEREPARSER_HPP
    #define RAYTRACER_SPHEREPARSER_HPP

    #include "Parser.hpp"
    #include "Sphere.hpp"
    #include <libconfig.h++>

    namespace RayTracer::Parser
    {
        class SphereParser
        {
            public:
                SphereParser() = default;
                ~SphereParser() = default;

                static void createSphere(const libconfig::Setting &sphere, RayTracer::Scene::Scene &scene);
                static RayTracer::Vector getSpherePosition(const libconfig::Setting &sphere);
                static int getSphereRadius(const libconfig::Setting &sphere);
                static RayTracer::Vector getSphereColor(const libconfig::Setting &sphere);
        };
    } // RayTracer

#endif //RAYTRACER_SPHEREPARSER_HPP
