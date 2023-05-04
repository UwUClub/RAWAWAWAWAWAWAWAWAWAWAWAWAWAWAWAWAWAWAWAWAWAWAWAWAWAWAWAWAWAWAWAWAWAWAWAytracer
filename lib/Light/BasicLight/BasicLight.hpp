/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** PointLight.hpp
*/

#ifndef RAYTRACER_BASICLIGHT_HPP
#define RAYTRACER_BASICLIGHT_HPP

#include "Entity.hpp"
#include "Vector.hpp"

namespace RayTracer::Entity
{
    class BasicLight : public Entity
    {
        public:
            explicit BasicLight(const DataEntityMap &aDataMap);
            ~BasicLight() override = default;

        private:
            double _ambient;
            double _diffuse;
    };
} // namespace RayTracer::Entity

#endif // RAYTRACER_BASICLIGHT_HPP
