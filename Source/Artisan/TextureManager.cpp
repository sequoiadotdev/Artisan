/*
 Copyright (C) 2025 SequoiaDotDev. - All Rights Reserved

 Unauthorized copying or redistribution of this file in source and binary forms via any medium
 is strictly prohibited.
 */

#include <iostream>
#include <ranges>
#include <Artisan/TextureManager.hpp>
#include <Artisan/Renderer.hpp>

TextureManager::TextureManager( Renderer& renderer ) : m_renderer( renderer ) {
    if ( !IMG_Init( IMG_INIT_PNG | IMG_INIT_JPG ) ) {
        std::cerr << "SDL_image initialization failed: " << IMG_GetError()
              << std::endl;
    }
}

TextureManager::~TextureManager() {
    for ( const auto& texture : m_textureMap | std::views::values ) {
        SDL_DestroyTexture( texture );
    }

    m_textureMap.clear();
}

SDL_Texture* TextureManager::LoadTexture( const std::string& textureId ) {
    if ( m_textureMap.contains( textureId ) ) {
        return m_textureMap[ textureId ];
    }

    SDL_Texture* texture = IMG_LoadTexture( m_renderer.GetRenderer(), ("Assets/Textures/" + textureId).c_str() );
    if ( !texture ) {
        std::cerr << "TextureManager: Failed to load texture!" << std::endl;
        return nullptr;
    }

    m_textureMap[ textureId ] = texture;
    return texture;
}

SDL_Texture* TextureManager::GetTexture( const std::string& textureId ) {
    if ( m_textureMap.contains( textureId ) ) {
        return m_textureMap[ textureId ];
    }

    return nullptr;
}
