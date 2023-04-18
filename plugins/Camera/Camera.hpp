/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Camera.hpp
*/

#ifndef RAYTRACER_CAMERA_HPP
    #define RAYTRACER_CAMERA_HPP

    #include "IEntity.hpp"
    #include "Vector.hpp"

    namespace RayTracer::Camera {
        class Camera : public Entity::IEntity {
        public:
            explicit Camera();
            ~Camera() override = default;

            void setPosition(const RayTracer::Vector &position);
            void setRotation(const RayTracer::Vector &rotation);
            void setResolution(const std::pair<int, int> &resolution);
            void setFieldOfView(float fov);
        private:
            std::pair<int, int> _resolution;
            RayTracer::Vector _position;
            RayTracer::Vector _rotation;
            float fieldOfView;
        };
    } // RayTracer

#endif //RAYTRACER_CAMERA_HPP
