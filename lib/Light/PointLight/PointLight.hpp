/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** PointLight.hpp
*/

#ifndef RAYTRACER_POINTLIGHT_HPP
#define RAYTRACER_POINTLIGHT_HPP

#include "Entity.hpp"
#include "IEntity.hpp"
#include "Vector.hpp"

namespace RayTracer::Entity
{
    class PointLight : public Entity
    {
        public:
            explicit PointLight(const DataEntityMap &aDataMap);
            ~PointLight() override = default;

        private:
            Point _position;
    };
} // namespace RayTracer::Entity

#endif // RAYTRACER_POINTLIGHT_HPP
