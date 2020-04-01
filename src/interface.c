#include <config.h>
#include <stdlib.h>
#include <string.h>
#include "interface.h"

interface_t *create_interface (mgs_t *mgs, backend_t *backend) {

    /* allocate memory for the instance and zero it */

    interface_t *interface = (interface_t *) malloc (sizeof (interface_t));
    memset (interface, 0, sizeof (interface_t));

    /* initialize the fields of the struct instance */

    interface->mgs = mgs;
    interface->backend = backend;

    /* spawn the video window and register for audio callbacks */

    interface->window = create_window (backend, WINDOW_TITLE,
                                                WINDOW_WIDTH,
                                                WINDOW_HEIGHT);
    register_audio_callback (backend, on_audio, interface);

    return interface;
}

void destroy_interface (interface_t *interface) {

    /* destroy the video window and unregister the audio callback */

    destroy_window (interface->window);
    unregister_audio_callback (interface->backend, on_audio, interface);

    free (interface);
}

void on_gamepad (window_t *window, gamepad_button_t button, int pressed,
                 void *interface) {

    /* TODO */
}

void on_keyboard (window_t *window, keyboard_key_t key, int pressed,
                  void *interface) {

    /* TODO */
}

void on_close (window_t *window, void *interface) {

    /* if we are closing the video window, then destroy this interface */

    destroy_interface ((interface_t *) interface);
}

void on_vsync (window_t *window, void *interface) {

    /* TODO */
}

void on_audio (double *buffer, int n_frames, int n_channels, double rate,
               void *interface) {

    /* TODO */
}
