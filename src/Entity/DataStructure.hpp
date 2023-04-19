/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** DataStructure.hpp
*/

#ifndef RAYTRACER_DATASTRUCTURE_HPP
    #define RAYTRACER_DATASTRUCTURE_HPP

    #include <iostream>
    #include <memory>
    #include "Point.hpp"
    #include "Color.hpp"

    namespace RayTracer::Entity {
        /**
         * @brief The DataEntity struct
         * @details This struct is used to store the data of the entities
         */
        struct DataEntity {
            int planePos;
            double height;
            double radius;
            std::string axis;
            RayTracer::Point position;
            RayTracer::Entity::Color color;
        } typedef DataEntity;
    } // RayTracer

#endif //RAYTRACER_DATASTRUCTURE_HPP
