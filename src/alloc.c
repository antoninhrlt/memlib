// This file is part of "memlib"
// Under the MIT License
// Copyright (c) 2022 Antonin Hérault

#include "memlib/alloc.h"
#include "memlib/blocks.h"
#include "memlib/defs.h"
#include "memlib/utils.h"

#include <unistd.h>

extern BlockMeta BLOCK_BASE;

#define TO_RETURN   created_block + 1
#define REQUEST_SPACE(last) \
    created_block = memlib_request_space(last, size); \
    if (!created_block) { return nullptr; } // system failure

void* memlib_alloc(size_t size) {
    if (size <= 0) {
        return nullptr;
    }

    BlockMeta created_block;

    // When it's the first allocation, it directly requests some space to the
    // operating system
    if (!BLOCK_BASE) {
        REQUEST_SPACE(nullptr);
        BLOCK_BASE = created_block;
        return TO_RETURN;
    }

    BlockMeta last = BLOCK_BASE;
    created_block = memlib_find_free_block(&last, size);

    // No right block available for the requested allocation, a request to the 
    // operating system is done so.
    if (!created_block) {
        REQUEST_SPACE(last);
        return TO_RETURN;
    }

    // A free block was found and `created_block` is now assigned to the 
    // retrieved memory location.
    created_block->is_free = false;
    #ifdef DEBUG
        created_block->magic = 0x28869;
    #endif // DEBUG
    
    return TO_RETURN;
}

void memlib_free(void* pointer) {
    // Already freed
    if (!pointer) {
        return;
    }

    BlockMeta block = memlib_block_from_pointer(pointer);
    block->is_free = true;

    #ifdef DEBUG
        block->magic = 0x526783;
    #endif // DEBUG
}

void* memlib_realloc(void* pointer, size_t size) {
    // Already freed
    if (!pointer) {
        return nullptr;
    }

    BlockMeta block = memlib_block_from_pointer(pointer);

    // Enough space, it simply returns the same memory block 
    if (block->size >= size) {
        return pointer;
    }

    // Real new allocation
    void* new = memlib_alloc(size);
    if (!new) {
        return NULL; // system failure
    }

    memlib_copy(new, pointer, block->size);
    memlib_free(pointer);
    return new;
}
