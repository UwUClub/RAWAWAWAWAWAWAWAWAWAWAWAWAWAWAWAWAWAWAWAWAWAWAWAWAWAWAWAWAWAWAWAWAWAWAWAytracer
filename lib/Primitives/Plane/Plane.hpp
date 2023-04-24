/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Plane.hpp
*/

#ifndef RAYTRACER_PLANE_HPP
    #define RAYTRACER_PLANE_HPP

    #include "Entity.hpp"
    #include "Vector.hpp"

    namespace RayTracer::Primitives {
        class Plane : public Entity::Entity {
        public:
            explicit Plane();
            ~Plane() override = default;

            void setAxis(const std::string &aAxis);
            void setColor(const RayTracer::Vector &aColor);

        private:
            char _axis;
            RayTracer::Point _position;
            RayTracer::Vector _color;
        };
    }

#endif //RAYTRACER_PLANE_HPP
