//
// Created by patatofour on 17/04/23.
//

#ifndef RAYTRACER_SUBSCRIBER_HPP
#define RAYTRACER_SUBSCRIBER_HPP

#include <string>
#include "IEntity.hpp"

namespace RayTracer::Plugin
{
    class Subscriber
    {
        public:
            Subscriber() = default;
            virtual ~Subscriber() = default;

            virtual void getNotified(const std::string &message, Entity::IEntityMap &entityMap) = 0;
    };
} // namespace RayTracer::Plugin

#endif // RAYTRACER_SUBSCRIBER_HPP
