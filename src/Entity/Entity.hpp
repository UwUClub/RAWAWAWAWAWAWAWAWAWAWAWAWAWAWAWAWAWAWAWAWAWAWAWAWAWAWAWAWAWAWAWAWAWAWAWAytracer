//
// Created by patatofour on 17/04/23.
//

#ifndef RAYTRACER_ENTITY_HPP
#define RAYTRACER_ENTITY_HPP

#include "Utils/Point.hpp"
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
            explicit Entity(EntityType type, Point position);
            ~Entity() override;

            /**
             * @brief Get the type of the entity
             * @return The type of the entity
             */
            [[nodiscard]] EntityType getType() const override;

            /**
             * @brief Translate the entity
             * @param vector The vector to translate the entity
             */
            void translate(Vector &vector) override;
            /**
             * @brief Rotate the entity
             * @param vector The vector to rotate the entity
             */
            void rotate(Vector &vector) override {};

        private:
            EntityType _type;
            Point _position;
    };
} // namespace RayTracer::Entity

#endif // RAYTRACER_ENTITY_HPP
