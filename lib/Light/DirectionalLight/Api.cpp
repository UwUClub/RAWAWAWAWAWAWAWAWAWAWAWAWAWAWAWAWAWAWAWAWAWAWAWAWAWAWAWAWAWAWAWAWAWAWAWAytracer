//
// Created by patatofour on 17/04/23.
//

#include "DirectionalLight.hpp"

extern "C" {
    RayTracer::Entity::IEntity *createEntity(RayTracer::Entity::DataEntityMap &aData)
    {
        return new RayTracer::Entity::DirectionalLight(aData);
    }

    void destroyEntity(RayTracer::Entity::IEntity *aEntity)
    {
        delete aEntity;
    }

    const char *getName()
    {
        return "DirectionalLight";
    }
}
