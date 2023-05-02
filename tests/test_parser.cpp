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
    char *test[2] = {(char *)"./build/tests/unit_tests", (char *)"./tests/subject.json"};
    RayTracer::Plugin::PluginManager pluginManager;
    RayTracer::Scene::Scene scene(pluginManager);
    RayTracer::Parser::Parser(test, scene, pluginManager);
}

Test(Parser_with_bad_config, Parser)
{
    char *test[2] = {(char *)"./build/tests/unit_tests", (char *)"./tests/test_no_cam.json"};
    RayTracer::Plugin::PluginManager pluginManager;
    RayTracer::Scene::Scene scene(pluginManager);
    cr_assert_throw(RayTracer::Parser::Parser(test, scene, pluginManager), RayTracer::Parser::Parser::ParserException);
}

Test(Parser_with_bad_config2, Parser)
{
    char *test[2] = {(char *)"./build/tests/unit_tests", (char *)"./tests/test_no_primitives.json"};
    RayTracer::Plugin::PluginManager pluginManager;
    RayTracer::Scene::Scene scene(pluginManager);
    cr_assert_throw(RayTracer::Parser::Parser(test, scene, pluginManager), RayTracer::Parser::Parser::ParserException);
}

Test(Parser_with_bad_config3, Parser)
{
    char *test[2] = {(char *)"./build/tests/unit_tests", (char *)"./tests/test_no_lights.json"};
    RayTracer::Plugin::PluginManager pluginManager;
    RayTracer::Scene::Scene scene(pluginManager);
    cr_assert_throw(RayTracer::Parser::Parser(test, scene, pluginManager), RayTracer::Parser::Parser::ParserException);
}

Test(Parser_with_bad_config4, Parser)
{
    char *test[2] = {(char *)"./build/tests/unit_tests", (char *)"./tests/test_bad_file.json"};
    RayTracer::Plugin::PluginManager pluginManager;
    RayTracer::Scene::Scene scene(pluginManager);
    cr_assert_throw(RayTracer::Parser::Parser(test, scene, pluginManager), RayTracer::Parser::Parser::ParserException);
}

Test(Parser_with_bad_config5, Parser)
{
    char *test[2] = {(char *)"./build/tests/unit_tests", (char *)"./tests/test_no_pos_cam.json"};
    RayTracer::Plugin::PluginManager pluginManager;
    RayTracer::Scene::Scene scene(pluginManager);
    cr_assert_throw(RayTracer::Parser::Parser(test, scene, pluginManager), RayTracer::Parser::Parser::ParserException);
}

Test(Parser_with_bad_config6, Parser)
{
    char *test[2] = {(char *)"./build/tests/unit_tests", (char *)""};
    RayTracer::Plugin::PluginManager pluginManager;
    RayTracer::Scene::Scene scene(pluginManager);
    cr_assert_throw(RayTracer::Parser::Parser(test, scene, pluginManager), RayTracer::Parser::Parser::ParserException);
}