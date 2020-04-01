#include <config.h>
#include <stdlib.h>
#include <string.h>
#include "mgs.h"

mgs_t *create_mgs (void) {

    /* allocate memory for the instance and zero it */

    mgs_t *mgs = (mgs_t *) malloc (sizeof (mgs_t));
    memset (mgs, 0, sizeof (mgs_t));

    /* initialize the fields of the struct instance */

    /* TODO */

    return mgs;
}

void destroy_mgs (mgs_t *mgs) {

    free (mgs);
}
