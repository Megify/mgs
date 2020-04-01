#ifndef MGS_H
#define MGS_H

/* this struct represents a state instance of a single emulated mgs machine */

typedef struct mgs_t {

    /* TODO */
    int tmp; 

} mgs_t;

/* use these functions to create and destroy mgs state instances */

mgs_t *create_mgs (void);
void destroy_mgs (mgs_t *mgs);

#endif /* MGS_H */
