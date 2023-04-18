/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Light.hpp
*/

#ifndef RAYTRACER_LIGHT_HPP
    #define RAYTRACER_LIGHT_HPP

    namespace RayTracer::Light {
        class Light {
            public:
                Light();
                virtual ~Light() = default;
            private:
                float _ambient;
                float _diffuse;
        };
    }

#endif //RAYTRACER_LIGHT_HPP
