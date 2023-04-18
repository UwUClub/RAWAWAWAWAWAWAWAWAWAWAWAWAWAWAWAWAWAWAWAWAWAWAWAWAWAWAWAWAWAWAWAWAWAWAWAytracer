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
        private:
            std::pair<int, int> _resolution;
            RayTracer::Vector _position;
            RayTracer::Vector _rotation;
            int fieldOfView;
        };
    } // RayTracer

#endif //RAYTRACER_CAMERA_HPP
