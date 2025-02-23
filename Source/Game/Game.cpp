/*
 Copyright (C) 2025 SequoiaDotDev. - All Rights Reserved

 Unauthorized copying or redistribution of this file in source and binary forms via any medium
 is strictly prohibited.
 */

#include <Game/Game.hpp>
#include <Game/TestScene.hpp>

Game::Game() : m_window( "SDL2 Game", 640, 480 ) {}

Game::~Game() {
    SDL_Quit();
}

bool Game::Init() {
    if ( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO ) != 0 ) {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        return false;
    }

    m_window.SetScene( std::make_unique<TestScene>() );
    return true;
}

void Game::Run() const {
    m_window.Run();
}
