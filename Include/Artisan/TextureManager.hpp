/*
 Copyright (C) 2025 SequoiaDotDev. - All Rights Reserved

 Unauthorized copying or redistribution of this file in source and binary forms via any medium
 is strictly prohibited.
 */

#ifndef TEXTUREMANAGER_HPP
#define TEXTUREMANAGER_HPP

#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <map>

class Renderer;

class TextureManager {
public:
    explicit TextureManager( Renderer& renderer );
    ~TextureManager();

    SDL_Texture* LoadTexture( const std::string& textureId );
    SDL_Texture* GetTexture( const std::string& textureId );
private:
    Renderer& m_renderer;
    std::map<std::string, SDL_Texture*> m_textureMap;


    TextureManager( const TextureManager& ) = delete;
    TextureManager& operator=( const TextureManager& ) = delete;
};

#endif //TEXTUREMANAGER_HPP
