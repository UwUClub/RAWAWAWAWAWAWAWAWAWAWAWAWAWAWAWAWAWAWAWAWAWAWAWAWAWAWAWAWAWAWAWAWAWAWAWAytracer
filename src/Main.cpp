//
// Created by patatofour on 14/04/23.
//

#include "Entity/Entity.hpp"
#include "HitPoint.hpp"
#include "IEntity.hpp"
#include "PluginManager.hpp"
#include "PluginObserver.hpp"
#include "Scene.hpp"
#include "Parser.hpp"
#include "Primitives.hpp"
#include "Camera.hpp"
#include "Ray.hpp"
#include <memory>
#include <iostream>

int main(int argc, char *argv[])
{
    //    RayTracer::Plugin::PluginManager pluginManager;
    RayTracer::Plugin::PluginObserver pluginObserver;
    //    RayTracer::Entity::DataEntityMap dataEntityMap;
    //
    //    dataEntityMap["r"] = 255;
    //
    RayTracer::Plugin::PluginManager pluginManager;
    RayTracer::Scene::Scene scene(pluginManager);
    (void) argc;
    try {
        RayTracer::Parser::Parser parser(argv, scene, pluginManager);
        pluginObserver.subscribe(pluginManager);
        pluginObserver.checkPlugins(scene.getEntities());

        // Get cam rays
        auto &myCam = scene.getCamera();
        const std::vector<RayTracer::Ray> myRays = myCam->getCastedRays();

        std::cout << "nb of rays: " << myRays.size() << std::endl;

        for (auto &entity : scene.getEntities()) {
            std::cout << "entity " << entity.first << std::endl;
        }

        // auto myTestRay = RayTracer::Ray(RayTracer::Point(0, 0, 0), RayTracer::Vector(0, 0, 1));
        // auto myTestHit = myTestRay.getClosestHit(scene.getEntities());

        // if (myTestHit.has_value()) {
        //     auto color= myTestHit->calcColor(scene.getEntities());
        //     std::cout << "hit: color " << color._r << " " << color._g << " " << color._b << std::endl;
        // }

        std::vector<RayTracer::Color> myPixels = std::vector<RayTracer::Color>();

        // Send rays
        for (auto &ray : myRays) {
            auto hit = ray.getClosestHit(scene.getEntities());
            auto color = RayTracer::Color(0, 0, 0);
            //std::cout << "ray [" << ray._origin._x << " " << ray._origin._y << " " << ray._origin._z << "] [" << ray._direction._x << " " << ray._direction._y << " " << ray._direction._z << "]" << std::endl;
            if (hit) {
                //std::cout << "color hit" << std::endl;
                color = hit->calcColor(scene.getEntities());
            } else {
                color = RayTracer::Color(255, 255, 255);
            }
            myPixels.push_back(color);
            // std::cout << color._r << color._g << color._b << std::endl;
        }
        scene.createPPM("firstScene", myPixels, 200, 100);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    //    //    auto myColor = pluginManager.createEntity("Color", dataEntityMap);
    //    //    scene.addEntity("Color", myColor);
    //    //    auto &list = scene.getEntities();
    //    //
    //    //    pluginManager.deleteEntities(list);

    // Example of how to use ppm creation method:
    // scene.createPPM("MyScene.ppm", std::vector<RayTracer::Color>(
    //     {
    //         RayTracer::Color(255, 0, 0),
    //         RayTracer::Color(0, 255, 0),
    //         RayTracer::Color(0, 0, 255),
    //         RayTracer::Color(255, 255, 0),
    //         RayTracer::Color(255, 128, 128),
    //         RayTracer::Color(128, 255, 128),
    //         RayTracer::Color(128, 128, 255),
    //         RayTracer::Color(255, 128, 128),
    //     }), 4, 2
    // );
    return 0;
}
