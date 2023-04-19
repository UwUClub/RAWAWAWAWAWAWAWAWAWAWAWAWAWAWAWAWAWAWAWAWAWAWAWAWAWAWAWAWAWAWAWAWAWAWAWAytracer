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
        struct DataEntity {
            RayTracer::Point position;
            RayTracer::Entity::Color color;
            double radius;
            double height;
        };
    } // RayTracer

#endif //RAYTRACER_DATASTRUCTURE_HPP
