/*
** EPITECH PROJECT, 2023
** RAWAWAWAytracer
** File description:
** Api
*/

#include "Api.hpp"
#include "Cone.hpp"

extern "C" {
    RayTracer::Entity::IEntity *createEntity(RayTracer::Entity::Color &aColor, RayTracer::Point &aCenter, double aRadius, double aHeight)
    {
        return new RayTracer::Entity::Cone(aColor, aCenter, aRadius, aHeight);
    }
    
    void destroyEntity(RayTracer::Entity::IEntity *aEntity)
    {
        delete aEntity;
    }
    
    const char *getName()
    {
        return "Cone";
    }
}