/*
 Copyright (C) 2025 SequoiaDotDev. - All Rights Reserved

 Unauthorized copying or redistribution of this file in source and binary forms via any medium
 is strictly prohibited.
 */

#ifndef BOUNDINGBOX_HPP
#define BOUNDINGBOX_HPP

struct BoundingBox {
    int x, y, w, h;

    constexpr BoundingBox() : x(0), y(0), w(0), h(0) {}
    constexpr BoundingBox( const int x, const int y, const int w, const int h )
        : x( x ), y( y ), w( w ), h( h ) {}

    bool IsValid() const { return x >= 0 && y >= 0 && w >= 0 && h >= 0; }
    bool IsPointWithin( const int pX, const int pY ) const {
        return pX >= x && pX < x + w && pY >= y && pY < y + h;
    }
};

#endif //BOUNDINGBOX_HPP
