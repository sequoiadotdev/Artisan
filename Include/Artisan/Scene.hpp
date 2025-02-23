/*
 Copyright (C) 2025 SequoiaDotDev. - All Rights Reserved

 Unauthorized copying or redistribution of this file in source and binary forms via any medium
 is strictly prohibited.
 */

#ifndef SCENE_HPP
#define SCENE_HPP

#include <Artisan/Renderer.hpp>

class Scene {
public:
    virtual ~Scene() = default;

    virtual void Init() = 0;
    virtual void Update( float deltaTime ) = 0;
    virtual void Render( Renderer& renderer ) = 0;
    virtual void Cleanup() = 0;
};

#endif //SCENE_HPP
