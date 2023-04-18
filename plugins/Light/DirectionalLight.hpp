/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** DirectionalLight.hpp
*/

#ifndef RAYTRACER_DIRECTIONALLIGHT_HPP
    #define RAYTRACER_DIRECTIONALLIGHT_HPP

    #include "IEntity.hpp"
    #include "Vector.hpp"
    #include "Light.hpp"

    namespace RayTracer::Light {
        class DirectionalLight : public Entity::IEntity, public Light {
        private:
            RayTracer::Vector _direction;
        };
    }

#endif //RAYTRACER_DIRECTIONALLIGHT_HPP
