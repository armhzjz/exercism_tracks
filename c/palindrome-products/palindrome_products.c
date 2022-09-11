#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include "palindrome_products.h"


product_t *get_palindrome_product(int from, int to) {
    product_t *products = (product_t *) calloc(1, sizeof(product_t));

    products->largest = INT_MAX;
    products->smallest = INT_MAX;

    if(from > to) {
        sprintf(products->error, "invalid input: min is %d and max is %d", from, to);
        return products;
    }
    
    for (int factor_1 = from; factor_1 <= to; factor_1++)
        for(int factor_2 = factor_1; factor_2 <= to; factor_2++) {
            int product = factor_1 * factor_2;
            if (check_if_palindrome(product)) {
                if(check_for_no_palindrome(products)) {
                    set_new_largest(products, product, factor_1, factor_2);
                    set_new_smallest(products, product,factor_1, factor_2);
                }
                else if (product > products->largest) {
                    set_new_largest(products, product, factor_1, factor_2);
                }
                else if (product < products->smallest) {
                    set_new_smallest(products, product, factor_1, factor_2);
                }
                else if (product == products->largest){
                    set_new_factors_to(&products->factors_lg, factor_1, factor_2);
                }
                else if (product == products->smallest){
                    set_new_factors_to(&products->factors_sm, factor_1, factor_2);
                }
            }
        }

    if(check_for_no_palindrome(products))
        sprintf(products->error, "no palindrome with factors in the range %d to %d", from, to);

    return products;
}

bool check_for_no_palindrome(product_t* products) {
    if((products->largest == products->smallest) && (products->largest == INT_MAX))
        return true;
    else
        return false;
    
}

void set_new_factors_to(factor_t** f, int fa, int fb) {
    if (! *f) {
        *f = (factor_t *) calloc(1, sizeof(factor_t));
        (*f)->factor_a = fa;
        (*f)->factor_b = fb;
        return;
    }
    set_new_factors_to(&(*f)->next, fa, fb);
}

void set_new_smallest(product_t *products, int p, int fa, int fb){
    free_all_factor_ts(&products->factors_sm);
    products->smallest = p;
    products->factors_sm = (factor_t *) calloc(1, sizeof(factor_t));
    products->factors_sm->factor_a = fa;
    products->factors_sm->factor_b = fb;
}

void set_new_largest(product_t *products, int p, int fa, int fb){
    free_all_factor_ts(&products->factors_lg);
    products->largest = p;
    products->factors_lg = (factor_t *) calloc(1, sizeof(factor_t));
    products->factors_lg->factor_a = fa;
    products->factors_lg->factor_b = fb;
}

void free_all_factor_ts(factor_t** factor) {
    if(! *factor)
        return;
    if(!!(*factor)->next)
        free_all_factor_ts(&(*factor)->next);
    free(*factor);
    return;
}

bool check_if_palindrome(int p) {
    int reverse = 0, value = p;
    while (value != 0) {
        reverse *= 10;
        reverse += value % 10;
        value /= 10;
    }
    return reverse == p;
}

void free_product(product_t *products) {
    free_all_factor_ts(&products->factors_lg);
    free_all_factor_ts(&products->factors_sm);
    free(products);
}
