//
// Created by patatofour on 17/04/23.
//

#ifndef RAYTRACER_SUBSCRIBER_HPP
#define RAYTRACER_SUBSCRIBER_HPP

#include "IEntity.hpp"
#include <string>

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
             * @param aMessage The aMessage to notify
             * @param aEntityMap The entity map
             */
            virtual void getNotified(const std::string &aMessage, Entity::IEntityMap &aEntityMap)
                = 0;
    };
} // namespace RayTracer::Plugin

#endif // RAYTRACER_SUBSCRIBER_HPP
