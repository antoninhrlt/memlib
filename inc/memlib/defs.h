// This file is part of "memlib"
// Under the MIT License
// Copyright (c) 2022 Antonin Hérault

#ifndef MEMLIB_DEFS
#define MEMLIB_DEFS

#define nullptr 0

typedef long unsigned int  size_t;

/**
 * Implementation for the boolean type
*/
typedef enum e_bool {
    true = 1,
    false = 0
} bool; // to looks like a native type

#endif // MEMLIB_DEFS
