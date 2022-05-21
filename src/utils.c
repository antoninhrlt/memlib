// This file is part of "memlib"
// Under the MIT License
// Copyright (c) 2022 Antonin Hérault

#include "memlib/defs.h"
#include "memlib/utils.h"

void memlib_copy(void* dest, const void* source, size_t size) {
    for (size_t i; i < size; i++) {
        ((int*) dest)[i] = ((int*) source)[i];
    }
}

bool memlib_comp(const void* first, const void* second, size_t size) {
    for (size_t i; i < size; i++) {
        if (((int*) first)[i] != ((int*) second)[i]) {
            return false;
        }
    }

    return true;
}

void memlib_set(void* dest, int fill_value, size_t size) {
    for (size_t i; i < size; i++) {
        ((int*) dest)[i] = fill_value;
    }
}
