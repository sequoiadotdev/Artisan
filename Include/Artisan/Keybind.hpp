
/*
 Copyright (C) 2025 SequoiaDotDev. - All Rights Reserved

 Unauthorized copying or redistribution of this file in source and binary forms via any medium
 is strictly prohibited.
 */

#ifndef KEYBIND_HPP
#define KEYBIND_HPP

#include <SDL.h>
#include <map>
#include <string>

class Keybind {
public:
    explicit Keybind( SDL_Keycode key );
    ~Keybind();

    bool IsDown() const;
    SDL_Keycode GetKey() const;

    static void Update( const SDL_Event& event );

private:
    std::string m_name;
    SDL_Keycode m_key;
    bool m_isDown;

    static std::map<SDL_Keycode, Keybind*> s_keybindings;
};

#endif //KEYBIND_HPP
