/*
 Copyright (C) 2025 SequoiaDotDev. - All Rights Reserved

 Unauthorized copying or redistribution of this file in source and binary forms via any medium
 is strictly prohibited.
 */

#ifndef CHECKBOX_HPP
#define CHECKBOX_HPP

#include <utility>

#include <Artisan/UI/Widget.hpp>

struct Checkbox final : Widget {
    bool* checked;
    std::string label;
    RGBA uncheckedColor = RGBA( 0x0A0A0AFF );
    RGBA checkedColor = Colors::Cyan;
    RGBA labelColor = Colors::White;

    Checkbox( bool* checked, std::string label )
        : checked( checked ), label(std::move( label )) {}

    Checkbox( bool* checked,
        std::string label,
        const RGBA uncheckedColor,
        const RGBA checkedColor,
        const RGBA labelColor
    ) : checked( checked ),
        label ( std::move ( label ) ),
        uncheckedColor( uncheckedColor ),
        checkedColor( checkedColor ),
        labelColor( labelColor ) {}

    void Render( Renderer& renderer ) override {

    }

};

#endif //CHECKBOX_HPP
