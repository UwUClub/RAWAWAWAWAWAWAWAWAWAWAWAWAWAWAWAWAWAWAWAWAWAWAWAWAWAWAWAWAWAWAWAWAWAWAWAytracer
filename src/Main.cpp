//
// Created by patatofour on 14/04/23.
//

#include "IEntity.hpp"
#include "PluginManager.hpp"
#include "PluginObserver.hpp"
#include "Scene.hpp"
#include "Parser.hpp"

int main(int argc, char *argv[])
{
    //    RayTracer::Plugin::PluginManager pluginManager;
    RayTracer::Plugin::PluginObserver pluginObserver;
    RayTracer::Entity::IEntityMap entityMap;
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
        for (auto &it : scene.getEntities()) {
            std::cout << it.first << std::endl;
            std::cout << it.second.size() << std::endl;
        }
        while (true) {
            pluginObserver.checkPlugins(entityMap);
        }
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
