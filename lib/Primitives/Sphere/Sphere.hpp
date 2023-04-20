/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Sphere.hpp
*/

#ifndef RAYTRACER_SPHERE_HPP
    #define RAYTRACER_SPHERE_HPP

    #include "Entity.hpp"
    #include "Vector.hpp"

    namespace RayTracer::Primitives {
        class Sphere : public Entity::Entity {
        public:
            explicit Sphere();
            ~Sphere() override = default;

            void setRadius(int radius);
            void setColor(const RayTracer::Vector &color);
        private:
            RayTracer::Point _position;
            int _radius;
            RayTracer::Vector _color;
        };
    }
    
#endif //RAYTRACER_SPHERE_HPP
