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
            explicit AEntityDecorator(IEntityPtr entity);
            ~AEntityDecorator() override = default;

            [[nodiscard]] EntityType getType() const override;

            void translate(Vector &vector) override;
            void rotate(Vector &vector) override;

        protected:
            IEntityPtr _entity;
    };
} // namespace RayTracer::Entity

#endif // RAYTRACER_AENTITYDECORATOR_HPP
