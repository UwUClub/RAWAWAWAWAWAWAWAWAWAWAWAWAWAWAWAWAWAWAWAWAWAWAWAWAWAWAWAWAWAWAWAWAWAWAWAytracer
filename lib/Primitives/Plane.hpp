/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Plane.hpp
*/

#ifndef RAYTRACER_PLANE_HPP
    #define RAYTRACER_PLANE_HPP

    #include "IEntity.hpp"
    #include "Vector.hpp"

    namespace RayTracer::Primitives {
        class Plane : public Entity::IEntity {
        public:
            explicit Plane();
            ~Plane() override = default;

            void setPosition(const Point &position) override;
            void setAxis(const std::string &axis);
            void setColor(const RayTracer::Vector &color);

            [[nodiscard]] Entity::EntityType getType() const override;
            void rotate(const Vector &vector) override;
            void translate(const Vector &vector) override;
            const Point &getPosition() override { return _position; };
        private:
            char _axis;
            RayTracer::Point _position;
            RayTracer::Vector _color;
        };
    }

#endif //RAYTRACER_PLANE_HPP
