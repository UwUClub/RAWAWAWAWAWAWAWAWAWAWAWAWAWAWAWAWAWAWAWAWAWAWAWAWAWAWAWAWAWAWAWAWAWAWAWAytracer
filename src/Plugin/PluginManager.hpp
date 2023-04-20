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
             * @brief Delete an aEntity
             * @param aName The aName of the aEntity
             * @param aEntity The aEntity to delete
             * @throw PluginException if the plugin doesn't exist
             */
            void deleteEntity(const std::string &aName, Entity::IEntityPtr &aEntity);
            /**
             * @brief Delete all the aEntities in the vector at key "aName"
             * @param aName the key of the map which contains the aEntities to delete
             * @param aEntities The aEntities to delete
             */
            void deleteEntities(const std::string &aName, Entity::IEntityMap &aEntities);
            /**
             * @brief Delete all the aEntities in the map
             * @param aEntities The aEntities to delete
             */
            void deleteEntities(Entity::IEntityMap &aEntities);

            /**
             * @brief Create an entity
             * @param aName The aName of the entity
             * @throw PluginException if the plugin doesn't exist
             * @return The entity created as a unique_ptr
             */
            Entity::IEntityPtr createEntity(const std::string &aName, Entity::DataEntityMap &aData);

            /**
             * @brief Event called when the observer notify the subscriber
             * @param aMessage The aMessage to notify
             * @param aEntityMap The entity map
             */
            void getNotified(const std::string &aMessage, Entity::IEntityMap &aEntityMap) override;

        private:
            /**
             * @brief Load a plugin
             * @param aPath The aPath of the plugin
             * @throw PluginException if the plugin already exist
             */
            void loadPlugin(const std::string &aPath);
            /**
             * @brief Unload a plugin
             * @param aName The aName of the plugin
             * @param aEntities The entity map
             * @throw PluginException if the plugin doesn't exist
             */
            void unloadPlugin(const std::string &aName, Entity::IEntityMap &aEntities);

        private:
            std::unordered_map<std::string, std::unique_ptr<Plugin>> _pluginsMap;
    };
} // namespace RayTracer::Plugin

#endif // RAYTRACER_PLUGINMANAGER_HPP
