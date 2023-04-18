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
        private:
            char _axis;
            int _position;
            RayTracer::Vector _color;
        };
    }

#endif //RAYTRACER_PLANE_HPP
