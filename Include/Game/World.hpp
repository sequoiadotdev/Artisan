/*
 Copyright (C) 2025 SequoiaDotDev. - All Rights Reserved

 Unauthorized copying or redistribution of this file in source and binary forms via any medium
 is strictly prohibited.
 */

#ifndef WORLD_HPP
#define WORLD_HPP

#include <vector>

#include <Game/Block.hpp>
#include <Game/Entity.hpp>

class World {
public:
    World();
    ~World();

    void Update();
    void Save();
    void Load();
private:
    uint64_t m_worldTime;
    std::vector<Entity> m_entities;
    std::vector<Block> m_blocks;
};

#endif //WORLD_HPP
