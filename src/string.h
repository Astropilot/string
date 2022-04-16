#ifndef SIMPLE_STRING_H
#define SIMPLE_STRING_H

#include <string.h>
#include <stdlib.h>

#define SIMPLE_STRING_VERSION_MAJOR 0
#define SIMPLE_STRING_VERSION_MINOR 1
#define SIMPLE_STRING_VERSION_PATCH 0

#ifndef SIMPLE_STRING_API
#define SIMPLE_STRING_API extern
#endif

#if !defined(_SIMPLE_STRING_NODEFAULT_ALLOCATORS)
	#define _SIMPLE_STRING_MALLOC(_size)        malloc(_size)
    #define _SIMPLE_STRING_REALLOC(_ptr, _size) realloc(_ptr, _size)
	#define _SIMPLE_STRING_FREE(_ptr)           free(_ptr)
#endif

typedef struct string_internal {
    char *buf;
    size_t capacity;
    size_t buf_len;

} string_internal;

typedef string_internal* string;


SIMPLE_STRING_API
string new_string(const char *str);

SIMPLE_STRING_API
void free_string(string str);

SIMPLE_STRING_API
void append_string(string str, string to_append);

SIMPLE_STRING_API
void append_array(string str, const char *to_append);

SIMPLE_STRING_API
string copy_string(string str);

#define STR(str) \
_Generic(str, char*: new_string, string: copy_string)((str))
#define ARRAY(str) str->buf
#define LEN(str) str->buf_len
#define APPEND(str, to_append) \
_Generic(to_append, string: append_string, char*: append_array)((str), (to_append))
#define COMPARE(str1, str2) strcmp((str1->buf), (str2->buf))

#define NULL_GUARD(ptr) if (ptr == NULL) return;
#define SAFE_FREE(ptr) if (ptr != NULL) _SIMPLE_STRING_FREE(ptr);

#endif /* SIMPLE_STRING_H */



#ifdef SIMPLE_STRING_IMPL

string new_string(const char *str) {
    string_internal *m_str = (string_internal*) _SIMPLE_STRING_MALLOC(sizeof(string_internal));
    size_t str_len = strlen(str);

    m_str->buf = (char*) _SIMPLE_STRING_MALLOC(sizeof(char) * (str_len + 1));
    m_str->buf_len = str_len;
    m_str->capacity = str_len + 1;

    strcpy(m_str->buf, str);

    return m_str;
}

void free_string(string str) {
    NULL_GUARD(str)

    SAFE_FREE(str->buf)
    SAFE_FREE(str)
}

void append_string(string str, string to_append) {
    size_t str_len = str->buf_len;
	size_t to_append_len = to_append->buf_len;
	size_t total_len = str_len + to_append_len + 1;

	if (total_len > str->capacity) {
		size_t new_capacity = total_len * 1.5;

		str->buf = _SIMPLE_STRING_REALLOC(str->buf, new_capacity * sizeof(char));
		str->capacity = new_capacity;
	}
	strcat(str->buf, to_append->buf);
	str->buf_len = total_len - 1;
}

void append_array(string str, const char *to_append) {
    size_t str_len = str->buf_len;
	size_t to_append_len = strlen(to_append);
	size_t total_len = str_len + to_append_len + 1;

	if (total_len > str->capacity) {
		size_t new_capacity = total_len * 1.5;

		str->buf = _SIMPLE_STRING_REALLOC(str->buf, new_capacity * sizeof(char));
		str->capacity = new_capacity;
	}
	strcat(str->buf, to_append);
	str->buf_len = total_len - 1;
}

string copy_string(string str) {
    return new_string(str->buf);
}

#endif /* SIMPLE_STRING_IMPL */
