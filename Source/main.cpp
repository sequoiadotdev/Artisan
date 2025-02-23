/*
 Copyright (C) 2025 SequoiaDotDev. - All Rights Reserved

 Unauthorized copying or redistribution of this file in source and binary forms via any medium
 is strictly prohibited.
 */

#include <iostream>
#include <Game/Game.hpp>
#ifdef __WINDOWS__
#include <windows.h>
#endif

int GameMain() {
    Game game;
    if ( !game.Init() ) {
        std::cerr << "Failed to initialize game." << std::endl;
    }
    game.Run();
    return 0;
}

#ifndef __WINDOWS__

int APIENTRY wWinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR lpCmdLine, int nShowCmd ) {
    return GameMain();
}

# else

int main( int argc, char** argv ) {
    return GameMain();
}

#endif