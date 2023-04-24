/*
** EPITECH PROJECT, 2023
** RAWAWAWAytracer
** File description:
** Api
*/

#include "Api.hpp"
#include "Sphere.hpp"

extern "C" {
    RayTracer::Entity::IEntity *createEntity(RayTracer::Point &aCenter, double aRadius, RayTracer::Entity::Color &aColor)
    {
        return new RayTracer::Entity::Sphere(aCenter, aRadius, aColor);
    }
    
    void destroyEntity(RayTracer::Entity::IEntity *aEntity)
    {
        delete aEntity;
    }
    
    const char *getName()
    {
        return "Sphere";
    }
}

