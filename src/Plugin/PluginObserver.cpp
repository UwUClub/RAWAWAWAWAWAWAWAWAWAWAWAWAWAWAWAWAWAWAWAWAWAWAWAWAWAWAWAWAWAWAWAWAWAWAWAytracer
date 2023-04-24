//
// Created by patatofour on 17/04/23.
//

#include "PluginObserver.hpp"
#include <algorithm>

namespace RayTracer::Plugin
{
    PluginObserver::PluginObserver()
    {
        for (auto &myPath : std::filesystem::directory_iterator("./plugins")) {
            _pluginsPath.push_back(myPath.path());
        }
    }

    void PluginObserver::subscribe(const std::shared_ptr<Subscriber> &aSubscriber)
    {
        _subscribers.push_back(aSubscriber);
    }

    void PluginObserver::notifySubscriber(const std::string &aEvent, Entity::IEntityMap &aEntityMap)
    {
        for (auto &mySubscriber : _subscribers) {
            mySubscriber->getNotified(aEvent, aEntityMap);
        }
    }

    void PluginObserver::checkPlugins(Entity::IEntityMap &aEntityMap)
    {
        for (auto &myPath : std::filesystem::directory_iterator("./plugins")) {
            auto myIt = std::find(_pluginsPath.begin(), _pluginsPath.end(), myPath.path());

            if (myIt == _pluginsPath.end()) {
                _pluginsPath.push_back(myPath.path());
                notifySubscriber("APPEARING:" + myPath.path().string(), aEntityMap);
            }
        }

        for (auto myIt = _pluginsPath.begin(); myIt != _pluginsPath.end();) {
            if (!std::filesystem::exists(*myIt)) {
                notifySubscriber("DISAPPEARING:" + myIt->string(), aEntityMap);
                myIt = _pluginsPath.erase(myIt);
            } else {
                ++myIt;
            }
        }
    }
} // namespace RayTracer::Plugin
