/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** PointLight.hpp
*/

#ifndef RAYTRACER_POINTLIGHT_HPP
    #define RAYTRACER_POINTLIGHT_HPP

    #include "Entity.hpp"
    #include "Vector.hpp"

    namespace RayTracer::Entity {
        class PointLight : public Entity {
        public:
            explicit PointLight();
            ~PointLight() override = default;

        private:
            Point _position;
        };
    } // RayTracer

#endif //RAYTRACER_POINTLIGHT_HPP
