/*
 Copyright (C) 2025 SequoiaDotDev. - All Rights Reserved

 Unauthorized copying or redistribution of this file in source and binary forms via any medium
 is strictly prohibited.
 */

#ifndef WIDGET_HPP
#define WIDGET_HPP

struct Widget {
    virtual ~Widget() = default;

    virtual void Render( Renderer& renderer );
};

#endif //WIDGET_HPP
