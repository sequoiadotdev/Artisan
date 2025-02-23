/*
 Copyright (C) 2025 SequoiaDotDev. - All Rights Reserved

 Unauthorized copying or redistribution of this file in source and binary forms via any medium
 is strictly prohibited.
 */

#ifndef TESTSCENE_HPP
#define TESTSCENE_HPP

#include <Artisan/Keybind.hpp>
#include <Artisan/Scene.hpp>
#include <Artisan/Renderer.hpp>

class TestScene final : public Scene {
public:
    void Init() override;
    void Update( float deltaTime ) override;
    void Render( Renderer& renderer ) override;
    void Cleanup() override;
private:
    float m_x = 640 / 2;
    float m_y = 480 / 2;
    //
    Keybind m_forward { SDLK_w };
    Keybind m_left { SDLK_a };
    Keybind m_down { SDLK_s };
    Keybind m_right { SDLK_d };
};

#endif //TESTSCENE_HPP
