/*
** EPITECH PROJECT, 2023
** RAWAWAWAytracer
** File description:
** Cylinder
*/

#include "../src/Entity/Primitives/Primitives.hpp"

#ifndef CYLINDER_HPP_
#define CYLINDER_HPP_

namespace RayTracer {
    namespace Entity {
        class Cylinder : public Primitives {
            public:
                Cylinder(Color color, Point center, double radius, double height);
                ~Cylinder();
                std::optional<double> isTouched(Ray ray) override;
            protected:
            private:
                Point _center;
                double _radius;
                double _height;
        };
    }
};

#endif /* !CYLINDER_HPP_ */
