//
// Created by patatofour on 14/04/23.
//

#include "Entity/IEntity.hpp"
#include "Parser/Parser.hpp"
#include "Plugin/PluginManager.hpp"
#include "Plugin/PluginObserver.hpp"

int main(int argc, char *argv[])
{
    //    std::shared_ptr<RayTracer::Plugin::PluginManager> pluginManager
    //        = std::make_shared<RayTracer::Plugin::PluginManager>();
    //    RayTracer::Plugin::PluginObserver pluginObserver;
    //    RayTracer::Entity::IEntityMap entityMap;
    RayTracer::Entity::DataEntityMap dataEntityMap;

    dataEntityMap["r"] = 255;

    //    pluginObserver.subscribe(pluginManager);
    //    while (true) {
    //        pluginObserver.checkPlugins(entityMap);
    //        pluginManager->createEntity("Color", dataEntityMap);
    //    }
    RayTracer::Scene::Scene scene;
    RayTracer::Plugin::PluginManager pluginManager;
    try {
        RayTracer::Parser::Parser parser(argv, scene, pluginManager);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    //    auto myColor = pluginManager.createEntity("Color", dataEntityMap);
    //    scene.addEntity("Color", myColor);
    //    auto &list = scene.getEntities();
    //
    //    pluginManager.deleteEntities(list);
    return 0;
}
