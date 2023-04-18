//
// Created by patatofour on 14/04/23.
//*

#include "Plugin/PluginManager.hpp"
#include "Parser.hpp"
int main(int argc, char *argv[])
{
    RayTracer::Plugin::PluginManager pluginManager;
    RayTracer::Parser::Parser parser(argc, argv);
    argc = argc;
    argv = argv;
    return 0;
}
