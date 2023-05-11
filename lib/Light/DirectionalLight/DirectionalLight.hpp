/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** DirectionalLight.hpp
*/

#ifndef RAYTRACER_DIRECTIONALLIGHT_HPP
#define RAYTRACER_DIRECTIONALLIGHT_HPP

#include "Entity.hpp"
#include "IEntity.hpp"
#include "Vector.hpp"

namespace RayTracer::Entity
{
    class DirectionalLight : public Entity
    {
        public:
            explicit DirectionalLight(const DataEntityMap &aDataMap);
            ~DirectionalLight() override = default;

            void setDirection(const Vector &aDirection);

        private:
            RayTracer::Vector _direction;
    };
} // namespace RayTracer::Entity

#endif // RAYTRACER_DIRECTIONALLIGHT_HPP
