#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct DynamicSlice {
    void **data;
    unsigned int size;
    unsigned int capacity;
};

struct DynamicSlice *create_dynamic_lice() {
    struct DynamicSlice *newSlice = (struct DynamicSlice *) malloc(sizeof(struct DynamicSlice));
    
    newSlice->data     = malloc(sizeof(void *) * CAPACITY);
    newSlice->size     = 0;
    newSlice->capacity = CAPACITY;
    
    return newSlice;
}

void *get(struct DynamicSlice *slice, int offset) {
    if (offset >= 0) {
        return slice->data[offset];
    }
    
    else {
        return slice->data[slice->size - offset];
    }
}

void expand(struct DynamicSlice *slice) {
    unsigned int newCapacity = slice->capacity * 2;
    
    slice->data = realloc(slice->data, sizeof(void *) * newCapacity);

    slice->capacity = newCapacity;
}

void append(struct DynamicSlice *slice, void *data) {
    if (slice->size == slice->capacity) {
        expand(slice);
        append(slice, data);
    }
    
    else {
        slice->data[slice->size] = data;
        slice->size++;
    }
}