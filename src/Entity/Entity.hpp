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
            Entity();
            ~Entity() override;
    };
} // namespace RayTracer::Entity

#endif // RAYTRACER_ENTITY_HPP
