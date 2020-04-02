#include <config.h>
#include <stdlib.h>
#include <string.h>
#include "backend.h"
#include "sdl.h"

backend_t *create_backend (void) {

    /* allocate memory for the instance and zero it */

    backend_t *backend = (backend_t *) malloc (sizeof (backend_t));
    memset (backend, 0, sizeof (backend_t));

    /* initialize the windows vector and the audio callbacks vector */

    /* TODO */

    /* init sdl since thats the actual backend we are using */

    init_sdl ();

    return backend;
}

void destroy_backend (backend_t *backend) {

    /* deinit sdl in corresponding to initing it at creation */

    quit_sdl ();

    /* remove all items from the two vectors */

    destroy_all_windows (backend);
    unregister_all_audio_callbacks (backend);

    free (backend);
}

void run_backend (backend_t *backend) {

    /* TODO: poll events and dispatch them to the interfaces associated with the
     * source window */

    /* TEMP */
    SDL_Delay (2000);
}

void register_audio_callback (backend_t *backend,
                              audio_callback_t *callback,
                              void *data) {

    /* TODO
    registered_audio_callback_t registered_callback;
    registered_callback.callback = callback;
    registered_callback.data = data;
    */

    /* TODO: push the object to the registered audio callbacks vector */
}

void unregister_audio_callback (backend_t *backend,
                                audio_callback_t *callback,
                                void *data) {

    /* TODO
    registered_audio_callback_t registered_callback;
    registered_callback.callback = callback;
    registered_callback.data = data;
    */

    /* TODO: remove this object from the regestired audio callbacks vector */
}

void unregister_all_audio_callbacks (backend_t *backend) {

    /* TODO: iterate the callbacks vector and call the above function on each */
}

window_t *create_window (backend_t *backend, const char *title,
                                             int width, int height) {

    /* allocate memory for the instance and zero it */

    window_t *window = (window_t *) malloc (sizeof (window_t));
    memset (window, 0, sizeof (window_t));

    /* initialize the fields of the struct instance */

    window->backend = backend;

    /* spawn the window via sdl or whatever */

    window->sdl_window = create_sdl_window (title, width, height);

    /* TODO: push this window object to the windows vector */

    return window;
}

void destroy_window (window_t *window) {

    /* destroy it via sdl or whatever */

    destroy_sdl_window (window->sdl_window);

    /* TODO: remove this window object from the windows vector */

    free (window);
}

void destroy_all_windows (backend_t *backend) {

    /* TODO: iterate the windows vector and call destroy_window on each */
}
