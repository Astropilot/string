#ifndef SIMPLE_STRING_H
#define SIMPLE_STRING_H

#include <string.h>
#include <stdlib.h>
#include <stdint.h>

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

/* String buffer
##################################################################
# string length (uint64_t) # buffer capacity (uint64_t) # buffer #
##################################################################
*/
typedef char* string;

/* Function declarations */

SIMPLE_STRING_API
string new_string(const char *str);

SIMPLE_STRING_API
void free_string(string str);

SIMPLE_STRING_API
string append_string(string str, string to_append);

SIMPLE_STRING_API
string append_array(string str, const char *to_append);

SIMPLE_STRING_API
string copy_string(string str);

SIMPLE_STRING_API
size_t string_len(string str);

/* Internal utils */
#define CAPACITY_SIZE sizeof(uint64_t)
#define LENGTH_SIZE sizeof(uint64_t)

#define STR_BUFFER_PTR(str_ptr) (str_ptr - CAPACITY_SIZE - LENGTH_SIZE)
#define STR_CAPACITY(str_ptr) (uint64_t)*(str_ptr - CAPACITY_SIZE)
#define STR_CAPACITY_PTR(str_ptr) (str_ptr - CAPACITY_SIZE)
#define STR_LEN(str_ptr) (uint64_t)*(STR_BUFFER_PTR(str_ptr))
#define STR_LEN_PTR(str_ptr) (STR_BUFFER_PTR(str_ptr))

#define BUFFER_STR_PTR(buf_ptr) (buf_ptr + CAPACITY_SIZE + LENGTH_SIZE)
#define BUFFER_CAPACITY_PTR(buf_ptr) (buf_ptr + LENGTH_SIZE)
#define BUFFER_LEN_PTR(buf_ptr) (buf_ptr)

#define NULL_GUARD(ptr, return_val) if (ptr == NULL) return (return_val);
#define NULL_GUARD_VOID(ptr) if (ptr == NULL) return;
#define SAFE_FREE(ptr) if (ptr != NULL) _SIMPLE_STRING_FREE(ptr);


/* Public utils */
#define STR(str) new_string(str)
#define COPY(str) copy_string(str)
#define APPEND_STR(str, to_append) (str) = append_string(str, to_append)
#define APPEND_ARR(str, to_append) (str) = append_array(str, to_append)

#endif /* SIMPLE_STRING_H */



#ifdef SIMPLE_STRING_IMPL

string new_string(const char *str) {
    NULL_GUARD(str, NULL)

    size_t str_len = strlen(str);
    string m_str = (string) _SIMPLE_STRING_MALLOC(CAPACITY_SIZE + LENGTH_SIZE + (sizeof(char) * (str_len + 1)));

    *BUFFER_LEN_PTR(m_str) = str_len;
    *BUFFER_CAPACITY_PTR(m_str) = str_len + 1;

    strcpy(BUFFER_STR_PTR(m_str), str);

    return BUFFER_STR_PTR(m_str);
}

string copy_string(string str) {
    NULL_GUARD(str, NULL)

    size_t str_capacity = STR_CAPACITY(str);
    string m_str = (string) _SIMPLE_STRING_MALLOC(CAPACITY_SIZE + LENGTH_SIZE + (sizeof(char) * str_capacity));

    memcpy(m_str, STR_BUFFER_PTR(str), CAPACITY_SIZE + LENGTH_SIZE + (sizeof(char) * str_capacity));

    return BUFFER_STR_PTR(m_str);
}

void free_string(string str) {
    NULL_GUARD_VOID(str)

    string buffer = STR_BUFFER_PTR(str);

    SAFE_FREE(buffer)
}

string append_string(string str, string to_append) {
    NULL_GUARD(str, NULL)
    NULL_GUARD(to_append, NULL)

    size_t str_len = STR_LEN(str);
	size_t to_append_len = STR_LEN(to_append);
	size_t total_len = str_len + to_append_len + 1;
    string str_buffer = STR_BUFFER_PTR(str);

	if (total_len > STR_CAPACITY(str)) {
		size_t new_capacity = total_len * 1.5;

		str_buffer = _SIMPLE_STRING_REALLOC(STR_BUFFER_PTR(str), CAPACITY_SIZE + LENGTH_SIZE + (new_capacity * sizeof(char)));
		*BUFFER_CAPACITY_PTR(str_buffer) = new_capacity;
	}
	strcat(BUFFER_STR_PTR(str_buffer), to_append);
	*BUFFER_LEN_PTR(str_buffer) = total_len - 1;

    return BUFFER_STR_PTR(str_buffer);
}

string append_array(string str, const char *to_append) {
    NULL_GUARD(str, NULL)
    NULL_GUARD(to_append, NULL)

    size_t str_len = STR_LEN(str);
	size_t to_append_len = strlen(to_append);
	size_t total_len = str_len + to_append_len + 1;
    string str_buffer = STR_BUFFER_PTR(str);

	if (total_len > STR_CAPACITY(str)) {
		size_t new_capacity = total_len * 1.5;

		str_buffer = _SIMPLE_STRING_REALLOC(STR_BUFFER_PTR(str), CAPACITY_SIZE + LENGTH_SIZE + (new_capacity * sizeof(char)));
		*BUFFER_CAPACITY_PTR(str_buffer) = new_capacity;
	}
	strcat(BUFFER_STR_PTR(str_buffer), to_append);
	*BUFFER_LEN_PTR(str_buffer) = total_len - 1;

    return BUFFER_STR_PTR(str_buffer);
}

size_t string_len(string str) {
    NULL_GUARD(str, 0)

    return (size_t) STR_LEN(str);
}

/* We clear all internals directives for preventing public use */

#undef CAPACITY_SIZE
#undef LENGTH_SIZE

#undef STR_BUFFER_PTR
#undef STR_CAPACITY
#undef STR_CAPACITY_PTR
#undef STR_LEN
#undef STR_LEN_PTR

#undef BUFFER_STR_PTR
#undef BUFFER_CAPACITY_PTR
#undef BUFFER_LEN_PTR

#undef NULL_GUARD
#undef SAFE_FREE

#endif /* SIMPLE_STRING_IMPL */
