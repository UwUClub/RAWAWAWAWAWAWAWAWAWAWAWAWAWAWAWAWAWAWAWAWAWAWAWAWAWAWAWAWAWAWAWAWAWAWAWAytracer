//
// Created by beafowl on 17/04/23.
//

#ifndef RAYTRACER_PARSER_HPP
#define RAYTRACER_PARSER_HPP

#include <fstream>
#include "Camera.hpp"
#include "Sphere.hpp"
#include "Plane.hpp"
#include "DirectionalLight.hpp"
#include "PointLight.hpp"
#include <libconfig.h++>
#include <utility>

namespace RayTracer::Parser
{
    class Parser
    {
        class ParserException : public std::exception
        {
            public:
                explicit ParserException(std::string message) : _message(std::move(message)){}

                ~ParserException() override = default;

                [[nodiscard]] const char *what() const noexcept override { return _message.c_str(); }

            private:
                std::string _message;
        };
        public:
            explicit Parser(int ac, char **av);
            ~Parser();
            RayTracer::Camera::Camera CreateCamera();
            void CreatePrimitive();
            void CreateLight();

        private:
            libconfig::Config _cfg;
            RayTracer::Scene &_scene;
    };
} // RayTracer

#endif //RAYTRACER_PARSER_HPP
