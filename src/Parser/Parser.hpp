/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Parser.hpp
*/

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
        /**
         * @brief The Parser class, parse the config file and add the camera, primitives and light to the scene
         */
        class Parser
        {
            public:
                /**
                 * @brief The Parser Exception class, throw when the config file is not valid
                 */
                class ParserException : public std::exception
                {
                    public:
                        /**
                         * @brief Construct a new Parser Exception object
                         * @param A message of the exception
                         */
                        public:  explicit ParserException(std::string message) : _message(std::move(message)){}

                        ~ParserException() override = default;

                        /**
                         * @brief Get the message of the exception
                         * @return the message of the exception (const char *)
                         */
                        [[nodiscard]] const char *what() const noexcept override { return _message.c_str(); }

                    private:
                        std::string _message;
                };

                /**
                 * @brief Construct a new Parser object
                 * @param char** arguments of the program
                 * @param RayTracer::Scene::Scene scene to add the camera, primitives and light to
                 * @throw ParserException if the config file is not valid
                 */
                explicit Parser(char **av, RayTracer::Scene::Scene &scene);

                ~Parser() = default;

                /**
                 * @brief Parse the config file and add the camera to the scene
                 * @throw ParserException
                 */
                void CreateCamera();

                /**
                 * @brief Parse the config file and add the primitives to the scene
                 * @param RayTracer::Scene::Scene scene to add the primitives to
                 * @throw ParserException
                 */
                void CreatePrimitive(RayTracer::Scene::Scene &scene);

                /**
                 * @brief Parse the config file and add the lights to the scene
                 * @param RayTracer::Scene::Scene scene to add the lights to
                 * @throw ParserException
                 */
                void CreateLight(RayTracer::Scene::Scene &scene);

            private:
                libconfig::Config _cfg;
                RayTracer::Scene::Scene &_scene;
        };
    } // RayTracer

#endif //RAYTRACER_PARSER_HPP
