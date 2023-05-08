/*
** EPITECH PROJECT, 2023
** RAWAWAWAytracer
** File description:
** HitPoint
*/

#include "Ray.hpp"
#include "IEntity.hpp"
#include "HitPoint.hpp"


namespace RayTracer
{
    HitPoint::HitPoint(double aX, double aY, double aZ, Color &aColor, Vector &aNormal)
        : Point(aX, aY, aZ)
        , _color(aColor)
        , _normal(aNormal)
    {
    }

    HitPoint::~HitPoint()
    {
    }

    static void calcAmbientColor(const std::unordered_map<std::string, std::vector<std::unique_ptr<Entity::IEntity>>> &aEntities, HitPoint &aHitPoint, Ray &aLight)
{
    for (auto &myEntity : aEntities) {
        if (myEntity.first == "BasicLight") {
            double myAmbient = myEntity.second[0]->getAmbient();
            double myDiffuse = myEntity.second[0]->getDiffuse();
            double diffuseFactor = aHitPoint._normal|aLight._direction;
            if (diffuseFactor > 0) {
                aHitPoint._color._r = aHitPoint._color._r * myAmbient + aHitPoint._color._r * myDiffuse * diffuseFactor;
                if (aHitPoint._color._r > 255)
                    aHitPoint._color._r = 255;
                aHitPoint._color._g = aHitPoint._color._g * myAmbient + aHitPoint._color._g * myDiffuse * diffuseFactor;
                if (aHitPoint._color._g > 255)
                    aHitPoint._color._g = 255;
                aHitPoint._color._b = aHitPoint._color._b * myAmbient + aHitPoint._color._b * myDiffuse * diffuseFactor;
                if (aHitPoint._color._b > 255)
                    aHitPoint._color._b = 255;
            } else {
                aHitPoint._color._r = aHitPoint._color._r * myAmbient;
                aHitPoint._color._g = aHitPoint._color._g * myAmbient;
                aHitPoint._color._b = aHitPoint._color._b * myAmbient;
            }
        }
    }
}

    Color HitPoint::calcColor(const std::unordered_map<std::string, std::vector<std::unique_ptr<Entity::IEntity>>> &aEntities)
    {
        Ray myRay = Ray({_x, _y, _z}, {0, 0, 0});
        for (auto &myEntity : aEntities) {
            if (myEntity.first == "PointLight") {
                for (auto &myLight : myEntity.second) {
                    myRay._direction._x = myLight->getPosition()._x - _x;
                    myRay._direction._y = myLight->getPosition()._y - _y;
                    myRay._direction._z = myLight->getPosition()._z - _z;
                    std::optional<HitPoint> myHitPoint = myRay.getClosestHit(aEntities);
                    if (!myHitPoint.has_value()) {
                        calcAmbientColor(aEntities, *this, myRay);
                        return _color;
                    } else {
                        return {0, 0, 0};
                    }
                }
            }
        }
        return RayTracer::Color(0, 0, 0);
    }
} // namespace RayTracer
