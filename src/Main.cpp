//
// Created by patatofour on 14/04/23.
//

#include "Entity/IEntity.hpp"
#include "Plugin/PluginManager.hpp"
#include "Plugin/PluginObserver.hpp"
#include "Parser/Parser.hpp"

int main(int argc, char *argv[])
{
//    std::shared_ptr<RayTracer::Plugin::PluginManager> pluginManager = std::make_shared<RayTracer::Plugin::PluginManager>();
//    RayTracer::Plugin::PluginObserver pluginObserver;
//    RayTracer::Entity::IEntityMap entityMap;
//
//
//    pluginObserver.subscribe(pluginManager);
//    while (true) {
//        pluginObserver.checkPlugins(entityMap);
//    }
    RayTracer::Scene::Scene scene;
    RayTracer::Parser::Parser parser(argv, scene);
    return 0;
}
