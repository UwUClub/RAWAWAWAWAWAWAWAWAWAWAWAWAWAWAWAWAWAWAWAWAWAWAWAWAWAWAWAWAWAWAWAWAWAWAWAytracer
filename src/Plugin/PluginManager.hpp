//
// Created by patatofour on 17/04/23.
//

#ifndef RAYTRACER_PLUGINMANAGER_HPP
#define RAYTRACER_PLUGINMANAGER_HPP

#include "Plugin.hpp"
#include "Subscriber.hpp"
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

namespace RayTracer::Plugin
{
    class PluginManager : public Subscriber
    {
        public:
            PluginManager();
            ~PluginManager() override;

            void deleteEntity(const std::string &name, Entity::IEntityPtr &entity);
            void deleteEntities(const std::string &name, Entity::IEntityMap &entities);
            void deleteEntities(Entity::IEntityMap &entities);

            Entity::IEntityPtr createEntity(const std::string &name);

            void getNotified(const std::string &message, Entity::IEntityMap &entityMap) override;

        private:
            void loadPlugin(const std::string &path);
            void unloadPlugin(const std::string &name, Entity::IEntityMap &entities);

        private:
            std::unordered_map<std::string, std::unique_ptr<Plugin>> _pluginsMap;
    };
} // namespace RayTracer::Plugin

#endif // RAYTRACER_PLUGINMANAGER_HPP
