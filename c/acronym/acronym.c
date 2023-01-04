/*
    References for this problem:
        https://www.codingame.com/playgrounds/14213/how-to-play-with-strings-in-c/string-split
        https://nxmnpg.lemoda.net/3/regex
        https://en.wikibooks.org/wiki/Regular_Expressions/POSIX-Extended_Regular_Expressions
        https://www.lemoda.net/c/unix-regex/
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <regex.h>
#include <stdbool.h>
#include <ctype.h>
#include "acronym.h"

/*  The following is the size of a buffer to contain any error messages
    encountered when the regular expression is compiled. */
#define MAX_ERROR_MSG 0x1000

int remove_punctuations(char *);

int remove_punctuations(char *phrase) {
    regex_t regex;
    int ret_int_regex;
    regmatch_t pmatch[100];

    /* compile the regular expression */
    int status = regcomp(&regex, "([^a-z0-9[:space:]]+)", REG_EXTENDED | REG_ICASE);
    if (status) {
        char error_message[MAX_ERROR_MSG];
        regerror(status, &regex, error_message, MAX_ERROR_MSG);
        printf("Regex error when trying to compile: %s\n", error_message);
        regfree(&regex);
        exit(1);
    }
    /*  match the regular expression
        agains the target phrase */
    while (true) {
        ret_int_regex = regexec(&regex, phrase, 100, pmatch, 0);
        if (ret_int_regex) {
            regfree(&regex);
            return ret_int_regex;
        }
        for (size_t i = 0; i < 100; i++) {
            if (pmatch[i].rm_so == -1)
                break;
            if (/* for each match found ...*/
                i != 0) {
                int start = pmatch[i].rm_so;
                int finish = pmatch[i].rm_eo;
                // Debuging purposes printf's ...
                // printf("Finding %d: '%.*s' (bytes %d:%d)\n", i, finish - start, phrase + start, start, finish);
                // printf("Finish menos start: %d\n", finish - start);
                /*  For each matched character
                    (finish - start) gives the number of characters matched */
                while (finish-- - start) {
                    /*  Character "'" must be removed.
                        Any other character can be replaced by a space. */
                    if (phrase[start] != '\''){
                        phrase[pmatch[i].rm_so++] = ' ';  /*    Replace the matched character with a space.
                                                                Increment the start index, so in case there are more than one
                                                                matched characters, they (the subsequent) characters will also
                                                                be replaced by spaces.
                                                            */
                    }
                    else { /* if phrase[start] equals indeed the character "'" ... */
                        /*  the following line basically shift the right side of the matched "'" character
                            once to the left
                        */
                        strcpy(&phrase[pmatch[i].rm_so], &phrase[pmatch[i].rm_so + 1]);
                        /*  Due to the shifting of the right side of the matched character to the left,
                            we need to decrement also by one the end character offset
                            (this offset is with respect to the "phrase" pointer)
                        */
                        --pmatch[0].rm_eo;
                    }
                }
            }
        }
        /* shift the pointer up to the new substring to be matched */
        phrase += pmatch[0].rm_eo;
    }
}

char *abbreviate(const char *phrase) {
    if (!phrase || !strcmp(phrase, "")) {
        return NULL;
    }

    char c;
    char *acronym = malloc(sizeof(char));
    char *tok_ptr;

    /* create a local copy because :
        1.  During the removal of punctuations, it might be the case that the string
            needs to be modified (when removing the character "'").
        2.  Strtok modifies the original string
    */
    char p[strlen(phrase)];
    strcpy(p, phrase);

    /* Remove puntuation characters from the local copy */
    remove_punctuations(p);

    /*  split the string (i.e. p) in multiple tokens
        according to the delimiter " " (i.e. space) */
    tok_ptr = strtok(p, " ");  /* strtok takes the phrase to split and the delimiter */
    if (tok_ptr) {
        c = (char) toupper(tok_ptr[0]);  /* convert first character of next token to an upper case char */
        sscanf((const char *)&c, "%1s", acronym); /*    sscanf used to copy exactly 1 byte (otherwise noise
                                                        will be introduced into the acronym string - strings
                                                        formating finishes until a \0 character is found on source) */
    }
    while (tok_ptr)
    {
        tok_ptr = strtok(NULL, " ");
        if (tok_ptr) {
            /* need to increase the allocated memory for the acronym (by one byte) */
            acronym = (char *) realloc((void *)acronym, sizeof(char) * (strlen(acronym) + 1));
            c = toupper(tok_ptr[0]);  /* convert first character of next token to an upper case char */
            strncat(acronym, &c, 1);
        }
    }
    return acronym;
}

// int main(int argc, char ** argv){
//     const char *s = ".elquetrabaja-AGX#;35267$ y el otro''''abc$!()=}:^'AAA";
//     char *resultado = abbreviate(s);
//     printf("resultado: %s\n", resultado);
//     free(resultado);
//     return 0;
// }