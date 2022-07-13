#include <stdlib.h>
#include "pascals_triangle.h"


void free_triangle(uint8_t **triangle, size_t rows) {
    if (!triangle)
        exit(-1);

    for(;rows != 0;) {
        free(triangle[rows - 1]);
        triangle[rows - 1] = NULL;
        rows--;
    }
    free(triangle);
    triangle = NULL;
}

uint8_t **create_triangle(size_t rows){
    if (rows == 0){
        uint8_t **x = (uint8_t **) malloc(sizeof(uint8_t *));
        *x = (uint8_t *) calloc(1, sizeof(uint8_t));
        return x;
    }

    uint8_t **pascal_triangle = (uint8_t **) malloc(sizeof(uint8_t *) * rows);
    for (size_t i = 0; i < rows; i++) {
        pascal_triangle[i] = (uint8_t *) malloc(sizeof(uint8_t) * rows);
        pascal_triangle[i][0] = 1;
        for (size_t j = 1; j < rows && (i > 0); j++)
            pascal_triangle[i][j] = pascal_triangle[i-1][j-1] + pascal_triangle[i-1][j];
    }
        
    return pascal_triangle;
}
