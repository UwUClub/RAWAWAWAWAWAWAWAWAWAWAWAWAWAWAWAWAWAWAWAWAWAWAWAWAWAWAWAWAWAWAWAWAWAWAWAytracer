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
        for (const auto &entry : std::filesystem::recursive_directory_iterator("./plugins")) {
            if (entry.path().string().find(".so") != std::string::npos)
                loadPlugin(entry.path());
            std::cout << entry.path() << std::endl;
        }
    }

    PluginManager::~PluginManager()
    {
        for (auto &plugin : _pluginsMap)
            unloadPlugin(plugin.first);
    }

    void PluginManager::loadPlugin(const std::string &path)
    {
        try {
            auto plugin = std::make_unique<Plugin>(path);
            auto &name = plugin->getName();

            if (_pluginsMap.find(name) != _pluginsMap.end())
                throw Plugin::Plugin::PluginException("Plugin " + name + " already loaded");

            _pluginsMap[plugin->getName()] = std::move(plugin);
        } catch (const Plugin::Plugin::PluginException &e) {
            std::cerr << e.what() << std::endl;
        }
    }

    void PluginManager::unloadPlugin(const std::string &name)
    {
        try {
            if (_pluginsMap.find(name) == _pluginsMap.end())
                throw Plugin::Plugin::PluginException("Plugin " + name + " not loaded");

            _pluginsMap.erase(name);
        } catch (const Plugin::Plugin::PluginException &e) {
            std::cerr << e.what() << std::endl;
        }
    }

    void PluginManager::deleteEntity(const std::string &name, Entity::IEntityPtr &entity)
    {
        try {
            if (_pluginsMap.find(name) == _pluginsMap.end())
                throw Plugin::Plugin::PluginException("Plugin " + name + " not loaded");

            _pluginsMap[name]->destroyEntity(entity);
        } catch (const Plugin::Plugin::PluginException &e) {
            std::cerr << e.what() << std::endl;
        }
    }

    void PluginManager::deleteEntities(const std::string &name, Entity::IEntityVector &entities)
    {
        for (auto &entity : entities)
            deleteEntity(name, entity);
    }

    void PluginManager::deleteEntities(Entity::IEntityMap &entities)
    {
        for (auto &entity : entities)
            deleteEntities(entity.first, entity.second);
    }

    Entity::IEntityPtr PluginManager::createEntity(const std::string &name)
    {
        if (_pluginsMap.find(name) == _pluginsMap.end())
            throw Plugin::Plugin::PluginException("Plugin " + name + " not loaded");

        auto entity = _pluginsMap[name]->createEntity();
        return std::unique_ptr<Entity::IEntity>(entity);
    }
} // namespace RayTracer::Plugin
