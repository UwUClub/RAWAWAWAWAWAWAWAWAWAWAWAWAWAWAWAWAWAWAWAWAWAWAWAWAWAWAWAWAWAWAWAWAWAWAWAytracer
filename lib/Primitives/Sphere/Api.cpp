//
// Created by beafowl on 20/04/23.
//

#include "Sphere.hpp"

extern "C" {
    RayTracer::Entity::Entity *createEntity(RayTracer::Entity::DataEntityMap &aData)
    {
        return new RayTracer::Primitives::Sphere(aData);
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
