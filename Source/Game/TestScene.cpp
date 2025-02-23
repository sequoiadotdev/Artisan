/*
 Copyright (C) 2025 SequoiaDotDev. - All Rights Reserved

 Unauthorized copying or redistribution of this file in source and binary forms via any medium
 is strictly prohibited.
 */

#include <Game/TestScene.hpp>
#include <Artisan/UI/Checkbox.hpp>
#include <Artisan/Renderer.hpp>
#include <Artisan/Colors.hpp>

void TestScene::Init() {

}

void TestScene::Update( const float deltaTime ) {
    constexpr int SPEED = 100;
    //
    float moveX = 0.0f;
    float moveY = 0.0f;
    //
    if ( m_forward.IsDown() ) moveY -= 100 * deltaTime;
    if ( m_down.IsDown() ) moveY += 100 * deltaTime;
    if ( m_left.IsDown() ) moveX -= 100 * deltaTime;
    if ( m_right.IsDown() ) moveX += 100 * deltaTime;
    //
    m_x += moveX * SPEED * deltaTime;
    m_y += moveY * SPEED * deltaTime;
}

void TestScene::Render( Renderer& renderer ) {
    bool isOn = false;
    Checkbox toggle{ &isOn, "Is On" };
    renderer.SetColor( Colors::Red );

    // const auto& texture = renderer.LoadTexture("Textures/Test.png");
    const auto& font = renderer.LoadFont( "PixelifySans-Regular", 18 );
    renderer.DrawText( "Money: you broke ahh bitch", 20, 40, font, Colors::White );
    renderer.SetColor ( RGBA { 0xAF69EEFF } );
    renderer.FillRect( { static_cast<int>( m_x ), static_cast<int>( m_y ), 32, 32 } );
}

void TestScene::Cleanup() {}
