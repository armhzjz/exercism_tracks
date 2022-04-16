#include <stdlib.h>
#include<errno.h>
#include "circular_buffer.h"


circular_buffer_t * new_circular_buffer(unsigned long capacity) {
    circular_buffer_t *buffer = malloc(sizeof(circular_buffer_t));
    buffer->buffer = malloc(capacity * sizeof(unsigned char));
    buffer->start_pos = buffer->current_pos = buffer->buffer;
    buffer->buffer_size = capacity;
    buffer->is_full = false;
    return buffer;
}

unsigned char delete_buffer(circular_buffer_t *buffer) {
    if(!buffer) {
        errno = ENODATA;
        return 1;
    }

    free(buffer->buffer);
    buffer->start_pos = buffer->current_pos = buffer->buffer = NULL;
    buffer->buffer_size = 0;
    buffer->is_full = false;
    free(buffer);
    buffer = NULL;

    return 0;
}

unsigned char write(circular_buffer_t *buffer, buffer_value_t value) {
    if(!buffer) {
        errno = ENODATA;
        return 1;
    }

    if(buffer->is_full) {
        errno = ENOBUFS;
        return 1;
    }

    buffer->buffer[buffer->current_pos++ - buffer->buffer] = value;
    buffer->current_pos = (unsigned long)(buffer->current_pos - buffer->buffer) < buffer->buffer_size ? buffer->current_pos : buffer->buffer;
    buffer->is_full = (buffer->start_pos == buffer->current_pos) ? true : false;
    return 0;
}

unsigned char overwrite(circular_buffer_t *buffer, buffer_value_t value) {
    if(!buffer) {
        errno = ENODATA;
        return 1;
    }
    
    buffer->buffer[buffer->current_pos++ - buffer->buffer] = value;
    buffer->current_pos = (unsigned long)(buffer->current_pos - buffer->buffer) < buffer->buffer_size ? buffer->current_pos : buffer->buffer;
    buffer->start_pos = buffer->is_full ? buffer->current_pos : buffer->start_pos;
    buffer->is_full = (buffer->start_pos == buffer->current_pos) ? true : false;
    return 0;
}

signed int read(circular_buffer_t *buffer, buffer_value_t *value) {
    if(!buffer) {
        errno = ENODATA;
        return 1;
    }
    
    if(!buffer->is_full && (buffer->start_pos == buffer->current_pos)) {
        errno = ENODATA;
        return 1;
    }

    buffer->is_full = false; /* reading a value out will empty the buffer by one
                                so, if it was full, it isn't anymore.
                                It might be faster to make an assignation to false
                                everytime, instead of making a comparison everytime
                                this function is ran */
    *value = buffer->buffer[buffer->start_pos++ - buffer->buffer];
    buffer->start_pos = (unsigned long)(buffer->start_pos - buffer->buffer) < buffer->buffer_size ? buffer->start_pos : buffer->buffer;
    return 0;
}

unsigned char clear_buffer(circular_buffer_t *buffer) {
    if(!buffer) {
        errno = ENODATA;
        return 1;
    }
    
    buffer->current_pos = buffer->start_pos = buffer->buffer;
    buffer->is_full = false;
    return 0;
}