// This file is part of "memlib"
// Under the MIT License
// Copyright (c) 2022 Antonin Hérault

#include "memlib/alloc.h"
#include "memlib/defs.h"

#include <unistd.h>

void* memlib_alloc(size_t size) {
    void* allocated = sbrk(0);
    void* request = sbrk(size);
    if (request == nullptr) {
        return nullptr;
    }
    return allocated;
}

void memlib_free(void* pointer) {}
