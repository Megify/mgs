#ifndef DYNSLICE_H
#define DYNSLICE_H

/* Global for the default beginning capacity size for dynamic slices. */
#define CAPACITY 5

struct DynamicSlice {
    void **data;
    unsigned int size;
    unsigned int capacity;
};

/*
 *  A simple and barebones dynamic slice implementation.
 *  It doubles its size once it's appended past capacity.
 */
struct DynamicSlice;

/*
 *  Creates a dynamic slice. Use this over creating it yourself as there are some defaults.
 *
 *  Returns:
 *    A generated struct representing a dynamic slice.
 */
struct DynamicSlice *create_dynamic_slice();

/*
 *  Frees a previously created dynamic slice. Use this over directly freeing the
 *  dynamic slice instance because there are some internals that need to be
 *  freed as well.
 */

void free_dynamic_slice(struct DynamicSlice *slice);

/*
 *  Gets a void pointer from the dynamic slice. Use this over indexing yourself.
 *  Accepts negative values, in which negative values will index backwards from the end.
 *
 *  Returns:
 *    A void pointer to the value at the specified index.
 */
void *get(struct DynamicSlice *slice, int offset);

/*
 *  Expands a dynamic slice.
 *  Automatically called from `append(struct DynamicSlice *slice, void *data)` when attempting to append past the capacity.
 */
void expand(struct DynamicSlice *slice);

/*
 *  Appends a pointer to a value at the end of the dynamic slice.
 *  Automatically calls `void *get(struct DynamicSlice *slice, int offset)` when attempting to append past the capacity.
 */
void append(struct DynamicSlice *slice, void *data);

/* TODO: remove function that removes an arbitrary item */

#endif /* DYNSLICE_H */
