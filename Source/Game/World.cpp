/*
 Copyright (C) 2025 SequoiaDotDev. - All Rights Reserved

 Unauthorized copying or redistribution of this file in source and binary forms via any medium
 is strictly prohibited.
 */

#include <Game/World.hpp>

void World::Update() {
    m_worldTime++;

    for ( auto& entity : m_entities ) {
        entity.Update();
    }

    for ( auto& block : m_blocks ) {
        block.Update();
    }
}
