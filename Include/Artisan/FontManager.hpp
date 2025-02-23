/*
 Copyright (C) 2025 SequoiaDotDev. - All Rights Reserved

 Unauthorized copying or redistribution of this file in source and binary forms via any medium
 is strictly prohibited.
 */

#ifndef FONTMANAGER_HPP
#define FONTMANAGER_HPP

#include <SDL_ttf.h>
#include <string>
#include <map>

class FontManager {
public:
    FontManager();
    ~FontManager();

    TTF_Font* LoadFont( const std::string& fontName, int fontSize );
    TTF_Font* GetFont( const std::string& fontId );
private:
    std::map<std::string, TTF_Font*> m_fontMap;

    FontManager( const FontManager& ) = delete;
    FontManager& operator=( const FontManager& ) = delete;
};

#endif //FONTMANAGER_HPP
