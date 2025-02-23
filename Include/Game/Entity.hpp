/*
 Copyright (C) 2025 SequoiaDotDev. - All Rights Reserved

 Unauthorized copying or redistribution of this file in source and binary forms via any medium
 is strictly prohibited.
 */

#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <cstdint>

class Entity {
public:
    void Update();
private:
    uint64_t m_age;
};

#endif //ENTITY_HPP
