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

#endif // MEMLIB_ALLOC
