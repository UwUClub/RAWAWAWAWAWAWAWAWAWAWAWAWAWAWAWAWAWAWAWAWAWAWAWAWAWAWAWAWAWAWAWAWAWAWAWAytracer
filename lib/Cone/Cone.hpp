/*
** EPITECH PROJECT, 2023
** RAWAWAWAytracer
** File description:
** Cone
*/

#include "../src/Entity/Primitives/Primitives.hpp"

#ifndef CONE_HPP_
#define CONE_HPP_

namespace RayTracer {
    namespace Entity {
        class Cone : public Primitives {
            public:
                Cone(Color color, Point center, double radius, double height);
                ~Cone();
                std::optional<double> isTouched(Ray ray) override;
            protected:
            private:
                Point _center;
                double _radius;
                double _height;
        };
    }
};

#endif /* !CONE_HPP_ */
