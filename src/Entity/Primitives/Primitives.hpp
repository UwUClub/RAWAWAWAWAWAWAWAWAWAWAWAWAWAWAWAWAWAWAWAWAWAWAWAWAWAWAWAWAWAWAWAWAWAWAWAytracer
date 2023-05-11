/*
** EPITECH PROJECT, 2023
** RAWAWAWAytracer
** File description:
** Primitives
*/

#ifndef PRIMITIVES_HPP_
#define PRIMITIVES_HPP_

#include "Entity.hpp"
#include "Ray.hpp"
#include <optional>

namespace RayTracer::Entity
{
    /**
     * @brief The base class for all primitives
     */
    class Primitives : public Entity
    {
        public:
            /**
             * @brief Construct a new Primitives object
             *
             * @param color The color of the primitive
             */
            Primitives(const Color &color);
            virtual ~Primitives() = default;

            std::optional<Color> getColor() override;
            void setColor(const Color &aColor);

        protected:
            Color _color;
    };

} // namespace RayTracer::Entity

#endif /* !PRIMITIVES_HPP_ */
