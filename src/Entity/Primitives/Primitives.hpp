/*
** EPITECH PROJECT, 2023
** RAWAWAWAytracer
** File description:
** Primitives
*/

#include <optional>
#include "Entity.hpp"
#include "Ray.hpp"

#ifndef PRIMITIVES_HPP_
#define PRIMITIVES_HPP_

namespace RayTracer {
    namespace Entity {
        class Primitives : public Entity {
            public:
                Primitives(Color color);
                ~Primitives();
                virtual std::optional<double> isTouched(Ray ray);
                Color getColor();
            protected:
            private:
                Color _color;
};

    }
}

#endif /* !PRIMITIVES_HPP_ */
