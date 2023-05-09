//
// Created by patatofour on 17/04/23.
//

#ifndef RAYTRACER_ENTITY_HPP
#define RAYTRACER_ENTITY_HPP

#include "IEntity.hpp"

namespace RayTracer::Entity
{
    class IEntity;

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
            Vector const &getRotation() override;

            /**
             * @brief Set the aAngle of the entity
             * @param aRotation The new rotation of the entity
             */
            void setRotation(const Vector &aRotation) override;

            /**
             * @brief Translate the entity
             * @param vector The vector to translate the entity
             */
            void translate(const Vector &aVector) override;
            /**
             * @brief Rotate the entity
             * @param aRotation The vector to rotate the entity
             */
            void rotate(const Vector &aRotation) override;
            /**
             * @brief Check if the ray touched the entity
             *
             * @param ray The ray to check
             * @return std::optional<double> The distance between the origin of the ray and the entity
             */
            std::optional<double> isTouched(const Ray &ray) override;
            /**
             * @brief Get the Casted Rays object
             * @return std::vector<Ray>& The casted rays
            */
            std::vector<Ray> getCastedRays() const override;
            std::optional<Color> getColor() override;
            std::pair<int, int> getResolution() const override;

        protected:
            EntityType _type;
            Point _position;
            Vector _rotation;
    };
} // namespace RayTracer::Entity

#endif // RAYTRACER_ENTITY_HPP
