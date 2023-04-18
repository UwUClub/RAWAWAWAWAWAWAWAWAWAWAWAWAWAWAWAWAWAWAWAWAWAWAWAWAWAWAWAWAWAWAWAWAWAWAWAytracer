/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Sphere.hpp
*/

#ifndef RAYTRACER_SPHERE_HPP
    #define RAYTRACER_SPHERE_HPP

    #include "IEntity.hpp"
    #include "Vector.hpp"

    namespace RayTracer::Primitives {
        class Sphere : public Entity::IEntity {
        public:
            explicit Sphere();
            ~Sphere() override = default;

            void setPosition(const RayTracer::Vector &position);
            void setRadius(int radius);
            void setColor(const RayTracer::Vector &color);

            [[nodiscard]] Entity::EntityType getType() const override;
            void rotate(Vector &vector) override;
            void translate(Vector &vector) override;
        private:
            RayTracer::Vector _position;
            int _radius;
            RayTracer::Vector _color;
        };
    }
    
#endif //RAYTRACER_SPHERE_HPP
