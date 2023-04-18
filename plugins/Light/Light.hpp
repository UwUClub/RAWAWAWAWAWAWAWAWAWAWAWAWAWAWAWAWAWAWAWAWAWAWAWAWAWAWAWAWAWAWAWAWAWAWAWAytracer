//
// Created by beafowl on 18/04/23.
//

#ifndef RAYTRACER_LIGHT_HPP
    #define RAYTRACER_LIGHT_HPP

    namespace RayTracer::Light {
        class Light {
            public:
                Light();
                virtual ~Light() = default;
            private:
                float _ambient;
                float _diffuse;
        };
    }

#endif //RAYTRACER_LIGHT_HPP
