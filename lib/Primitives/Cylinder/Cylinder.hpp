/*
** EPITECH PROJECT, 2023
** RAWAWAWAytracer
** File description:
** Cylinder
*/

#ifndef CYLINDER_HPP_
#define CYLINDER_HPP_

#include "IEntity.hpp"
#include "Primitives.hpp"

namespace RayTracer::Entity
{
    class Cylinder : public Primitives
    {
        public:
            Cylinder(const DataEntityMap &aDataMap);
            ~Cylinder() override = default;
            std::optional<double> isTouched(const Ray &aRay) override;
            Vector getNormal(const Point &aPoint) override;

        protected:
        private:
            Point _center;
            double _radius;
            double _height;
    };
}; // namespace RayTracer::Entity

#endif /* !CYLINDER_HPP_ */
