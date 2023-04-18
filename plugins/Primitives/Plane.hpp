//
// Created by beafowl on 18/04/23.
//

#ifndef RAYTRACER_PLANE_HPP
    #define RAYTRACER_PLANE_HPP

    #include "IEntity.hpp"
    #include "Vector.hpp"

    namespace RayTracer::Primitives {
        class Plane : public Entity::IEntity {
        public:
            explicit Plane();
            ~Plane() override = default;

            void setPosition(int position);
            void setAxis(const std::string &axis);
            void setColor(const RayTracer::Vector &color);

            [[nodiscard]] Entity::EntityType getType() const override;
            void rotate(Vector &vector) override;
            void translate(Vector &vector) override;
        private:
            char _axis;
            int _position;
            RayTracer::Vector _color;
        };
    }

#endif //RAYTRACER_PLANE_HPP
