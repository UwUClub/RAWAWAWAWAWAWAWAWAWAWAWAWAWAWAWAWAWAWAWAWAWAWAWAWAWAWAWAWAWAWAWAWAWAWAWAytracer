/*
** EPITECH PROJECT, 2023
** RAWAWAWAytracer
** File description:
** Sphere
*/

#include "../src/Entity/Primitives/Primitives.hpp"

#ifndef SPHERE_HPP_
#define SPHERE_HPP_

namespace RayTracer {
    namespace Entity {
        class Sphere : public Primitives {
            public:
                Sphere(const std::unordered_map<std::string, double> &dataMap);
                ~Sphere();
                std::optional<double> isTouched(Ray ray) override;
            protected:
            private:
                Point _center;
                double _radius;
        };
    } // namespace Entity
} // namespace RayTracer

#endif /* !SPHERE_HPP_ */
