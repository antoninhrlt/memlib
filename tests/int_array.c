// This file is part of "memlib"
// Under the MIT License
// Copyright (c) 2022 Antonin Hérault

#include <stdio.h>

#include "memlib.h"

/**
 * You can try to run this test with "valgrind" to check memory errors :
 *  valgrind build/<platform>/<arch>/<release|debug>/test
*/

int main() {
    int* array = memlib_alloc(sizeof(int) * 10);
    if (array == nullptr) {
        return -1;
    }

    array[0] = 1;
    array[1] = 2;
    array[2] = 3;

    printf("%p : [%i, %i, %i]\n", array, array[0], array[1], array[2]);

    memlib_free(array);
    return 0;
}
