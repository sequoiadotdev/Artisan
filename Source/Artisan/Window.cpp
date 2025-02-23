/*
 Copyright (C) 2025 SequoiaDotDev. - All Rights Reserved

 Unauthorized copying or redistribution of this file in source and binary forms via any medium
 is strictly prohibited.
 */

#include <chrono>
#include <stdexcept>
#include <thread>
#include <iostream>
#include <Artisan/Window.hpp>
#include <Artisan/Keybind.hpp>
#include <Artisan/Colors.hpp>

Window::Window( const std::string &title, const int width, const int height )
    : m_window( nullptr ), m_height( height ), m_width( width ) {
    m_window = SDL_CreateWindow( title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN );

    if ( m_window == nullptr ) {
        throw std::runtime_error( "Failed to create window: " + std::string(SDL_GetError()) );
    }

    try {
        m_renderer = std::make_unique<Renderer>( *this );
    } catch ( [[maybe_unused]] const std::exception &e ) {
        SDL_DestroyWindow( m_window );
        throw;
    }
}

Window::~Window() {
    if ( m_window != nullptr ) {
        SDL_DestroyWindow( m_window );
        m_window = nullptr;
    }
}

void Window::SetScene( std::unique_ptr<Scene> scene ) {
    if ( m_scene ) {
        m_scene->Cleanup();
    }

    m_scene = std::move( scene );

    if ( m_scene ) {
        m_scene->Init();
    }
}

void Window::Run() const {
    if ( !m_scene ) {
        throw std::runtime_error( "No scene set before running the window!" );
    }
    MainLoop();
}

void Window::MainLoop() const {
    bool running = true;
    SDL_Event event;

    constexpr float targetFrameTime = 1.0f / 60.0f;
    auto lastTime = std::chrono::high_resolution_clock::now();

    while ( running ) {
        auto startTime = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> deltaTime = startTime - lastTime;
        lastTime = startTime;

        while ( SDL_PollEvent( &event ) ) {
            if ( event.type == SDL_QUIT ) {
                running = false;
            }

            if ( event.type == SDL_KEYDOWN || event.type == SDL_KEYUP ) {
                Keybind::Update( event );
            }
        }

        if ( m_scene ) {
            m_scene->Update( deltaTime.count() );
        }

        m_renderer->SetColor( Colors::Black );
        m_renderer->Clear();

        if ( m_scene ) {
            m_scene->Render( *m_renderer );
        }

        auto endTime = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> frameDuration = endTime - startTime;

        m_renderer->DrawText(
            "MSPF: " + std::to_string( frameDuration.count() * 1000.0f ) + "ms",
            20, 20,
            m_renderer->GetFont("PixelifySans-Regular_18"),
            Colors::White
        );

        m_renderer->Present();

        if ( frameDuration.count() > 0.01667f ) {
            std::cout << "Warning: Game running behind, Expected maximum frame time of "
                      << "16.67ms, But took " << ( frameDuration.count() * 1000.0f ) << "ms!" << std::endl;
        }


        if (frameDuration.count() < targetFrameTime) {
            std::this_thread::sleep_for( std::chrono::duration<float>( targetFrameTime - frameDuration.count() ) );
        }
    }
}

const std::unique_ptr<Renderer>& Window::GetRenderer() const { return m_renderer; }
SDL_Window *Window::GetWindow() const { return m_window; }
int Window::GetHeight() const { return m_height; }
int Window::GetWidth() const { return m_width; }