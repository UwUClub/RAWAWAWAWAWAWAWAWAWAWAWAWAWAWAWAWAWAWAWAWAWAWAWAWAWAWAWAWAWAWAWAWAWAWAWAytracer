/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Parser.cpp
*/

#include "Parser.hpp"
#include "CameraParser.hpp"
#include "IEntity.hpp"
#include "LightParser.hpp"
#include "PrimitivesParser.hpp"
#include <cstring>

namespace RayTracer::Parser
{
    Parser::Parser(char **aAv, RayTracer::Scene::Scene &aScene,
        RayTracer::Plugin::PluginManager &aPluginManager)
        : _cfg()
    {
        try {
            _cfg.readFile(aAv[1]);
        } catch (const libconfig::FileIOException &fioex) {
            std::cout << "I/O error while reading file." << aAv[1] << std::endl;
            throw ParserException("I/O error while reading file.");
        } catch (const libconfig::ParseException &pex) {
            std::string myError = "Parse error at ";
            myError += pex.getFile();
            myError += ":";
            myError += std::to_string(pex.getLine());
            myError += " - ";
            myError += pex.getError();
            throw ParserException(myError);
        }
        try {
            CreateCamera(aScene, aPluginManager);
            CreatePrimitive(aScene, aPluginManager);
            CreateLight(aScene, aPluginManager);
        } catch (const ParserException &e) {
            std::cerr << e.what() << std::endl;
        }
    }

    void Parser::CreateCamera(RayTracer::Scene::Scene &aScene,
        RayTracer::Plugin::PluginManager &aPluginManager)
    {
        Entity::DataEntityMap myCameraData;
        const libconfig::Setting &myRoot = _cfg.getRoot();
        if (!myRoot.exists("camera") || !myRoot["camera"].isGroup())
            throw ParserException("No 'camera' setting in configuration file.");
        const libconfig::Setting &myCamera = myRoot["camera"];
        if (!myCamera.exists("resolution") || !myCamera.exists("position")
            || !myCamera.exists("rotation") || !myCamera.exists("fieldOfView"))
            throw ParserException(
                "Camera is missing parameters (resolution, position, rotation, fieldOfView).");

        CameraParser::createCamera(myCamera, myCameraData, aPluginManager, aScene);
    }

    void Parser::CreatePrimitive(RayTracer::Scene::Scene &aScene,
        RayTracer::Plugin::PluginManager &aPluginManager)
    {
        Entity::DataEntityMap myPrimitiveData;
        const libconfig::Setting &myRoot = _cfg.getRoot();
        if (!myRoot.exists("primitives") || !myRoot["primitives"].isGroup())
            throw ParserException("No 'primitives' setting in configuration file.");
        const libconfig::Setting &myPrimitives = myRoot["primitives"];

        for (int i = 0; i < myPrimitives.getLength(); i++) {
            if (std::strcmp(myPrimitives[i].getName(), "Planes") == 0) {
                PrimitivesParser::createPlane(myPrimitives["Planes"], myPrimitiveData,
                    aPluginManager, aScene);
            } else {
                for (int y = 0; y < myPrimitives[i].getLength()
                                && std::strcmp(myPrimitives[i].getName(), "Planes") == 0;
                     y++)
                    PrimitivesParser::createPrimitive(myPrimitives[y], myPrimitiveData,
                        aPluginManager, aScene);
            }
        }
    }

    void Parser::CreateLight(RayTracer::Scene::Scene &aScene,
        RayTracer::Plugin::PluginManager &aPluginManager)
    {
        Entity::DataEntityMap myLightData;
        const libconfig::Setting &myRoot = _cfg.getRoot();
        if (!myRoot.exists("lights") || !myRoot["lights"].isGroup())
            throw ParserException("No 'lights' setting in configuration file.");
        const libconfig::Setting &myLights = myRoot["lights"];

        if (myLights.exists("point") && myLights["point"].isList())
            Light::LightParser::createLight(myLights["point"], myLightData, aPluginManager, aScene);
    }
} // namespace RayTracer::Parser
