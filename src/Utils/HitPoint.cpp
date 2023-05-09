/*
** EPITECH PROJECT, 2023
** RAWAWAWAytracer
** File description:
** HitPoint
*/

#include <cmath>
#include "Ray.hpp"
#include "IEntity.hpp"
#include "HitPoint.hpp"


namespace RayTracer
{
    HitPoint::HitPoint(double aX, double aY, double aZ, Color &aColor, Vector &aNormal, Vector &aViewVector)
        : Point(aX, aY, aZ)
        , _color(aColor)
        , _normal(aNormal)
        , _viewVector(aViewVector)
    {
    }

    HitPoint::~HitPoint()
    {
    }

    static void calcAmbiantColor(const std::unordered_map<std::string, std::vector<std::unique_ptr<Entity::IEntity>>> &aEntities, Color &aColor)
    {
        for (auto &myEntity : aEntities) {
            if (myEntity.first == "BasicLight") {
                double myAmbient = myEntity.second[0]->getAmbient();
                aColor._r = aColor._r * myAmbient * 0.6;
                aColor._g = aColor._g * myAmbient * 0.6;
                aColor._b = aColor._b * myAmbient * 0.6;
            }
        }
    }

    static void calcDiffuseColor(const std::unordered_map<std::string, std::vector<std::unique_ptr<Entity::IEntity>>> &aEntities, HitPoint &aHitPoint, Ray &aLight)
    {
        for (auto &myEntity : aEntities) {
            if (myEntity.first == "BasicLight") {
                double myAmbient = myEntity.second[0]->getAmbient();
                double myDiffuse = myEntity.second[0]->getDiffuse();
                Vector myLightDirection = Vector (aLight._direction._x / aLight._direction._dist,
                    aLight._direction._y / aLight._direction._dist,
                    aLight._direction._z / aLight._direction._dist);
                double diffuseFactor = std::max(aHitPoint._normal|(myLightDirection), 0.0);
                double specularFactor = pow(std::max(aHitPoint._viewVector|(myLightDirection*-1 - (aHitPoint._normal) * ((aHitPoint._normal|(myLightDirection*-1)) * 2.0)), 0.0), 32);
                aHitPoint._color._r = aHitPoint._color._r * myAmbient + (aHitPoint._color._r * myDiffuse * diffuseFactor) + (aHitPoint._color._r * 0.9 * specularFactor);
                if (aHitPoint._color._r > 255)
                    aHitPoint._color._r = 255;
                aHitPoint._color._g = aHitPoint._color._g * myAmbient + (aHitPoint._color._g * myDiffuse * diffuseFactor) + (aHitPoint._color._g * 0.9 * specularFactor);
                if (aHitPoint._color._g > 255)
                    aHitPoint._color._g = 255;
                aHitPoint._color._b = aHitPoint._color._b * myAmbient + (aHitPoint._color._b * myDiffuse * diffuseFactor) + (aHitPoint._color._b * 0.9 * specularFactor);
                if (aHitPoint._color._b > 255)
                    aHitPoint._color._b = 255;
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
                    myRay._direction._dist = sqrt(pow(myRay._direction._x, 2) + pow(myRay._direction._y, 2) + pow(myRay._direction._z, 2));
                    std::optional<HitPoint> myHitPoint = myRay.getClosestHit(aEntities);
                    if (!myHitPoint.has_value()) {
                        calcDiffuseColor(aEntities, *this, myRay);
                        return _color;
                    } else {
                        calcAmbiantColor(aEntities, _color);
                        return _color;
                    }
                }
            }
        }
        return RayTracer::Color(0, 0, 0);
    }
} // namespace RayTracer
