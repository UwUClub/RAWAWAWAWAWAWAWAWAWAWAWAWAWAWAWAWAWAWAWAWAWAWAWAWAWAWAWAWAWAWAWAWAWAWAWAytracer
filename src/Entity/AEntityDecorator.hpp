//
// Created by patatofour on 17/04/23.
//

#ifndef RAYTRACER_AENTITYDECORATOR_HPP
#define RAYTRACER_AENTITYDECORATOR_HPP

#include "IEntity.hpp"

namespace RayTracer::Entity
{
    class AEntityDecorator : public IEntity
    {
        public:
            AEntityDecorator(IEntityPtr entity);
            ~AEntityDecorator() override = default;

        protected:
            IEntityPtr _entity;
    };
} // namespace RayTracer::Entity

#endif // RAYTRACER_AENTITYDECORATOR_HPP
