# memlib
Memory allocations and management library written in C to be used without the standard library

## Get started
The project is using [xmake](https://xmake.io) and it requires to have this tool
installed on your computer.
- `git clone https://github.com/antoninhrlt/memlib`
- `cd memlib`
- `xmake install` (or `xmake install -o <target folder>`)

The library is now installed on your computer and you can start using it !

## Example
```c
int array[] = {1, 2, 3};
int* copy = memlib_alloc(sizeof(int) * 3);

memlib_copy(copy, array, 3);

printf("%p : [%i, %i, %i]\n", copy, copy[0], copy[1], copy[2]);
// Indicate if both arrays are the same
printf("? %s\n", memlib_comp(array, copy, 3) ? "true" : "false");

memlib_free(copy);
```
