//
// Created by patatofour on 17/04/23.
//

#ifndef RAYTRACER_IENTITY_HPP
#define RAYTRACER_IENTITY_HPP

#include "Point.hpp"
#include "Vector.hpp"
#include "Ray.hpp"
#include <memory>
#include <unordered_map>
#include <vector>

namespace RayTracer
{
    struct Ray;
}

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
            virtual Point const &getPosition() = 0;

            /**
             * @brief Set the position of the entity
             * @param point The position of the entity
             */
            virtual void setPosition(const Point &aPoint) = 0;

            /**
             * @brief Get the rotation of the entity
             */
            virtual Vector const &getRotation() = 0;

            /**
             * @brief Set the aAngle of the entity
             * @param aAngle The aAngle of the entity
             */
            virtual void setRotation(const Vector &aRotation) = 0;

            /**
             * @brief Translate the entity
             * @param vector The vector to translate the entity
             */
            virtual void translate(const Vector &aVector) = 0;
            /**
             * @brief Rotate the entity
             * @param aRotation the vector applied to rotate the entity
             */
            virtual void rotate(const Vector &aRotation) = 0;
            /**
             * @brief Check if the ray touched the entity
             *
             * @param ray The ray to check
             * @return std::optional<double> The distance between the origin of the ray and the entity
             */
            virtual std::optional<double> isTouched(const Ray &ray) = 0;
            /**
             * @brief Get the Casted Rays object
             * @return std::vector<Ray>& The casted rays
            */
            virtual std::vector<Ray> getCastedRays() const = 0;
            virtual std::optional<Color> getColor() = 0;
            virtual double getAmbient() const = 0;
            virtual double getDiffuse() const = 0;
            virtual Vector getNormal(const Point &aPoint) = 0;
    };

    using IEntityPtr = std::unique_ptr<IEntity>;
    using IEntityVector = std::vector<IEntityPtr>;
    using IEntityMap = std::unordered_map<std::string, IEntityVector>;
    using DataEntityMap = std::unordered_map<std::string, double>;
} // namespace RayTracer::Entity

#endif // RAYTRACER_IENTITY_HPP
