// This file is part of "memlib"
// Under the MIT License
// Copyright (c) 2022 Antonin Hérault

#ifndef MEMLIB_ALLOC
#define MEMLIB_ALLOC

#include "defs.h"

void* memlib_alloc(size_t size);
void memlib_free(void* pointer);

#endif // MEMLIB_ALLOC
