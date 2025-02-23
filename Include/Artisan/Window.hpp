/*
 Copyright (C) 2025 SequoiaDotDev. - All Rights Reserved

 Unauthorized copying or redistribution of this file in source and binary forms via any medium
 is strictly prohibited.
 */

#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SDL.h>
#include <string>
#include <memory>
#include <Artisan/Renderer.hpp>
#include <Artisan/Scene.hpp>

class Window {
public:
    Window( const std::string& title, int width, int height );
    ~Window();
    Window( const Window& ) = delete;
    Window& operator=( const Window& ) = delete;

    void SetScene( std::unique_ptr<Scene> scene );
    void Run() const;

    [[nodiscard]] SDL_Window *GetWindow() const;
    [[nodiscard]] const std::unique_ptr<Renderer>& GetRenderer() const;
    [[nodiscard]] int GetWidth() const;
    [[nodiscard]] int GetHeight() const;
private:
    SDL_Window *m_window;
    std::unique_ptr<Renderer> m_renderer;
    std::unique_ptr<Scene> m_scene;
    int m_height, m_width;

    void MainLoop() const;
};

#endif //WINDOW_HPP
