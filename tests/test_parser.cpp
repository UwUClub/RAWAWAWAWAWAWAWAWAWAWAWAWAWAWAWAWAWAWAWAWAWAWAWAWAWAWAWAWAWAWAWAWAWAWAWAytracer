//
// Created by beafowl on 29/04/23.
//

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "Parser.hpp"
#include "PluginManager.hpp"
#include "Scene.hpp"

Test(Parser_with_good_config, Parser)
{
    char *test[2] = {(char *)"./build/tests/unit_tests", (char *)"./tests/test.json"};
    RayTracer::Plugin::PluginManager pluginManager;
    RayTracer::Scene::Scene scene(pluginManager);
    RayTracer::Parser::Parser(test, scene, pluginManager);
}