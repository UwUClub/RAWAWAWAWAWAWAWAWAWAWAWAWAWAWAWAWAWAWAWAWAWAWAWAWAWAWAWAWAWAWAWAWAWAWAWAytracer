/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Camera.hpp
*/

#ifndef RAYTRACER_CAMERA_HPP
    #define RAYTRACER_CAMERA_HPP

    #include <utility>
    #include "Entity.hpp"
    #include "Vector.hpp"
    #include "Point.hpp"
    #include <cstdint>

namespace RayTracer::Entity {
        class Camera : public Entity::Entity {
        public:
            explicit Camera();
            ~Camera() = default;

            void setRotation(const Vector &rotation);
            void setResolution(const std::pair<int, int> &resolution);
            void setFieldOfView(float fov);

        private:
            std::pair<int, int> _resolution;
            RayTracer::Vector _rotation;
            float fieldOfView;
        };
    } // RayTracer

#endif //RAYTRACER_CAMERA_HPP
