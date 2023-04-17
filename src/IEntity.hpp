//
// Created by patatofour on 17/04/23.
//

#ifndef RAYTRACER_IENTITY_HPP
#define RAYTRACER_IENTITY_HPP

#include <memory>
#include <unordered_map>
#include <vector>

namespace RayTracer::Primitive
{
    class IEntity
    {
        public:
            virtual ~IEntity() = default;
    };

    using IEntityPtr = std::unique_ptr<IEntity>;
    using IEntityVector = std::vector<IEntityPtr>;
    using IEntityMap = std::unordered_map<std::string, IEntityVector>;
} // namespace RayTracer::Primitive

#endif // RAYTRACER_IENTITY_HPP
