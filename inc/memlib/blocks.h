// This file is part of "memlib"
// Under the MIT License
// Copyright (c) 2022 Antonin Hérault

#ifndef MEMLIB_BLOCK
#define MEMLIB_BLOCK

#include "defs.h"

/**
 * Meta information on a memory block. This way permits to store information 
 * when an allocation is made to free it later
*/
typedef struct s_block_meta {
    size_t size;
    // "BlockMeta" is not used in the code because not already defined, it's 
    // forced-fully to use the type "as raw"
    struct s_block_meta* next;
    bool is_free;
    
    #ifdef DEBUG
        int magic;
    #endif // DEBUG
} *BlockMeta;

/**
 * This solution permits to use free space when it's possible. Well, if you 
 * allocate a block then you free it, it should be possible to re-use it.
 * When no space is found, `request_space` should be called
*/
BlockMeta memlib_find_free_block(BlockMeta* last, size_t size);

/**
 * Request to the operating system space for allocation. 
 * Used when `find_free_block` haven't found anything correct for the requested
 * block allocation
*/
BlockMeta memlib_request_space(BlockMeta last, size_t size);

#endif // MEMLIB_BLOCK
