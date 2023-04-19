//
// Created by patatofour on 17/04/23.
//

#ifndef RAYTRACER_ENTITY_HPP
#define RAYTRACER_ENTITY_HPP

#include "Utils/Point.hpp"
#include "Utils/Euler.hpp"
#include "IEntity.hpp"

namespace RayTracer::Entity
{
    /**
     * @brief The Entity class
     */
    class Entity : public IEntity
    {
        public:
            /**
             * @brief Construct a new Entity object
             * @param type The type of the entity
             */
            explicit Entity(EntityType type);
            ~Entity() override;

            /**
             * @brief Get the type of the entity
             * @return The type of the entity
             */
            [[nodiscard]] EntityType getType() const override;

            /**
             * @brief Get the position of the entity
             * @return The position of the entity
             */
            Point const &getPosition() override;

            /**
             * @brief Set the position of the entity
             * @param point The position of the entity
             */
            void setPosition(Point &point) override;

            /**
             * @brief Get the angle of the entity
             * @return The angle of the entity
             */
            Euler const &getAngle() override;

            /**
             * @brief Set the angle of the entity
             * @param angle The angle of the entity
             */
            void setAngle(Euler &angle) override;

            /**
             * @brief Translate the entity
             * @param vector The vector to translate the entity
             */
            void translate(Vector &vector) override;
            /**
             * @brief Rotate the entity
             * @param vector The vector to rotate the entity
             */
            void rotate(Euler &angle) override;

        private:
            EntityType _type;
            Point _position;
            Euler _angle;
    };
} // namespace RayTracer::Entity

#endif // RAYTRACER_ENTITY_HPP
