#include <config.h>
#include <stdio.h>
#include <stdlib.h>
#include "mgs.h"
#include "backend.h"
#include "interface.h"

int main (int argc, char **argv) {

    mgs_t *mgs;             /* instance of the emulated machine */
    backend_t *backend;     /* interface to the host's windowing system */
    interface_t *interface; /* instance of the user interface window */

    puts ("Welcome to the MGS emulator!");

    /* TODO: parse command line arguments using getopt */

    /* TODO: load program rom and save ram from disk using mmap */

    /* instantiate the emulated machine and point it to the program rom and save
     * ram that was loaded from disk */

    mgs = create_mgs (/* TODO: program rom and save ram arguments */);

    /* instantiate the windowing backend */

    /* TODO: eventually provide a command line switch to choose between various
     * potential backends */

    backend = create_backend ();

    /* instantiate a user interface window to interact with the emulated mgs
     * machine */

    interface = create_interface (mgs, backend);

    /* enter the main user interface run loop
     * this is powered by the backend which calls back the interface instance
     * for relevant events
     * the backend will run until the user exits */

    run_backend (backend);
    
    /* cleanup */

    destroy_mgs (mgs);
    destroy_backend (backend);
    /* we don't destroy the interface because it destroys itself
     * when the user closes the window */

    puts ("Goodbye!");

    return EXIT_SUCCESS;
}
