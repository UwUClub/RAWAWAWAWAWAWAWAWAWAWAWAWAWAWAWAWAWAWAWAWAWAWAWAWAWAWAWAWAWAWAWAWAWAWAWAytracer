/*
** EPITECH PROJECT, 2023
** RAWAWAWAytracer
** File description:
** Api
*/

#include "Api.hpp"
#include "Plane.hpp"

extern "C" {
    RayTracer::Entity::IEntity *createEntity(double aPos, std::string aAxis, RayTracer::Entity::Color &aColor)
    {
        return new RayTracer::Entity::Plane(aPos, aAxis, aColor);
    }
    
    void destroyEntity(RayTracer::Entity::IEntity *aEntity)
    {
        delete aEntity;
    }
    
    const char *getName()
    {
        return "Plane";
    }
}