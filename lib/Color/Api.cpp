//
// Created by patatofour on 17/04/23.
//

#include "Color.hpp"
#include <iostream>

extern "C" {
RayTracer::Entity::IEntity *createEntity()
{
    return new RayTracer::Entity::Color(255, 255, 255, 255);
}

void destroyEntity(RayTracer::Entity::IEntity *aEntity)
{
    delete aEntity;
}

const char *getName()
{
    return "Color";
}
}
