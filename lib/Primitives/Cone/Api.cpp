/*
** EPITECH PROJECT, 2023
** RAWAWAWAytracer
** File description:
** Api
*/

#include "Cone.hpp"

extern "C" {
    RayTracer::Entity::IEntity *createEntity(const std::unordered_map<std::string, double> &dataMap)
    {
        return new RayTracer::Entity::Cone(dataMap);
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