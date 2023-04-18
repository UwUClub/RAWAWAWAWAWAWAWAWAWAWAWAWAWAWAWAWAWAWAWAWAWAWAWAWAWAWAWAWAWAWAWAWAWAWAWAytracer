//
// Created by beafowl on 17/04/23.
//

#ifndef RAYTRACER_PARSER_HPP
#define RAYTRACER_PARSER_HPP

#include <fstream>
#include "Scene.hpp"
#include "Camera.hpp"
#include "Sphere.hpp"
#include "Plane.hpp"
#include "DirectionalLight.hpp"
#include "PointLight.hpp"
#include "SphereParser.hpp"
#include "PlaneParser.hpp"
#include "PointLightParser.hpp"
#include "CameraParser.hpp"
#include <libconfig.h++>
#include <utility>

namespace RayTracer::Parser
{
    class Parser
    {
        public:
            class ParserException : public std::exception
            {
                public:
                    public:  explicit ParserException(std::string message) : _message(std::move(message)){}

                    ~ParserException() override = default;

                    [[nodiscard]] const char *what() const noexcept override { return _message.c_str(); }

                private:
                    std::string _message;
            };
            ~Parser() = default;
            explicit Parser(char **av, RayTracer::Scene::Scene &scene);
            void CreateCamera();
            void CreatePrimitive(RayTracer::Scene::Scene &scene);
            void CreateLight(RayTracer::Scene::Scene &scene);

        private:
            libconfig::Config _cfg;
            RayTracer::Scene::Scene &_scene;
    };
} // RayTracer

#endif //RAYTRACER_PARSER_HPP
