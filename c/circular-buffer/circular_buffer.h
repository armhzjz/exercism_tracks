#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <stdbool.h>


typedef unsigned char buffer_value_t;
typedef struct {
    unsigned char *buffer;
    unsigned long buffer_size;
    unsigned char *start_pos;
    unsigned char *current_pos;
    bool is_full;
} circular_buffer_t;

unsigned char write(circular_buffer_t *, buffer_value_t);
unsigned char overwrite(circular_buffer_t *, buffer_value_t);
signed int read(circular_buffer_t *, buffer_value_t *);
unsigned char clear_buffer(circular_buffer_t *);
circular_buffer_t * new_circular_buffer(unsigned long);
unsigned char delete_buffer(circular_buffer_t *);

#endif
