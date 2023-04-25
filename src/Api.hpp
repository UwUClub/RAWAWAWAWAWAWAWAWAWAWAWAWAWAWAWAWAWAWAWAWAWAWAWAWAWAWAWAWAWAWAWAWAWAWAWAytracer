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
 * @param aData The data to create the entity, a key is the name of the data and the value is the
 * data
 * @return A pointer to the new entity
 * @note The pointer must be deleted by the plugin
 * @throw An exception if the entity cannot be created
 */
EXPORT RayTracer::Entity::IEntity *createEntity(RayTracer::Entity::DataEntityMap &aData);

/*
 * @brief Get the name of the plugin
 * @return The name of the plugin
 * @note The name must be unique
 */
EXPORT const char *getName();

/*
 * @brief Destroy an aEntity
 * @param aEntity The aEntity to destroy
 * @return The aEntity
 */
EXPORT void destroyEntity(RayTracer::Entity::IEntity *aEntity);
};

#endif /*API_HPP_*/