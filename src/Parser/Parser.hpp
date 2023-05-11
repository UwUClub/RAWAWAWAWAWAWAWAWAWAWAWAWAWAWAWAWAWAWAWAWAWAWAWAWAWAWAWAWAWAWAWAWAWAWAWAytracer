//
// Created by beafowl on 17/04/23.
//

#ifndef RAYTRACER_PARSER_HPP
#define RAYTRACER_PARSER_HPP

#include "PluginManager.hpp"
#include "Scene.hpp"
#include <fstream>
#include <iostream>
#include <libconfig.h++>
#include <utility>

namespace RayTracer::Parser
{
    /**
     * @brief The Parser class
     * @details This class is used to parse the config file
     */
    class Parser
    {
        public:
            /**
             * @brief The ParserException class
             * @details This class is used to throw an exception when the parser fails
             */
            class ParserException : public std::exception
            {
                public:
                public:
                    explicit ParserException(std::string message)
                        : _message(std::move(message))
                    {
                    }

                    ~ParserException() override = default;

                    [[nodiscard]] const char *what() const noexcept override
                    {
                        return _message.c_str();
                    }

                private:
                    std::string _message;
            };

            /**
             * @brief Construct a new Parser object
             *
             * @param aAv The arguments of the program
             * @param aScene The scene to fill
             * @param aPluginManager The plugin manager to create entities
             */
            explicit Parser(char **aAv, RayTracer::Scene::Scene &aScene,
                RayTracer::Plugin::PluginManager &aPluginManager);
            /**
             * @brief Destroy the Parser object
             */
            ~Parser() = default;
            /**
             * @brief Create a Camera object
             *
             * @param aScene The scene to fill
             * @param aPluginManager The plugin manager to create entities
             */
            void CreateCamera(RayTracer::Scene::Scene &aScene,
                RayTracer::Plugin::PluginManager &aPluginManager);
            /**
             * @brief Create a Primitive object
             *
             * @param aScene The scene to fill
             * @param aPluginManager The plugin manager to create entities
             */
            void CreatePrimitive(RayTracer::Scene::Scene &aScene,
                RayTracer::Plugin::PluginManager &aPluginManager);
            /**
             * @brief Create a Light object
             *
             * @param aScene The scene to fill
             * @param aPluginManager The plugin manager to create entities
             */
            void CreateLight(RayTracer::Scene::Scene &aScene,
                RayTracer::Plugin::PluginManager &aPluginManager);

        private:
            libconfig::Config _cfg;
    };
} // namespace RayTracer::Parser

#endif // RAYTRACER_PARSER_HPP
