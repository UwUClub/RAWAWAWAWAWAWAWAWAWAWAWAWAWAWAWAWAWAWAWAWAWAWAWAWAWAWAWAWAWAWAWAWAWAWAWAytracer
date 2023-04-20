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
        }
    }

    PluginManager::~PluginManager()
    {
        auto entities = Entity::IEntityMap();

        for (auto &plugin : _pluginsMap)
            unloadPlugin(plugin.first, entities);
    }

    void PluginManager::loadPlugin(const std::string &path)
    {
        try {
            auto plugin = std::make_unique<Plugin>(path);
            auto &name = plugin->getName();

            if (_pluginsMap.find(name) != _pluginsMap.end() && _pluginsMap[name] != nullptr)
                throw Plugin::Plugin::PluginException("Plugin " + name + " already loaded");

            _pluginsMap[plugin->getName()] = std::move(plugin);
            std::cout << "Plugin " << name << " loaded" << std::endl;
        } catch (const Plugin::Plugin::PluginException &e) {
            std::cerr << e.what() << std::endl;
        }
    }

    void PluginManager::unloadPlugin(const std::string &name, Entity::IEntityMap &entities)
    {
        try {
            if (_pluginsMap.find(name) == _pluginsMap.end())
                throw Plugin::Plugin::PluginException("Plugin " + name + " not loaded");

            deleteEntities(name, entities);

            _pluginsMap[name].reset();
            std::cout << "Plugin " << name << " unloaded" << std::endl;
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

    void PluginManager::deleteEntities(const std::string &name, Entity::IEntityMap &entities)
    {
        for (auto &entity : entities[name])
            deleteEntity(name, entity);

        entities[name].clear();
        entities.erase(name);
    }

    void PluginManager::deleteEntities(Entity::IEntityMap &entities)
    {
        for (auto &entity : entities)
            deleteEntities(entity.first, entities);

        entities.clear();
    }

    Entity::IEntityPtr PluginManager::createEntity(const std::string &name,
        Entity::DataEntityMap &data)
    {
        if (_pluginsMap.find(name) == _pluginsMap.end())
            throw Plugin::Plugin::PluginException("Plugin " + name + " not loaded");

        auto entity = _pluginsMap[name]->createEntity(data);
        return std::unique_ptr<Entity::IEntity>(entity);
    }

    void PluginManager::getNotified(const std::string &message, Entity::IEntityMap &entities)
    {
        std::string path;
        if (message.starts_with("APPEARING")) {
            path = message.substr(message.find("APPEARING") + 10);
            loadPlugin(path);
            return;
        }
        if (message.starts_with("DISAPPEARING")) {
            path = message.substr(message.find("DISAPPEARING") + 13);
            unloadPlugin(path, entities);
        }
    }
} // namespace RayTracer::Plugin
