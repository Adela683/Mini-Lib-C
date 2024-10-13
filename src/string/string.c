// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source) {
    //https://www.techiedelight.com/implement-strcpy-function-c/
    if (destination == NULL) {
        return NULL;
    }

    // take a pointer pointing to the beginning of the destination string
    char *ptr = destination;

    // copy the C-string pointed by source into the array
    // pointed by destination
    while (*source != '\0') {
        *destination = *source;
        destination++;
        source++;
    }

    // include the terminating null character
    *destination = '\0';

    // the destination is returned by standard `strcpy()`
    return ptr;
}

char *strncpy(char *destination, const char *source, size_t len) {
    // return if dest and src is NULL
    if ((destination == NULL) && (source == NULL))
        return NULL;
    // take a pointer pointing to the beginning of dest string
    char *start = destination;
    // copy first n characters of C-string pointed by src
    // into the array pointed by dest
    while (len--) {
        *destination = *source;
        destination++;
        source++;
    }
    // null terminate dest string
    //*destination = '\0';
    return start;
}

char *strcat(char *destination, const char *source) {
    //https://www.techiedelight.com/implement-strcat-function-c/
    // make `ptr` point to the end of the destination string
    char *ptr = destination + strlen(destination);

    // appends characters of the source to the destination string
    while (*source != '\0') {
        *ptr++ = *source++;
    }

    // null terminate destination string
    *ptr = '\0';

    return destination;
}

char *strncat(char *destination, const char *source, size_t len) {
    // make `ptr` point to the end of the destination string
    char *ptr = destination + strlen(destination);

    // Appends characters of the source to the destination string
    while (*source != '\0' && len) {
        len--;
        *ptr++ = *source++;
    }

    // null terminate destination string
    *ptr = '\0';

    return destination;
}

int strcmp(const char *str1, const char *str2) {
    //https://musl.libc.org/
    for (; *str1 == *str2 && *str1; str1++, str2++)
        ;
    return *(unsigned char *)str1 - *(unsigned char *)str2;
}

int strncmp(const char *str1, const char *str2, size_t len) {
    //https://musl.libc.org/
    if (!len--)
        return 0;
    for (; *str1 == *str2 && *str1 && *str2 && len; str1++, str2++, len--)
        ;
    return *(unsigned char *)str1 - *(unsigned char *)str2;
}

size_t strlen(const char *str) {
    size_t i = 0;

    for (; *str != '\0'; str++, i++)
        ;

    return i;
}

char *strchr(const char *str, int c) {
    while (*str != c && *str != '\0') {
        str++;
    }
    if (*str == c) {
        return (char *)str;
    } else {
        return NULL;
    }
}

char *strrchr(const char *str, int c) {
    int len = strlen(str);
    str = str + len;
    while (*str != c && len) {
        str--;
        len--;
    }
    if (*str == c) {
        return (char *)str;
    } else {
        return NULL;
    }
}

char *strstr(const char *haystack, const char *needle) {
    if (haystack == NULL || needle == NULL) {
        return NULL;
    }

    const char *h, *n;

    for (; *haystack; haystack++) {
        for (h = haystack, n = needle; *h && *n && (*h == *n); ++h, ++n)
            ;
        if (*n == '\0') {
            return (char *)haystack;
        }
    }
    return NULL;
}

char *strrstr(const char *haystack, const char *needle) {
    if (haystack == NULL || needle == NULL) {
        return NULL;
    }

    const char *h, *n;
    char *result = NULL;

    for (; *haystack; haystack++) {
        for (h = haystack, n = needle; *h && *n && (*h == *n); ++h, ++n)
            ;
        if (*n == '\0') {
            result = (char *)haystack;
        }
    }
    if (result == NULL) {
        return NULL;
    } else {
        return result;
    }
}

void *memcpy(void *destination, const void *source, size_t num) {
    //https://www.geeksforgeeks.org/write-memcpy/
    char *csrc = (char *)source;
    char *cdest = (char *)destination;

    // Copy contents of src[] to dest[]
    for (size_t i = 0; i < num; i++)
        cdest[i] = csrc[i];

    return destination;
}

void *memmove(void *destination, const void *source, size_t num) {
    /*https://stackoverflow.com/questions/13339582/why-is-linux-memmove-implemented-the-way-it-is*/
    signed char operation;
    size_t end;
    size_t current;

    if (destination != source) {
        if (destination < source) {
            operation = 1;
            current = 0;
            end = num;
        } else {
            operation = -1;
            current = num - 1;
            end = -1;
        }

        for (; current != end; current += operation) {
            *(((unsigned char *)destination) + current) = *(((unsigned char *)source) + current);
        }
    }
    return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num) {
    //https://aticleworld.com/memcmp-in-c/
    unsigned char *p = (unsigned char *)ptr1;
    unsigned char *q = (unsigned char *)ptr2;
    int charCompareStatus = 0;

    if (ptr1 == ptr2) {
        return charCompareStatus;
    }

    while (num > 0) {
        if (*p != *q) {
            if (*p > *q) {
                charCompareStatus = 1;
            } else {
                charCompareStatus = -1;
            }
            break;
        }
        num--;
        p++;
        q++;
    }
    return charCompareStatus;
}

void *memset(void *source, int value, size_t num) {
    //https://aticleworld.com/memset-in-c/
    unsigned char *src = source;
    while (num--) {
        *src++ = (unsigned char)value;
    }
    return source;
}
