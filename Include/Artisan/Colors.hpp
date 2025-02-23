/*
 Copyright (C) 2025 SequoiaDotDev. - All Rights Reserved

 Unauthorized copying or redistribution of this file in source and binary forms via any medium
 is strictly prohibited.
 */

#ifndef COLORS_HPP
#define COLORS_HPP

#include <cstdint>

struct RGBA {
    uint8_t r, g, b, a;

    constexpr RGBA( const uint8_t r, const uint8_t g, const uint8_t b, const uint8_t a = 255 )
        : r( r ), g( g ), b( b ), a( a ) {}

    explicit constexpr RGBA( const uint32_t color )
        : r ( color >> 24 & 0xFF ),
        g ( color >> 16 & 0xFF ),
        b ( color >> 8 & 0xFF ),
        a ( color & 0xFF ) {}

    static constexpr RGBA FromRGB( const uint32_t rgb ) {
        return {
            static_cast<uint8_t>( rgb >> 16 & 0xFF ),
            static_cast<uint8_t>( rgb >> 8 & 0xFF ),
            static_cast<uint8_t>( rgb & 0xFF ),
            0xFF
        };
    }
};

namespace Colors {
    constexpr RGBA White       { 255, 255, 255 };
    constexpr RGBA Black       { 000, 000, 000 };
    constexpr RGBA Red         { 255, 000, 000 };
    constexpr RGBA Green       { 000, 255, 000 };
    constexpr RGBA Blue        { 000, 000, 255 };
    constexpr RGBA Yellow      { 255, 255, 000 };
    constexpr RGBA Cyan        { 000, 255, 255 };
    constexpr RGBA Magenta     { 255, 000, 255 };
    constexpr RGBA Transparent { 000, 000, 000, 000 };
}

#endif //COLORS_HPP
