//
// Created by patatofour on 18/04/23.
//

#include "Scene.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>

namespace RayTracer::Scene
{
    Scene::Scene(Plugin::PluginManager &aPluginManager)
        : _pluginManager(aPluginManager)
    {
    }

    Scene::~Scene()
    {
        _pluginManager.deleteEntities(_entities);
    }

    void Scene::addEntity(const std::string &aName, Entity::IEntityPtr &aEntity)
    {
        _entities[aName].push_back(std::move(aEntity));
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

    void Scene::createPPM(const std::string &aFileName, const std::vector<Color> &aPixels, const int aWidth, const int aHeight)
    {
        std::ofstream file(aFileName);
        if (!file.is_open())
            throw SceneException("Cannot open file " + aFileName);
        file << "P3\n" << aWidth << " " << aHeight << "\n255\n";

        int col = 1;
        for (const auto &pixel : aPixels) {
            file << std::setw(3) << pixel._r << " ";
            file << std::setw(3) << pixel._g << " ";
            file << std::setw(3) << pixel._b;
            if (col == aWidth) {
                file << "\n";
                col = 0;
            } else {
                file << " ";
            }
            col++;
        }
        file.close();
    }
} // namespace RayTracer::Scene