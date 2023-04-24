//
// Created by patatofour on 17/04/23.
//

#include "Camera.hpp"

extern "C" {
    RayTracer::Entity::Entity *createEntity(RayTracer::Entity::DataEntityMap &aData)
    {
        return new RayTracer::Entity::Camera(aData);
    }

    void destroyEntity(RayTracer::Entity::IEntity *aEntity)
    {
        delete aEntity;
    }

    const char *getName()
    {
        return "Camera";
    }
}
