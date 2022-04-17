# Simple Strings for C

A header-only pure C library to manipulate more easily string in C for my personal usage

```c
#define SIMPLE_STRING_IMPL
#include "string.h"

#include <stdio.h>
#include <string.h>

int main(void) {
    // Define strings easily from old school char arrays
    string my_string = STR("Hello");
    string my_string2 = STR(" World");

    // Concatenation!
    APPEND_STR(my_string, my_string2);
    APPEND_ARR(my_string, "!");

    // Access to the length of the string is O(1)
    printf("String \"%s\" of size %lu\n", my_string, string_len(my_string));

    string copy = COPY(my_string); // Easy copy!

    if (strcmp(my_string, copy) == 0) {
        printf("The two strings are equals!\n");
    }

    // Modify string easily
    copy[0] = 'B';

    printf("Copy \"%s\" of size %lu\n", copy, string_len(copy));

    if (strcmp(my_string, copy) != 0) {
        printf("The two strings are not equals!\n");
    }

    // Do not forget to free your strings
    free_string(my_string);
    free_string(my_string2);
    free_string(copy);

    return 0;
}
```
