/*
 Copyright (C) 2025 SequoiaDotDev. - All Rights Reserved

 Unauthorized copying or redistribution of this file in source and binary forms via any medium
 is strictly prohibited.
 */

#include <Artisan/Keybind.hpp>

std::map<SDL_Keycode, Keybind*> Keybind::s_keybindings;

Keybind::Keybind( const SDL_Keycode key ): m_key( key ), m_isDown( false ) {
    if ( !s_keybindings.contains( key ) ) {
        s_keybindings[ key ] = this;
    }
}

Keybind::~Keybind() {
    if ( s_keybindings[m_key] == this ) {
        s_keybindings.erase( m_key );
    }
}

bool Keybind::IsDown() const {
    return m_isDown;
}

SDL_Keycode Keybind::GetKey() const {
    return m_key;
}

void Keybind::Update( const SDL_Event& event ) {
    if ( event.type == SDL_KEYDOWN || event.type == SDL_KEYUP ) {
        if ( s_keybindings.contains( event.key.keysym.sym ) ) {
            s_keybindings[ event.key.keysym.sym ]->m_isDown = (event.type == SDL_KEYDOWN);
        }
    }
}
