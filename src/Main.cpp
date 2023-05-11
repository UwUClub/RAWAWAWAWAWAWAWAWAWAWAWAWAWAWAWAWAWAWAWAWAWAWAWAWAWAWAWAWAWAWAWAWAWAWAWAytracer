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
    RayTracer::Plugin::PluginObserver pluginObserver;
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

        // Send rays
        std::vector<RayTracer::Color> myPixels = std::vector<RayTracer::Color>();
        for (auto &ray : myRays) {
            auto hit = ray.getClosestHit(scene.getEntities());
            auto color = RayTracer::Color(0, 0, 0);
            if (hit) {
                color = hit->calcColor(scene.getEntities());
            } else {
                color = RayTracer::Color(255, 255, 255);
            }
            myPixels.push_back(color);
        }
        scene.createPPM("firstScene.ppm", myPixels, myCam->getResolution().first, myCam->getResolution().second);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}
