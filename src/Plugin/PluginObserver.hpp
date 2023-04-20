//
// Created by patatofour on 17/04/23.
//

#ifndef RAYTRACER_PLUGINOBSERVER_HPP
#define RAYTRACER_PLUGINOBSERVER_HPP

#include "IEntity.hpp"
#include "Subscriber.hpp"
#include <filesystem>
#include <memory>
#include <vector>

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
             * @brief Subscribe a aSubscriber to the observer
             * @param aSubscriber The aSubscriber to subscribe
             */
            void subscribe(const std::shared_ptr<Subscriber> &aSubscriber);
            /**
             * @brief Check if a plugin has been added or removed
             * @param aEntityMap The entity map
             * @details If a plugin has been added, the observer will notify all the subscribers
             * @details If a plugin has been removed, the observer will notify all the subscribers
             * @details format of message: "APPEARING:plugin_path" or "DISAPPEARING:plugin_path"
             */
            void checkPlugins(Entity::IEntityMap &aEntityMap);

        private:
            /**
             * @brief Notify all the subscribers
             * @param aEvent The aEvent to notify
             * @param aEntityMap The entity map
             */
            void notifySubscriber(const std::string &aEvent, Entity::IEntityMap &aEntityMap);

        private:
            std::vector<std::shared_ptr<Subscriber>> _subscribers;
            std::vector<std::filesystem::path> _pluginsPath;
    };
} // namespace RayTracer::Plugin

#endif // RAYTRACER_PLUGINOBSERVER_HPP
