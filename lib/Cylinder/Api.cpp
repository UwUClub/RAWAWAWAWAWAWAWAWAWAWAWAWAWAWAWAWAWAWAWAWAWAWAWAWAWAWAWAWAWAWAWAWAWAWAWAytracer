/*
** EPITECH PROJECT, 2023
** RAWAWAWAytracer
** File description:
** Api
*/

#include "Api.hpp"
#include "Cylinder.hpp"

extern "C" {
    RayTracer::Entity::IEntity *createEntity(RayTracer::Entity::Color &aColor, RayTracer::Point &aCenter, double aRadius, double aHeight)
    {
        return new RayTracer::Entity::Cylinder(aColor, aCenter, aRadius, aHeight);
    }
    
    void destroyEntity(RayTracer::Entity::IEntity *aEntity)
    {
        delete aEntity;
    }
    
    const char *getName()
    {
        return "Cylinder";
    }
}