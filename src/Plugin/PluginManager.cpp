//
// Created by patatofour on 17/04/23.
//

#include "PluginManager.hpp"
#include <filesystem>
#include <iostream>

namespace RayTracer::Plugin
{
    PluginManager::PluginManager()
    {
        for (const auto &myEntry : std::filesystem::recursive_directory_iterator("./plugins")) {
            if (myEntry.path().string().find(".so") != std::string::npos) {
                loadPlugin(myEntry.path());
            }
        }
    }

    PluginManager::~PluginManager()
    {
        auto myEntities = Entity::IEntityMap();

        for (auto &myPlugin : _pluginsMap)
            unloadPlugin(myPlugin.first, myEntities);
    }

    void PluginManager::loadPlugin(const std::string &aPath)
    {
        try {
            auto myPlugin = std::make_unique<Plugin>(aPath);
            auto &aName = myPlugin->getName();

            if (_pluginsMap.find(aName) != _pluginsMap.end() && _pluginsMap[aName] != nullptr)
                throw Plugin::Plugin::PluginException("Plugin " + aName + " already loaded");

            _pluginsMap[myPlugin->getName()] = std::move(myPlugin);
            _pluginsPathMap[aPath] = aName;
            std::cout << "Plugin " << aName << " loaded" << std::endl;
        } catch (const Plugin::Plugin::PluginException &e) {
            std::cerr << e.what() << std::endl;
        }
    }

    void PluginManager::unloadPlugin(const std::string &aName, Entity::IEntityMap &aEntities)
    {
        try {
            auto myIt = _pluginsPathMap.find(aName);
            if (myIt == _pluginsPathMap.end())
                throw Plugin::Plugin::PluginException("Plugin " + aName + " not loaded");

            deleteEntities(aName, aEntities);

            _pluginsMap[myIt->second].reset();
            std::cout << "Plugin " << aName << " unloaded" << std::endl;
        } catch (const Plugin::Plugin::PluginException &e) {
            std::cerr << e.what() << std::endl;
        }
    }

    void PluginManager::deleteEntity(const std::string &aName, Entity::IEntityPtr &aEntity)
    {
        try {
            if (_pluginsMap.find(aName) == _pluginsMap.end())
                throw Plugin::Plugin::PluginException("Plugin " + aName + " not loaded");

            _pluginsMap[aName]->destroyEntity(aEntity);
        } catch (const Plugin::Plugin::PluginException &e) {
            std::cerr << e.what() << std::endl;
        }
    }

    void PluginManager::deleteEntities(const std::string &aName, Entity::IEntityMap &aEntities)
    {
        for (auto &myEntity : aEntities[aName])
            deleteEntity(aName, myEntity);
    }

    void PluginManager::deleteEntities(Entity::IEntityMap &aEntities)
    {
        for (auto &myEntity : aEntities)
            deleteEntities(myEntity.first, aEntities);
    }

    Entity::IEntityPtr PluginManager::createEntity(const std::string &aName,
        Entity::DataEntityMap &aData)
    {
        if (_pluginsMap.find(aName) == _pluginsMap.end())
            throw Plugin::Plugin::PluginException("Plugin " + aName + " not loaded");

        auto myEntity = _pluginsMap[aName]->createEntity(aData);

        return std::unique_ptr<Entity::IEntity>(myEntity);
    }

    void PluginManager::getNotified(const std::string &aMessage, Entity::IEntityMap &aEntityMap)
    {
        std::string myPath;

        std::cout << "PluginManager: " << aMessage << std::endl;
        if (aMessage.starts_with("APPEARING")) {
            myPath = aMessage.substr(aMessage.find("APPEARING") + 10);
            loadPlugin(myPath);
            return;
        }
        if (aMessage.starts_with("DISAPPEARING")) {
            myPath = aMessage.substr(aMessage.find("DISAPPEARING") + 13);
            unloadPlugin(myPath, aEntityMap);
        }
    }
} // namespace RayTracer::Plugin
