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
            explicit PointLight();
            ~PointLight() override = default;

            void setPosition(Point &point) override;
            [[nodiscard]] Entity::EntityType getType() const override;
            void rotate(Vector &vector) override;
            void translate(Vector &vector) override;
            const RayTracer::Point &getPosition() override { return _position; };
        private:
            Point _position;
        };
    } // RayTracer

#endif //RAYTRACER_POINTLIGHT_HPP
