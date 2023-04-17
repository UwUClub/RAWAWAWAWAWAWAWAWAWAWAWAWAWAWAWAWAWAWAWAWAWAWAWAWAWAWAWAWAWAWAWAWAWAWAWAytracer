//
// Created by patatofour on 17/04/23.
//

#ifndef RAYTRACER_PLUGIN_HPP
#define RAYTRACER_PLUGIN_HPP

#include "Entity/IEntity.hpp"
#include <memory>
#include <string>

namespace RayTracer::Plugin
{
    class Plugin
    {
        public:
            explicit Plugin(const std::string &path);
            ~Plugin();

            Entity::IEntity *createEntity();
            [[nodiscard]] const std::string &getName() const;

            void destroyEntity(std::unique_ptr<Entity::IEntity> &entity);

            class PluginException : public std::exception
            {
                public:
                    explicit PluginException(const std::string &message)
                        : _message(message)
                    {
                    }

                    ~PluginException() override = default;

                    [[nodiscard]] const char *what() const noexcept override
                    {
                        return _message.c_str();
                    }

                private:
                    std::string _message;
            };

        private:
            void *_handle;
            std::string _name;
    };
} // namespace RayTracer::Plugin

#endif // RAYTRACER_PLUGIN_HPP
