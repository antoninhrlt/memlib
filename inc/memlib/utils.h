// This file is part of "memlib"
// Under the MIT License
// Copyright (c) 2022 Antonin Hérault

#ifndef MEMLIB_UTILS
#define MEMLIB_UTILS

#include "defs.h"

/**
 * Copy the content of a block thanks to its pointer to another one
*/
void memlib_copy(void* dest, const void* source, size_t size);

/**
 * Do a comparaison between two memory blocks
*/
bool memlib_comp(const void* first, const void* second, size_t size);

/**
 * Fill a memory block with an unique value until `size`
*/
void memlib_set(void* dest, int fill_value, size_t size);

#endif // MEMLIB_UTILS
