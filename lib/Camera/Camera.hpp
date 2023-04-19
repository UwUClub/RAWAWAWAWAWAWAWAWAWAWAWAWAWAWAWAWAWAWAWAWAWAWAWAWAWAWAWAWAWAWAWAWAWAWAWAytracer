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

    namespace RayTracer {
        class Camera : public Entity::IEntity {
        public:
            explicit Camera();
            ~Camera() override = default;

            void setPosition(Point &position) override;
            void setRotation(const RayTracer::Vector &rotation);
            void setResolution(const std::pair<int, int> &resolution);
            void setFieldOfView(float fov);
            [[nodiscard]] Entity::EntityType getType() const override { return Entity::EntityType::CAMERA; };
            void translate(Vector &vector) override;
            void rotate(Vector &vector) override;
            const RayTracer::Point &getPosition() override { return _position; };

        private:
            std::pair<int, int> _resolution;
            RayTracer::Point _position;
            RayTracer::Vector _rotation;
            float fieldOfView;
        };
    } // RayTracer

#endif //RAYTRACER_CAMERA_HPP
