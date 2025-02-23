/*
 Copyright (C) 2025 SequoiaDotDev. - All Rights Reserved

 Unauthorized copying or redistribution of this file in source and binary forms via any medium
 is strictly prohibited.
 */

#include <Artisan/FontManager.hpp>
#include <iostream>
#include <ranges>

FontManager::FontManager() {
    if ( TTF_Init() == -1 ) {
        std::cerr << "SDL_ttf initialization failed: " << TTF_GetError()
              << std::endl;
    }
}

FontManager::~FontManager() {
    for ( const auto& font : m_fontMap | std::views::values ) {
        TTF_CloseFont( font );
    }

    m_fontMap.clear();
    TTF_Quit();
}

TTF_Font* FontManager::LoadFont( const std::string& fontName, const int fontSize ) {
    const std::string fontId = fontName + "_" + std::to_string( fontSize );

    if ( m_fontMap.contains( fontId ) ) {
        return m_fontMap[ fontId ];
    }

    TTF_Font* font = TTF_OpenFont( ("Assets/Fonts/" + fontName + ".ttf").c_str(), fontSize );

    if ( font == nullptr ) {
        std::cerr << "Failed to load font: " << fontName << " - " << TTF_GetError()
              << std::endl;
        return nullptr;
    }

    m_fontMap[fontId] = font;
    return font;
}

TTF_Font* FontManager::GetFont( const std::string& fontId ) {
    if ( m_fontMap.contains( fontId ) ) {
        return m_fontMap[ fontId ];
    }

    return nullptr;
}

