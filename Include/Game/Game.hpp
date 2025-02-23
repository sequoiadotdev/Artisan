/*
 Copyright (C) 2025 SequoiaDotDev. - All Rights Reserved

 Unauthorized copying or redistribution of this file in source and binary forms via any medium
 is strictly prohibited.
 */

#ifndef GAME_HPP
#define GAME_HPP

#include <Artisan/Window.hpp>

class Game {
public:
    Game();
    ~Game();
    bool Init();
    void Run() const;
private:
    Window m_window;
};

#endif //GAME_HPP
