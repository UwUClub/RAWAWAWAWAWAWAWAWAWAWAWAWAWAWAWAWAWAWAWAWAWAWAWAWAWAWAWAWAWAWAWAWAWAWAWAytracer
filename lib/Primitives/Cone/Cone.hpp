/*
** EPITECH PROJECT, 2023
** RAWAWAWAytracer
** File description:
** Cone
*/

#ifndef CONE_HPP_
#define CONE_HPP_

#include "IEntity.hpp"
#include "Primitives.hpp"

namespace RayTracer::Entity
{
    /**
     * @brief Cone class
     * @details One of the primitives
     */
    class Cone : public Primitives
    {
        public:
            /**
             * @brief Construct a new Cone object
             *
             * @param dataMap The map containing the data
             */
            Cone(const DataEntityMap &dataMap);
            ~Cone() override = default;
            /**
             * @brief Check if the ray touched the cone
             *
             * @param ray The ray to check
             * @return std::optional<double> The distance between the ray and the cone
             */
            std::optional<double> isTouched(const Ray &ray) override;

        protected:
        private:
            Point _center;
            double _radius;
            double _height;
    };
}; // namespace RayTracer::Entity

#endif /* !CONE_HPP_ */
