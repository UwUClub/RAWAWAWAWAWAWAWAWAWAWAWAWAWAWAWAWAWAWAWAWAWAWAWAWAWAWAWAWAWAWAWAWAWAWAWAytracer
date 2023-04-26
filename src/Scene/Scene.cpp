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

    void Scene::createPPM(const std::string &aFileName, const std::vector<Color> &aPixels, const int &aWidth, const int &aHeight)
    {
        std::ofstream myFile(aFileName);
        if (!myFile.is_open())
            throw SceneException("Cannot open file " + aFileName);
        myFile << "P3\n" << aWidth << " " << aHeight << "\n255\n";

        int myCol = 1;
        for (const auto &myPixel : aPixels) {
            myFile << std::setw(3) << myPixel._r << " ";
            myFile << std::setw(3) << myPixel._g << " ";
            myFile << std::setw(3) << myPixel._b;
            if (myCol == aWidth) {
                myFile << "\n";
                myCol = 0;
            } else {
                myFile << " ";
            }
            myCol++;
        }
        myFile.close();
    }
} // namespace RayTracer::Scene