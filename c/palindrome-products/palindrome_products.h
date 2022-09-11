#ifndef PALINDROME_PRODUCTS_H
#define PALINDROME_PRODUCTS_H

#include <stdbool.h>

#define MAXERR 100

typedef struct factors {
   int factor_a;
   int factor_b;
   struct factors *next;
} factor_t;

struct product {
   int smallest;
   int largest;
   factor_t *factors_sm;
   factor_t *factors_lg;
   char error[MAXERR];
};

typedef struct product product_t;

product_t *get_palindrome_product(int from, int to);
void free_product(product_t *p);

void set_new_largest(product_t *, int, int, int);
void set_new_smallest(product_t *, int, int, int);
void free_all_factor_ts(factor_t**);
void set_new_factors_to(factor_t**, int, int);
bool check_if_palindrome(int);
bool check_for_no_palindrome(product_t*);
#endif
