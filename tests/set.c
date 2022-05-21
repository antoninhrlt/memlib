// This file is part of "memlib"
// Under the MIT License
// Copyright (c) 2022 Antonin Hérault

#include <stdio.h>

#include "memlib.h"

/**
 * You can try to run this test with "valgrind" to check memory errors :
 *  valgrind build/<platform>/<arch>/<release|debug>/test
*/

#define LEN 3

int main() {
    int* to_set = memlib_alloc(sizeof(int) * LEN);
    if (to_set == nullptr) {
        return -1;
    }

    memlib_set(to_set, 5, LEN);

    printf("%p : [%i, %i, %i]\n", to_set, to_set[0], to_set[1], to_set[2]);

    memlib_free(to_set);
    return 0;
}
