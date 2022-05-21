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
    int array[] = {1, 2, 3};
    int* copy = memlib_alloc(sizeof(int) * LEN);
    if (copy == nullptr) {
        return -1;
    }

    memlib_copy(copy, array, LEN);

    printf("%p : [%i, %i, %i]\n", copy, copy[0], copy[1], copy[2]);
    printf("? %s\n", memlib_comp(array, copy, LEN) ? "true" : "false");

    memlib_free(copy);
    return 0;
}
