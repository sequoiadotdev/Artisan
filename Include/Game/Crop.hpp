/*
 Copyright (C) 2025 SequoiaDotDev. - All Rights Reserved

 Unauthorized copying or redistribution of this file in source and binary forms via any medium
 is strictly prohibited.
 */

#ifndef CROP_HPP
#define CROP_HPP
#include <cstdint>

#include <Game/Block.hpp>

class Crop : public Block {
public:
    void Update() override;
private:
    uint64_t m_age;
};

#endif //CROP_HPP
