/*
 Copyright (C) 2025 SequoiaDotDev. - All Rights Reserved

 Unauthorized copying or redistribution of this file in source and binary forms via any medium
 is strictly prohibited.
 */

#include <iostream>
#include <stdexcept>
#include <Artisan/Renderer.hpp>
#include <Artisan/Window.hpp>
#include <Artisan/Colors.hpp>

Renderer::Renderer( const Window &window ) : m_renderer( nullptr ) {
    m_renderer = SDL_CreateRenderer( window.GetWindow(), -1, SDL_RENDERER_ACCELERATED );

    if ( m_renderer == nullptr ) {
        throw std::runtime_error( "Failed to create renderer: " + std::string( SDL_GetError() ) );
    }

    m_textureManager = std::make_unique<TextureManager>( *this );
    m_fontManager = std::make_unique<FontManager>();
}

Renderer::~Renderer() {
    m_textureManager.reset();

    if ( m_renderer != nullptr ) {
        SDL_DestroyRenderer( m_renderer );
        m_renderer = nullptr;
    }
}

SDL_Renderer *Renderer::GetRenderer() const { return m_renderer; }
const TextureManager* Renderer::GetTextureManager() const {
    return m_textureManager.get();
}


void Renderer::Clear() const {
    SDL_RenderClear( m_renderer );
}

void Renderer::SetColor( const RGBA rgba ) const {
    const auto [r, g, b, a] = rgba;
    SDL_SetRenderDrawColor( m_renderer, r, g, b, a );
}

void Renderer::DrawRect( const SDL_Rect& rect ) const {
    SDL_RenderDrawRect( m_renderer, &rect );
}

void Renderer::FillRect( const SDL_Rect& rect ) const {
    SDL_RenderFillRect( m_renderer, &rect );
}

void Renderer::DrawLine( const int x1, const int y1, const int x2, const int y2 ) const {
    SDL_RenderDrawLine( m_renderer, x1, y1, x2, y2 );
}

void Renderer::DrawPoint( const int x, const int y ) const {
    SDL_RenderDrawPoint( m_renderer, x, y );
}

SDL_Texture* Renderer::LoadTexture( const std::string& texturePath ) const {
   return m_textureManager->LoadTexture( texturePath );
}

SDL_Texture* Renderer::GetTexture( const std::string& id ) const {
    return m_textureManager->GetTexture( id );
}

void Renderer::DrawTexture( SDL_Texture* texture, const SDL_Rect& destRect ) const {
    SDL_RenderCopy( m_renderer, texture, nullptr, &destRect );
}

void Renderer::DrawTexture( SDL_Texture* texture, const SDL_Rect& destRect, const SDL_Rect& srcRect ) const {
    SDL_RenderCopy( m_renderer, texture, &destRect, &srcRect );
}

TTF_Font* Renderer::LoadFont( const std::string& fontPath, const int fontSize ) const {
    return m_fontManager->LoadFont( fontPath, fontSize );
}

TTF_Font* Renderer::GetFont( const std::string& fontId ) const {
     return m_fontManager->GetFont( fontId );
}

void Renderer::DrawText( const std::string& text, const int x, const int y, TTF_Font* font, RGBA color ) const {
    const auto[r, g, b, a] = color;
    SDL_Surface* surface = TTF_RenderText_Blended( font, text.c_str(), { r, g, b, a } );

    if ( surface == nullptr ) {
        std::cerr << "Failed to render text: " << TTF_GetError() << std::endl;
        return;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface( m_renderer, surface );

    if ( texture == nullptr ) {
        std::cerr << "Failed to create texture from surface: " << SDL_GetError()
              << std::endl;
        SDL_FreeSurface( surface );
        return;
    }

    const SDL_Rect destRect = { x, y, surface->w, surface->h };
    SDL_RenderCopy( m_renderer, texture, nullptr, &destRect );

    SDL_FreeSurface( surface );
    SDL_DestroyTexture( texture );
}


void Renderer::Present() const { SDL_RenderPresent( m_renderer ); }
