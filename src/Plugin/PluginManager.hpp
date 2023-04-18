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

            /**
             * @brief Delete an entity
             * @param name The name of the entity
             * @param entity The entity to delete
             */
            void deleteEntity(const std::string &name, Entity::IEntityPtr &entity);
            /**
             * @brief Delete all the entities in the vector at key "name"
             * @param name the key of the map which contains the entities to delete
             * @param entities The entities to delete
             */
            void deleteEntities(const std::string &name, Entity::IEntityMap &entities);
            /**
             * @brief Delete all the entities in the map
             * @param entities The entities to delete
             */
            void deleteEntities(Entity::IEntityMap &entities);

            /**
             * @brief Create an entity
             * @param name The name of the entity
             * @return The entity created as a unique_ptr
             */
            Entity::IEntityPtr createEntity(const std::string &name);

            /**
             * @brief Event called when the observer notify the subscriber
             * @param message The message to notify
             * @param entityMap The entity map
             */
            void getNotified(const std::string &message, Entity::IEntityMap &entityMap) override;

        private:
            /**
             * @brief Load a plugin
             * @param path The path of the plugin
             */
            void loadPlugin(const std::string &path);
            /**
             * @brief Unload a plugin
             * @param name The name of the plugin
             * @param entities The entity map
             */
            void unloadPlugin(const std::string &name, Entity::IEntityMap &entities);

        private:
            std::unordered_map<std::string, std::unique_ptr<Plugin>> _pluginsMap;
    };
} // namespace RayTracer::Plugin

#endif // RAYTRACER_PLUGINMANAGER_HPP
