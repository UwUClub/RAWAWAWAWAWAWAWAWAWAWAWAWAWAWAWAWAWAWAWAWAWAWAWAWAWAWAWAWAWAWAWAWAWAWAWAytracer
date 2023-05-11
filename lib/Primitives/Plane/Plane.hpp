/*
** EPITECH PROJECT, 2023
** RAWAWAWAytracer
** File description:
** Plane
*/

#ifndef PLANE_HPP_
#define PLANE_HPP_

#include "IEntity.hpp"
#include "Primitives.hpp"

namespace RayTracer
{
    namespace Entity
    {
        class Plane : public Primitives
        {
            public:
                Plane(const DataEntityMap &aDataMap);
                ~Plane() override = default;
                std::optional<double> isTouched(const Ray &aRay) override;
                Vector getNormal(const Point &aPoint) override;
            protected:
            private:
                Point _center;
                Vector _normal;
        };
    } // namespace Entity
};    // namespace RayTracer

#endif /* !PLANE_HPP_ */
