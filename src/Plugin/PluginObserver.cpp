//
// Created by patatofour on 17/04/23.
//

#include "PluginObserver.hpp"
#include <algorithm>

namespace RayTracer::Plugin
{
    PluginObserver::PluginObserver()
    {
        for (auto &p : std::filesystem::directory_iterator("./plugins")) {
            _pluginsPath.push_back(p.path());
        }
    }

    void PluginObserver::subscribe(const std::shared_ptr<Subscriber>& subscriber)
    {
        _subscribers.push_back(subscriber);
    }

    void PluginObserver::notifySubscriber(const std::string& event, Entity::IEntityMap &entityMap)
    {
        for (auto &subscriber : _subscribers) {
            subscriber->getNotified(event, entityMap);
        }
    }

    void PluginObserver::checkPlugins(Entity::IEntityMap &entityMap)
    {
        for (auto &p : std::filesystem::directory_iterator("./plugins")) {
            auto it = std::find(_pluginsPath.begin(), _pluginsPath.end(), p.path());

            if (it == _pluginsPath.end()) {
                _pluginsPath.push_back(p.path());
                notifySubscriber("APPEARING:" + p.path().string(), entityMap);
            }
        }

        for (auto it = _pluginsPath.begin(); it != _pluginsPath.end();) {
            if (!std::filesystem::exists(*it)) {
                notifySubscriber("DISAPPEARING:" + it->string(), entityMap);
                it = _pluginsPath.erase(it);
            } else {
                ++it;
            }
        }
    }
} // namespace RayTracer::Plugin
