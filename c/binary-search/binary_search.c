#include "binary_search.h"


int *binary_search(int value, const int *arr, size_t length) {
    if(length == 0)
        return NULL;

    if(value == arr[length >> 1]) {
        return (int *) &arr[length >> 1];
    } else if(value < arr[length >> 1]){
        return binary_search(value, arr, (length >> 1));
    } else if(value > arr[length >> 1]) {
        return length>>1 ? binary_search(value, &arr[(length >> 1)], length - (length >> 1)) : 
                            binary_search(value, &arr[(length >> 1)], 0);
    }

    return NULL; /* intended to avoid warnings/errors,
                    but in theory should never be needed nor used.
                    */
}
