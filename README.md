<h1 align="center">
  <br>
  Simple Strings for C
</h1>

<p align="center">
    <a href="https://github.com/Astropilot/string/actions?query=workflow%3ATests">
        <img src="https://github.com/Astropilot/string/workflows/Tests/badge.svg" alt="Test">
    </a>
    <a href="https://codecov.io/gh/Astropilot/string" target="_blank">
        <img src="https://img.shields.io/codecov/c/github/Astropilot/string?color=%2334D058" alt="Coverage">
    </a>
    <img src="https://img.shields.io/badge/language-C-blue.svg">
    <a href="https://github.com/Astropilot/string/blob/main/LICENSE">
        <img src="https://img.shields.io/github/license/Astropilot/string" alt="MIT License">
    </a>
    <img src="https://img.shields.io/badge/made%20with-%E2%9D%A4%EF%B8%8F-yellow.svg">
</p>

<p align="center">
  <a href="#about">About</a> •
  <a href="#usage">Usage</a> •
  <a href="#contributing">Contributing</a> •
  <a href="#authors">Authors</a> •
  <a href="#license">License</a>
</p>

## About

A header-only pure C library to manipulate more easily string in C for my personal usage.

This library is under development and some functions are not/partially implemented, please do not use this library for serious projects.

Although I try to pay attention to the performance of the functions, this library does not aim to provide the best in terms of speed or memory saving.

## Usage

```c
#define SIMPLE_STRING_IMPL
#include "string.h"

#include <stdio.h>
#include <string.h>

int main(void) {
    // Define strings easily from old school char arrays
    string my_string = STR("Hello"); // Use macro shortcut
    string my_string2 = spls_new_string(" World"); // Or full function

    // Concatenation!
    APPEND_STR(my_string, my_string2);
    APPEND_ARR(my_string, "!");

    // Access to the length of the string is O(1)
    printf("String \"%s\" of size %lu\n", my_string, spls_len(my_string));

    string copy = CLONE(my_string); // Easy copy!

    if (strcmp(my_string, copy) == 0) {
        printf("The two strings are equals!\n");
    }

    // Modify string easily
    copy[0] = 'B';

    printf("Copy \"%s\" of size %lu\n", copy, spls_len(copy));

    if (strcmp(my_string, copy) != 0) {
        printf("The two strings are not equals!\n");
    }

    // Do not forget to free your strings
    spls_free_string(my_string);
    spls_free_string(my_string2);
    spls_free_string(copy);

    return 0;
}
```

**Important**: Never use `string` in libc or third-party functions that will change
the size of the string! All subsequents call to my library will mostly fail or give
undesired behaviors!

### All functions

Full documentation will come later...

```c
string spls_new_string(const char *str);

void spls_free_string(string str);

string spls_clone(const string str);

size_t spls_len(const string str);

string spls_append_string(string str, string to_append);

string spls_append_array(string str, const char *to_append);

string spls_capitalize(const string str);

string spls_tolower(const string str);

string spls_toupper(const string str);

unsigned int spls_count(const string str, const string search, unsigned int start, unsigned int end);

bool spls_startswith(const string str, const string value);

bool spls_endswith(const string str, const string value);

int spls_find(const string str, const string search, unsigned int start, unsigned int end);

bool spls_isalnum(const string str);

bool spls_isalpha(const string str);

bool spls_isdigit(const string str);

bool spls_islower(const string str);

bool spls_isupper(const string str);

bool spls_isprintable(const string str);

bool spls_isspace(const string str);

string spls_strip(const string str, const string characters);

string spls_lstrip(const string str, const string characters);

string spls_rstrip(const string str, const string characters);

string spls_replace(const string str, const string old_value, const string new_value, unsigned int count);

string* spls_split(const string str, const string separator, unsigned int maxsplit);

string* spls_splitlines(const string str, bool keeplinebreaks);
```

## Contributing

The project is open for contributions! [Open an Issue](https://github.com/Astropilot/string/issues/new) to propose new features/report a bug or directly make a pull request if you want to implement/fix it yourself. Please respect the conventions defined by editorconfig!

## Authors

|            |               Github profile                |   Discord   |
| ---------- | :-----------------------------------------: | :---------: |
| Astropilot | [Astropilot](https://github.com/Astropilot) | [Anos]#2347 |

## License

MIT - See LICENSE file
