#define SIMPLE_STRING_IMPL
#include "string.h"

#include <stdio.h>

int main(void) {
    // Define strings easily from old school char arrays
    string my_string = STR("Hello");
    string my_string2 = STR(" World");

    // Concatenation!
    APPEND(my_string, my_string2);
    APPEND(my_string, "!");

    // Access underlying char array for libc functions like printf
    char *original_array = ARRAY(my_string);

    // Access to the length of the string is O(1)
    printf("String \"%s\" of size %lu\n", original_array, LEN(my_string));

    string copy = STR(my_string); // Easy copy!

    if (COMPARE(my_string, copy) == 0) {
        printf("The two strings are equals!\n");
    }

    // Do not forget to free your strings
    free_string(my_string);
    free_string(my_string2);
    free_string(copy);

    return 0;
}
