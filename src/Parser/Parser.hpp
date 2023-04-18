//
// Created by beafowl on 17/04/23.
//

#ifndef RAYTRACER_PARSER_HPP
#define RAYTRACER_PARSER_HPP

#include <fstream>
#include "Camera.cpp"
#include "Primitives.cpp"
#include "Light.cpp"
#include <libconfig.h++>

namespace RayTracer::Parser
{
    class Parser
    {
        class ParserException : public std::exception
        {
            public:
                explicit ParserException(const std::string &message) : _message(message){}

                ~ParserException() override = default;

                [[nodiscard]] const char *what() const noexcept override { return _message.c_str(); }

            private:
                std::string _message;
        };
        public:
            explicit Parser(int ac, char **av);
            ~Parser();
            RayTracer::Camera::Camera getCamera();
            RayTracer::Primitives::Primitives getPrimitive();
            RayTracer::Light::Light getLight();

        private:
            libconfig::Config _cfg;
    };
} // RayTracer

#endif //RAYTRACER_PARSER_HPP
