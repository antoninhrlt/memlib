// This file is part of "memlib"
// Under the MIT License
// Copyright (c) 2022 Antonin Hérault

#include "memlib/blocks.h"
#include "memlib/defs.h"

BlockMeta BLOCK_BASE;

BlockMeta memlib_block_from_pointer(void* pointer) {
    return (BlockMeta) pointer - 1;
}

BlockMeta memlib_find_free_block(BlockMeta* last, size_t size) {
    BlockMeta current = BLOCK_BASE;
    
    // Finds if the next block is free and if the size is correct for the asked 
    // block to allocated
    while (current && !(current->is_free && current->size >= size)) {
        *last = current;
        current = current->next;
    }

    return current;
}

BlockMeta memlib_request_space(BlockMeta last, size_t size) {
    BlockMeta created_block = sbrk(0);

    void* request = sbrk(size + sizeof(BlockMeta));
    if (request == nullptr) {
        return nullptr;
    }

    if (last) {
        last->next = created_block;
    }

    created_block->size = size;
    created_block->next = nullptr;
    created_block->is_free = false;
    
    #ifdef DEBUG
        created_block->magic = 0x90274;
    #endif // DEBUG

    return created_block;
}
