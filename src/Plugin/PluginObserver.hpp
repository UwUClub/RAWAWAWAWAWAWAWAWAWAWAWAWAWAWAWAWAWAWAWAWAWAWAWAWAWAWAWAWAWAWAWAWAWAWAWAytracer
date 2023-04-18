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
    class PluginObserver final
    {
        public:
            PluginObserver();
            virtual ~PluginObserver() = default;

            void subscribe(const std::shared_ptr<Subscriber>& subscriber);
            void checkPlugins(Entity::IEntityMap &entityMap);

        private:
            void notifySubscriber(const std::string &event, Entity::IEntityMap &entityMap);

        private:
            std::vector<std::shared_ptr<Subscriber>> _subscribers;
            std::vector<std::filesystem::path> _pluginsPath;
    };
} // namespace RayTracer::Plugin

#endif // RAYTRACER_PLUGINOBSERVER_HPP
