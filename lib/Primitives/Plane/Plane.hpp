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
            explicit Plane(const std::unordered_map<std::string, double> &dataMap);
            ~Plane() override = default;

            void setAxis(const std::string &axis);
            void setColor(const RayTracer::Vector &color);

        private:
            char _axis;
            RayTracer::Point _position;
            RayTracer::Vector _color;
        };
    }

#endif //RAYTRACER_PLANE_HPP
