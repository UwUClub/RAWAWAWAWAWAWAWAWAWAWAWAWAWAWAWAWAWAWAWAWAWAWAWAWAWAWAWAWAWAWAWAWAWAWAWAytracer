//
// Created by patatofour on 17/04/23.
//

#include "Plugin.hpp"
#include <dlfcn.h>

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
            throw PluginException("Cannot load symbol 'myGetEntity': " + std::string(dlerror()));
        return myGetEntity(aData);
    }

    void Plugin::destroyEntity(std::unique_ptr<Entity::IEntity> &aEntity)
    {
        auto myDestroyEntity
            = reinterpret_cast<void (*)(Entity::IEntity *)>(dlsym(_handle, "myDestroyEntity"));

        if (!myDestroyEntity)
            throw PluginException(
                "Cannot load symbol 'myDestroyEntity': " + std::string(dlerror()));
        myDestroyEntity(aEntity.release());
    }

    const std::string &Plugin::getName() const
    {
        return _name;
    }
} // namespace RayTracer::Plugin
