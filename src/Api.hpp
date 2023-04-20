/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Api.hpp
*/

#ifndef API_HPP_
#define API_HPP_

#include "IEntity.hpp"
#include <iostream>
#include <memory>

#ifdef _WIN32
#define EXPORT __declspec(dllexport)
#else
#define EXPORT
#endif

extern "C" {

/*
 * @brief Create a new entity
 * @return A pointer to the new entity
 * @note The pointer must be deleted by the plugin
 */
EXPORT RayTracer::Entity::IEntity *createEntity(RayTracer::Entity::DataEntityMap &data);

/*
 * @brief Get the name of the plugin
 * @return The name of the plugin
 * @note The name must be unique
 */
EXPORT const char *getName();

/*
 * @brief Destroy an entity
 * @param entity The entity to destroy
 * @return The entity
 */
EXPORT void destroyEntity(RayTracer::Entity::IEntity *entity);
};

#endif /*API_HPP_*/