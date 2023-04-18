/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** PointLight.hpp
*/

#ifndef RAYTRACER_POINTLIGHT_HPP
    #define RAYTRACER_POINTLIGHT_HPP

    #include "IEntity.hpp"
    #include "Vector.hpp"
    #include "Light.hpp"

    namespace RayTracer::Light {
        class PointLight : public Entity::IEntity, public Light {
        public:
        private:
            RayTracer::Vector _position;
            RayTracer::Vector _color;
        };
    } // RayTracer

#endif //RAYTRACER_POINTLIGHT_HPP
