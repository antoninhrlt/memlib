// This file is part of "memlib"
// Under the MIT License
// Copyright (c) 2022 Antonin Hérault

#ifndef MEMLIB_ALLOC
#define MEMLIB_ALLOC

#include "defs.h"

/**
 * Reserve a memory block by searching available space or asking to the 
 * operating system
*/
void* memlib_alloc(size_t size);

/**
 * Set the memory block of `pointer` as free to be used again
*/
void memlib_free(void* pointer);

/**
 * Free the allocated space (thanks to its pointer) and do a call to 
 * `memlib_alloc`, this means that the space memory block will be used if the 
 * size is the same or a new block will be allocated if the size was increased
*/
void* memlib_realloc(void* pointer, size_t size);

// TODO : memlib_calloc()

#endif // MEMLIB_ALLOC
