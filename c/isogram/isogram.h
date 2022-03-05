#ifndef ISOGRAM_H
#define ISOGRAM_H

#include <stdbool.h>

typedef struct {
    char *letters;
    unsigned char array_used_elements;
    unsigned char array_size;
} found_letters_t;


bool is_isogram(const char phrase[]);
void initLetterArrays(found_letters_t *, char initSize);
void insertLetter(found_letters_t *, char letter);
void freeArray(found_letters_t *);

#endif
