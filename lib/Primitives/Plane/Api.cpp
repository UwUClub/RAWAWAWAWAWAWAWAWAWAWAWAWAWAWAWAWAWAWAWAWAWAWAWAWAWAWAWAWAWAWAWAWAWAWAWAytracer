//
// Created by beafowl on 20/04/23.
//

#include "Plane.hpp"

extern "C" {
    RayTracer::Entity::Entity *createEntity(RayTracer::Entity::DataEntityMap &aData)
    {
        return new RayTracer::Primitives::Plane(aData);
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