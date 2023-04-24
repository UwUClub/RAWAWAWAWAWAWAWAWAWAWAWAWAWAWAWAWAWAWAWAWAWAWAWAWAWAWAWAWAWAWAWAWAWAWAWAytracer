//
// Created by patatofour on 18/04/23.
//

#ifndef RAYTRACER_SCENE_HPP
#define RAYTRACER_SCENE_HPP

#include "IEntity.hpp"

namespace RayTracer::Scene
{
    /**
     * @brief The Scene class
     */
    class Scene final
    {
        public:
            Scene() = default;
            ~Scene() = default;

            /**
             * @brief Add an aEntity to the scene
             * @param aName The aName of the aEntity which is the key of the map
             * @param aEntity The aEntity to add
             */
            void addEntity(const std::string &aName, Entity::IEntityPtr &aEntity);

            /**
             * @brief Get the entities of the scene
             * @return The entities of the scene
             */
            Entity::IEntityMap &getEntities();

            /**
             * @brief Get the camera of the scene
             * @throw SceneException if there is no camera in the scene
             * @return The camera of the scene
             */
            Entity::IEntityPtr &getCamera();
            /**
             * @brief Get the lights of the scene
             * @throw SceneException if there is no light in the scene
             * @return The lights of the scene
             */
            Entity::IEntityVector &getLights();

            class SceneException : public std::exception
            {
                public:
                    explicit SceneException(const std::string &aMessage)
                        : _message(aMessage)
                    {
                    }

                    ~SceneException() override = default;

                    [[nodiscard]] const char *what() const noexcept override
                    {
                        return _message.c_str();
                    }

                private:
                    std::string _message;
            };

        private:
            Entity::IEntityMap _entities;
    };
} // namespace RayTracer::Scene

#endif // RAYTRACER_SCENE_HPP
