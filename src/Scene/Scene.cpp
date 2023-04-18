//
// Created by patatofour on 18/04/23.
//

#include "Scene.hpp"

namespace RayTracer::Scene
{
    void Scene::addEntity(const std::string &name, Entity::IEntityPtr &entity)
    {
        _entities[name].push_back(std::move(entity));
    }
    
    Entity::IEntityMap &Scene::getEntities()
    {
        return _entities;
    }

    Entity::IEntityPtr &Scene::getCamera()
    {
        if (_entities["Camera"].empty())
            throw SceneException("No camera in the scene");
        return _entities["Camera"][0];
    }

    Entity::IEntityVector &Scene::getLights()
    {
        if (_entities["Light"].empty())
            throw SceneException("No light in the scene");
        return _entities["Light"];
    }

} // namespace RayTracer::Scene