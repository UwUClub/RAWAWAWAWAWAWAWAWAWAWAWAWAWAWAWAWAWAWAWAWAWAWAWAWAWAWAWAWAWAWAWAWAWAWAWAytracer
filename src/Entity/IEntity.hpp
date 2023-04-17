//
// Created by patatofour on 17/04/23.
//

#ifndef RAYTRACER_IENTITY_HPP
#define RAYTRACER_IENTITY_HPP

#include "Vector.hpp"
#include <memory>
#include <unordered_map>
#include <vector>

namespace RayTracer::Entity
{
    enum class EntityType {
        PRIMITIVE,
        LIGHT,
        CAMERA,
        SKYBOX,
        UNDEFINED
    };

    class IEntity
    {
        public:
            virtual ~IEntity() = default;

            [[nodiscard]] virtual EntityType getType() const = 0;

            // virtual Color intersect(Scene &scene, Ray &viewRay) const = 0;

            virtual void translate(Vector &vector) = 0;
            virtual void rotate(Vector &vector) = 0;
    };

    using IEntityPtr = std::unique_ptr<IEntity>;
    using IEntityVector = std::vector<IEntityPtr>;
    using IEntityMap = std::unordered_map<std::string, IEntityVector>;
} // namespace RayTracer::Entity

#endif // RAYTRACER_IENTITY_HPP
