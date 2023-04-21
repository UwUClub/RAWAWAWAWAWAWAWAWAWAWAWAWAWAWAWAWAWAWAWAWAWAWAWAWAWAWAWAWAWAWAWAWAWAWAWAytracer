//
// Created by patatofour on 14/04/23.
//

#include "Entity/IEntity.hpp"
#include "Parser/Parser.hpp"
#include "Plugin/PluginManager.hpp"
#include "Plugin/PluginObserver.hpp"

int main(int argc, char *argv[])
{
    //    RayTracer::Plugin::PluginManager pluginManager;
    //    RayTracer::Plugin::PluginObserver pluginObserver;
    //    RayTracer::Entity::IEntityMap entityMap;
    //    RayTracer::Entity::DataEntityMap dataEntityMap;
    //
    //    dataEntityMap["r"] = 255;
    //
    //    pluginObserver.subscribe(pluginManager);
    //    while (true) {
    //        pluginObserver.checkPlugins(entityMap);
    //        pluginManager.createEntity("Color", dataEntityMap);
    //    }
<<<<<<< HEAD
    //    RayTracer::Scene::Scene scene;
    //    RayTracer::Plugin::PluginManager pluginManager;
    //    try {
    //        RayTracer::Parser::Parser parser(argv, scene, pluginManager);
    //    } catch (std::exception &e) {
    //        std::cerr << e.what() << std::endl;
    //        return 84;
    //    }
    //    //    auto myColor = pluginManager.createEntity("Color", dataEntityMap);
    //    //    scene.addEntity("Color", myColor);
    //    //    auto &list = scene.getEntities();
    //    //
    //    //    pluginManager.deleteEntities(list);
=======
    RayTracer::Scene::Scene scene;
    RayTracer::Plugin::PluginManager pluginManager;
    try {
        RayTracer::Parser::Parser parser(argv, scene, pluginManager);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    //auto myColor = pluginManager.createEntity("Color", dataEntityMap);
    //scene.addEntity("Color", myColor);
    auto &list = scene.getEntities();
    pluginManager.deleteEntities(list);
>>>>>>> 161780da3770127ab9dad9414a8bc8039273aed3
    return 0;
}
