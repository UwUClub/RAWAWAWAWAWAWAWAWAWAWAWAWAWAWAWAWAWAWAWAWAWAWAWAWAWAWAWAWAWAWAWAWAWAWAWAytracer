//
// Created by patatofour on 17/04/23.
//

#include "Plugin.hpp"
#include <dlfcn.h>

namespace RayTracer::Plugin
{
    Plugin::Plugin(const std::string &path)
    {
        _handle = dlopen(path.c_str(), RTLD_LAZY);
        if (!_handle)
            throw PluginException("Cannot open library: " + std::string(dlerror()));
        dlerror();
        auto nameGetter = reinterpret_cast<const char *(*) ()>(dlsym(_handle, "getName"));
        const char *dlsym_error = dlerror();
        if (dlsym_error) {
            dlclose(_handle);
            throw PluginException("Cannot load symbol 'getName': " + std::string(dlsym_error));
        }
        _name = std::string(nameGetter());
    }

    Plugin::~Plugin()
    {
        if (_handle == nullptr)
            return;
        dlclose(_handle);
    }

    Entity::IEntity *Plugin::createEntity()
    {
        auto getEntity = reinterpret_cast<Entity::IEntity *(*) ()>(dlsym(_handle, "createEntity"));

        if (!getEntity)
            throw PluginException("Cannot load symbol 'getEntity': " + std::string(dlerror()));
        return getEntity();
    }

    void Plugin::destroyEntity(std::unique_ptr<Entity::IEntity> &entity)
    {
        auto destroyEntity
            = reinterpret_cast<void (*)(Entity::IEntity *)>(dlsym(_handle, "destroyEntity"));

        if (!destroyEntity)
            throw PluginException("Cannot load symbol 'destroyEntity': " + std::string(dlerror()));
        destroyEntity(entity.release());
    }

    const std::string &Plugin::getName() const
    {
        return _name;
    }
} // namespace RayTracer::Plugin
