/*
** EPITECH PROJECT, 2023
** RAWAWAWAytracer
** File description:
** Ray
*/

#ifndef RAY_HPP_
#define RAY_HPP_

#include <optional>
#include "Color.hpp"
#include "Point.hpp"
#include "Vector.hpp"
#include <memory>
#include <unordered_map>
#include <vector>

namespace RayTracer
{
    class HitPoint;

    namespace Entity {
        class IEntity;
    }

    struct Ray {
        public:
            /**
             * @brief Construct a new Ray object
             *
             * @param origin The origin of the ray
             * @param direction The direction of the ray
             */
            Ray(const Point aOrigin, const Vector aDirection);
            /**
             * @brief Destroy the Ray object
             *
             */
            ~Ray();
            /**
             * @brief Get the closest hit of the ray
             *
             * @param entities The entities to check
             * @return Color The color of the closest hit
             */
            std::optional<HitPoint> getClosestHit(const std::unordered_map<std::string, std::vector<std::unique_ptr<Entity::IEntity>>> &aEntities) const;

            /**
             * @brief The origin of the ray
             */
            Point _origin;
            /**
             * @brief The direction of the ray
             */
            Vector _direction;
    };
} // namespace RayTracer

#endif /* !RAY_HPP_ */
