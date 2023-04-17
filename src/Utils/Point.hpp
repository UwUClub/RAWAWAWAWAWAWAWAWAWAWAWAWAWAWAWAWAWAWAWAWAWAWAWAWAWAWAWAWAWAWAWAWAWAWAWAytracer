/*
** EPITECH PROJECT, 2023
** RAWAWAWAytracer
** File description:
** Point
*/

#ifndef POINT_HPP_
#define POINT_HPP_

struct Point {
    public:
        Point(double x, double y, double z) : x(x), y(y), z(z) {};
        ~Point();
        double x;
        double y;
        double z;
};

#endif /* !POINT_HPP_ */
