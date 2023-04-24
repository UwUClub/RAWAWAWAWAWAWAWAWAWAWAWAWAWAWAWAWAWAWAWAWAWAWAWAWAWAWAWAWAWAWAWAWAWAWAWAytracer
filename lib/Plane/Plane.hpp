/*
** EPITECH PROJECT, 2023
** RAWAWAWAytracer
** File description:
** Plane
*/

#include "../src/Entity/Primitives/Primitives.hpp"

#ifndef PLANE_HPP_
#define PLANE_HPP_

namespace RayTracer {
    namespace Entity {
        class Plane : public Primitives {
            public:
                Plane(double pos, std::string axis, Color color);
                ~Plane();
                std::optional<double> isTouched(Ray ray) override;
            protected:
            private:
                Point _center;
                Vector _normal;
            };
    }
};


#endif /* !PLANE_HPP_ */
