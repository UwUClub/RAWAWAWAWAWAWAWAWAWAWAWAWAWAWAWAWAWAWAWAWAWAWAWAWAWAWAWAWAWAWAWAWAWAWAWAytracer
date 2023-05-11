//
// Created by patatofour on 17/04/23.
//

#ifndef RAYTRACER_PLUGIN_HPP
#define RAYTRACER_PLUGIN_HPP

#include "IEntity.hpp"
#include <memory>
#include <string>

namespace RayTracer::Plugin
{
    /**
     * @brief The Plugin class
     */
    class Plugin final
    {
        public:
            /**
             * @brief Plugin constructor
             * @param path The path of the plugin
             * @throw PluginException if the plugin can't be loaded
             */
            explicit Plugin(const std::string &aPath);
            /**
             * @brief Plugin destructor
             */
            ~Plugin();

            /**
             * @brief Create an entity
             * @return The entity of the plugin
             * @throw PluginException if the plugin doesn't have the createEntity function
             */
            Entity::IEntity *createEntity(Entity::DataEntityMap &aData);
            /**
             * @brief Get the name of the plugin
             * @return The name of the plugin which is the name of all the entities created by the
             * plugin
             * @throw PluginException if the plugin doesn't have the getName function
             */
            [[nodiscard]] const std::string &getName() const;

            /**
             * @brief Destroy an aEntity
             * @param aEntity The aEntity to destroy
             * @throw PluginException if the plugin doesn't have the destroyEntity function
             */
            void destroyEntity(std::unique_ptr<Entity::IEntity> &aEntity);

            /**
             * @brief The PluginException class
             */
            class PluginException : public std::exception
            {
                public:
                    explicit PluginException(const std::string &aMessage)
                        : _message(aMessage)
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
