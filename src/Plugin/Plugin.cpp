//
// Created by patatofour on 17/04/23.
//

#include "Plugin.hpp"
#include <dlfcn.h>
#include <iostream>

namespace RayTracer::Plugin
{
    Plugin::Plugin(const std::string &aPath)
    {
        _handle = dlopen(aPath.c_str(), RTLD_LAZY);
        if (!_handle)
            throw PluginException("Cannot open library: " + std::string(dlerror()));
        dlerror();
        auto myNameGetter = reinterpret_cast<const char *(*) ()>(dlsym(_handle, "getName"));
        const char *myDlSymError = dlerror();
        if (myDlSymError) {
            dlclose(_handle);
            throw PluginException("Cannot load symbol 'getName': " + std::string(myDlSymError));
        }
        _name = std::string(myNameGetter());
    }

    Plugin::~Plugin()
    {
        if (_handle == nullptr)
            return;
        dlclose(_handle);
    }

    Entity::IEntity *Plugin::createEntity(Entity::DataEntityMap &aData)
    {
        auto myGetEntity = reinterpret_cast<Entity::IEntity *(*) (Entity::DataEntityMap &)>(
            dlsym(_handle, "createEntity"));

        if (!myGetEntity)
            throw PluginException("Cannot load symbol 'getEntity': " + std::string(dlerror()));
        try {
            auto myEntity = myGetEntity(aData);
            return myEntity;
        } catch (std::exception &e) {
            throw PluginException("Cannot create entity: " + std::string(e.what()));
        }
    }

    void Plugin::destroyEntity(Entity::IEntityPtr &aEntity)
    {
        auto myDestroyEntity
            = reinterpret_cast<void (*)(Entity::IEntity *)>(dlsym(_handle, "destroyEntity"));

        if (!myDestroyEntity)
            throw PluginException("Cannot load symbol 'destroyEntity': " + std::string(dlerror()));
        myDestroyEntity(aEntity.release());
    }

    const std::string &Plugin::getName() const
    {
        return _name;
    }
} // namespace RayTracer::Plugin
