/*
** EPITECH PROJECT, 2023
** RAWAWAWAytracer
** File description:
** Sphere
*/

#include "IEntity.hpp"
#include "Primitives.hpp"

#ifndef SPHERE_HPP_
#define SPHERE_HPP_

namespace RayTracer::Entity
{
    class Sphere : public Primitives
    {
        public:
            Sphere(const DataEntityMap &dataMap);
            ~Sphere() override = default;
            std::optional<double> isTouched(const Ray &ray) override;

        protected:
        private:
            Point _center;
            double _radius;
    };
} // namespace RayTracer::Entity

#endif /* !SPHERE_HPP_ */
