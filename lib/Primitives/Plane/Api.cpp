/*
** EPITECH PROJECT, 2023
** RAWAWAWAytracer
** File description:
** Api
*/

#include "Api.hpp"
#include "Plane.hpp"

extern "C" {
    RayTracer::Entity::IEntity *createEntity(const std::unordered_map<std::string, double> &dataMap)
    {
        return new RayTracer::Entity::Plane(dataMap);
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