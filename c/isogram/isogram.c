#include "isogram.h"
#include "stdlib.h"
#include "string.h"
#include "strings.h"
#include "ctype.h"


void initLetterArrays(found_letters_t *letters, char initSize) {
    letters->letters = malloc(initSize * sizeof(char));
    letters->array_used_elements = 0;
    letters->array_size = initSize;
}

void insertLetter(found_letters_t *letters, char aletter)
{
    // if the array has no more empty 'space'....
    if (letters->array_used_elements == letters->array_size) {
        letters->array_size += 1;
        letters->letters = realloc(letters->letters, letters->array_size * sizeof(char));
    }
    // letters->array_used_elements is the number of used entries,
    // because letters->letters[letters->array_used_elements++] updates letters->array_used_elements only *after* the array has been accessed.
    // Therefore letters->array_used_elements can go up to letters->array_size
    letters->letters[letters->array_used_elements++] = aletter;
}

void freeArray(found_letters_t *letters) {
    free(letters->letters);
    letters->letters = NULL;
    letters->array_used_elements = letters->array_size = 0;
}

bool is_isogram(const char phrase[]) {

    if(!phrase)
        return false;

    bool ret = true; // return value. It will be set to False if / when
                     // a letter or character is found twice
    found_letters_t found_letters;
    initLetterArrays(&found_letters,3); // initialize the letters-found structure

    for(const char *pletter = phrase; *pletter && ret; pletter++) {
        // if letter in turn is a space or a hyphen, ignore it
        if(!strncmp(pletter, " ", 1) || !strncmp(pletter, "-", 1)) { continue; }
        // check if the letter in turn was already found once
        for(unsigned char array_it = 0; array_it < found_letters.array_size; array_it++) {
            if(!strncasecmp(&found_letters.letters[array_it], pletter, 1)) {
                ret=false;
                break;
            }
        }
        // make an entry with the current letter (if ret is still true)
        if(ret){
            insertLetter(&found_letters, *pletter);
        }
    }

    // free up the allocated memory
    freeArray(&found_letters);

    return ret;
}
