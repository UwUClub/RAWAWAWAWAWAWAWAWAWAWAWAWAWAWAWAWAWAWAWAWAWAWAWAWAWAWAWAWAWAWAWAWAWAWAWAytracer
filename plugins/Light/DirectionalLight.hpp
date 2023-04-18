//
// Created by beafowl on 18/04/23.
//

#ifndef RAYTRACER_DIRECTIONALLIGHT_HPP
    #define RAYTRACER_DIRECTIONALLIGHT_HPP

    #include "IEntity.hpp"
    #include "Vector.hpp"
    #include "Light.hpp"

    namespace RayTracer::Light {
        class DirectionalLight : public Entity::IEntity, public Light {
        private:
            RayTracer::Vector _direction;
        };
    }

#endif //RAYTRACER_DIRECTIONALLIGHT_HPP
