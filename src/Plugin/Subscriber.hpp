//
// Created by patatofour on 17/04/23.
//

#ifndef RAYTRACER_SUBSCRIBER_HPP
#define RAYTRACER_SUBSCRIBER_HPP

#include <string>
#include "IEntity.hpp"

namespace RayTracer::Plugin
{
    /**
     * @brief The Subscriber interface
     */
    class Subscriber
    {
        public:
            virtual ~Subscriber() = default;

            /**
            * @brief Get notified by the observer
            * @param message The message to notify
            * @param entityMap The entity map
            */
            virtual void getNotified(const std::string &message, Entity::IEntityMap &entityMap) = 0;
    };
} // namespace RayTracer::Plugin

#endif // RAYTRACER_SUBSCRIBER_HPP
