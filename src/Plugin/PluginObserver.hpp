//
// Created by patatofour on 17/04/23.
//

#ifndef RAYTRACER_PLUGINOBSERVER_HPP
#define RAYTRACER_PLUGINOBSERVER_HPP

#include "Subscriber.hpp"
#include "IEntity.hpp"
#include <vector>
#include <memory>
#include <filesystem>

namespace RayTracer::Plugin
{
    /**
     * @brief The PluginObserver class
     */
    class PluginObserver final
    {
        public:
            /**
             * @brief PluginObserver constructor
             * @details Init the plugins path
             */
            PluginObserver();
            /**
             * @brief PluginObserver destructor
             */
            virtual ~PluginObserver() = default;

            /**
             * @brief Subscribe a subscriber to the observer
             * @param subscriber The subscriber to subscribe
             */
            void subscribe(const std::shared_ptr<Subscriber>& subscriber);
            /**
             * @brief Check if a plugin has been added or removed
             * @param entityMap The entity map
             * @details If a plugin has been added, the observer will notify all the subscribers
             * @details If a plugin has been removed, the observer will notify all the subscribers
             * @details format of message: "APPEARING:plugin_path" or "DISAPPEARING:plugin_path"
             */
            void checkPlugins(Entity::IEntityMap &entityMap);

        private:
            /**
             * @brief Notify all the subscribers
             * @param event The event to notify
             * @param entityMap The entity map
             */
            void notifySubscriber(const std::string &event, Entity::IEntityMap &entityMap);

        private:
            std::vector<std::shared_ptr<Subscriber>> _subscribers;
            std::vector<std::filesystem::path> _pluginsPath;
    };
} // namespace RayTracer::Plugin

#endif // RAYTRACER_PLUGINOBSERVER_HPP
