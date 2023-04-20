//
// Created by patatofour on 17/04/23.
//

#ifndef RAYTRACER_IENTITY_HPP
#define RAYTRACER_IENTITY_HPP

#include "Point.hpp"
#include "Vector.hpp"
#include <memory>
#include <unordered_map>
#include <vector>

namespace RayTracer::Entity
{
    /**
     * @brief The EntityType enum
     */
    enum class EntityType {
        PRIMITIVE,
        LIGHT,
        CAMERA,
        SKYBOX,
        COLOR,
        UNDEFINED
    };

    /**
     * @brief The IEntity Interface
     */
    class IEntity
    {
        public:
            virtual ~IEntity() = default;

            /**
             * @brief Get the type of the entity
             */
            [[nodiscard]] virtual EntityType getType() const = 0;

            // virtual Color intersect(Scene &scene, Ray &viewRay) const = 0;

            /**
             * @brief Get the position of the entity
             */
            virtual const Point &getPosition() = 0;

            /**
             * @brief Set the position of the entity
             * @param point The position of the entity
             */
            virtual void setPosition(const Point &aPoint) = 0;

            /**
             * @brief Translate the entity
             * @param vector The vector to translate the entity
             */
            virtual void translate(const Vector &aVector) = 0;
            /**
             * @brief Rotate the entity
             * @param vector The vector to rotate the entity
             */
            virtual void rotate(const Vector &aVector) = 0;
    };

    using IEntityPtr = std::unique_ptr<IEntity>;
    using IEntityVector = std::vector<IEntityPtr>;
    using IEntityMap = std::unordered_map<std::string, IEntityVector>;
    using DataEntityMap = std::unordered_map<std::string, double>;
} // namespace RayTracer::Entity

#endif // RAYTRACER_IENTITY_HPP
