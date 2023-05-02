/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Camera.hpp
*/

#ifndef RAYTRACER_CAMERA_HPP
#define RAYTRACER_CAMERA_HPP

#include "Entity.hpp"
#include "IEntity.hpp"
#include "Point.hpp"
#include "Vector.hpp"
#include "Ray.hpp"
#include <cstdint>
#include <utility>

namespace RayTracer::Entity
{
    using resolution = std::pair<int, int>;

    class Camera : public Entity::Entity
    {
        public:
            explicit Camera(const DataEntityMap &dataMap);
            ~Camera() override = default;

            /**
             * @brief Set the Rotation object
             *
             * @param aRotation The rotation of the camera
             */
            void setRotation(const Vector &aRotation);
            /**
             * @brief Set the Resolution object
             *
             * @param aResolution The resolution of the camera
             */
            void setResolution(const resolution &aResolution);
            /**
             * @brief Set the Field Of View object
             *
             * @param aFov The field of view of the camera
             */
            void setFieldOfView(float aFov);
            /**
             * @brief Get the Casted Rays object
             * @return std::vector<Ray>& The casted rays
            */
            std::vector<Ray> &getCastedRays() const;

        private:
            resolution _resolution;
            Vector _rotation;
            double _fieldOfView;
    };

} // namespace RayTracer::Entity

#endif // RAYTRACER_CAMERA_HPP
