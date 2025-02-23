/*
 Copyright (C) 2025 SequoiaDotDev. - All Rights Reserved

 Unauthorized copying or redistribution of this file in source and binary forms via any medium
 is strictly prohibited.
 */

#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <SDL.h>
#include <memory>
#include <Artisan/Colors.hpp>
#include <Artisan/FontManager.hpp>
#include <Artisan/TextureManager.hpp>

class Window;

class Renderer {
public:
    explicit Renderer( const Window& window );
    ~Renderer();
    Renderer( const Renderer& ) = delete;
    Renderer& operator=( const Renderer& ) = delete;

    SDL_Renderer* GetRenderer() const;
    const TextureManager* GetTextureManager() const;
    void Clear() const;
    void SetColor( RGBA rgba ) const;
    // Geometry
    void DrawRect( const SDL_Rect& rect ) const;
    void FillRect( const SDL_Rect& rect ) const;
    void DrawLine( int x1, int y1, int x2, int y2 ) const;
    void DrawPoint( int x, int y ) const;
    // Textures
    SDL_Texture* LoadTexture( const std::string& texturePath ) const;
    SDL_Texture* GetTexture( const std::string& id ) const;
    void DrawTexture( SDL_Texture* texture, const SDL_Rect& destRect ) const;
    void DrawTexture( SDL_Texture* texture, const SDL_Rect& destRect, const SDL_Rect& srcRect ) const;
    // Fonts
    TTF_Font* LoadFont( const std::string& fontPath, int fontSize ) const;
    TTF_Font* GetFont( const std::string& fontId ) const;
    void DrawText( const std::string &text, int x, int y, TTF_Font *font, RGBA color ) const;
    //
    void Present() const;

private:
    SDL_Renderer* m_renderer;
    std::unique_ptr<TextureManager> m_textureManager;
    std::unique_ptr<FontManager> m_fontManager;
};

#endif //RENDERER_HPP
