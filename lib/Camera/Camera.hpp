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
#include "Euler.hpp"
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
             * @brief Set the Angles object
             *
             * @param aAngles The angles of the camera
             */
            void setAngles(const Euler &aAngles);
            /**
             * @brief Get the Resolution object
             *
             * @return resolution The resolution of the camera
             */
            resolution getResolution() const;
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
            std::vector<Ray> getCastedRays() const override;

        private:
            resolution _resolution;
            Euler _angles;
            double _fieldOfView;
    };

} // namespace RayTracer::Entity

#endif // RAYTRACER_CAMERA_HPP
