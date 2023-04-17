//
// Created by patatofour on 17/04/23.
//

#ifndef RAYTRACER_ENTITY_HPP
#define RAYTRACER_ENTITY_HPP

#include "IEntity.hpp"

namespace RayTracer::Entity
{
    class Entity : public IEntity
    {
        public:
            explicit Entity(EntityType type);
            ~Entity() override;

            [[nodiscard]] EntityType getType() const override;

        private:
            EntityType _type;
    };
} // namespace RayTracer::Entity

#endif // RAYTRACER_ENTITY_HPP
