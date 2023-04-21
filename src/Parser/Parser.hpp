//
// Created by beafowl on 17/04/23.
//

#ifndef RAYTRACER_PARSER_HPP
#define RAYTRACER_PARSER_HPP

#include <fstream>
#include <libconfig.h++>
#include <utility>
#include <iostream>
#include "Scene.hpp"
#include "CameraParser.hpp"
#include "PluginManager.hpp"

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
            explicit Parser(char **av, RayTracer::Scene::Scene &scene, RayTracer::Plugin::PluginManager &pluginManager);
            void CreateCamera(RayTracer::Scene::Scene &scene);
            void CreatePrimitive(RayTracer::Scene::Scene &scene);
            void CreateLight(RayTracer::Scene::Scene &scene);

        private:
            libconfig::Config _cfg;
            RayTracer::Scene::Scene &_scene;
            RayTracer::Plugin::PluginManager &_pluginManager;
    };
} // RayTracer

#endif //RAYTRACER_PARSER_HPP
