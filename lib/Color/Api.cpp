//
// Created by patatofour on 17/04/23.
//

#include "Api.hpp"
#include "Color.hpp"

extern "C" {
RayTracer::Entity::IEntity *createEntity(RayTracer::Entity::DataEntityMap &aData)
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
