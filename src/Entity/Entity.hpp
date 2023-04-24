//
// Created by patatofour on 17/04/23.
//

#ifndef RAYTRACER_ENTITY_HPP
#define RAYTRACER_ENTITY_HPP

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
            explicit Entity(EntityType aType);
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
            void setPosition(const Point &aPoint) override;

            /**
             * @brief Get the angle of the entity
             * @return The angle of the entity
             */
            Euler const &getAngle() override;

            /**
             * @brief Set the aAngle of the entity
             * @param aAngle The aAngle of the entity
             */
            void setAngle(const Euler &aAngle) override;

            /**
             * @brief Translate the entity
             * @param vector The vector to translate the entity
             */
            void translate(const Vector &aVector) override;
            /**
             * @brief Rotate the entity
             * @param aAngle The vector to rotate the entity
             */
            void rotate(const Euler &aAngle) override;

        private:
            EntityType _type;
            Point _position;
            Euler _angle;
    };
} // namespace RayTracer::Entity

#endif // RAYTRACER_ENTITY_HPP
