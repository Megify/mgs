#ifndef INTERFACE_H
#define INTERFACE_H

#include "mgs.h"
#include "backend.h"

/* this struct represents an instance of a user interface window that can be
 * used to interact with a single emulated mgs machine */

typedef struct interface_t {

    mgs_t *mgs;         /* the emulated machine attached to this window */
    backend_t *backend; /* interface to the host's windowing system */
    window_t *window;   /* the main video display output window */

} interface_t;

/* use these functions to create and destroy interface instances */

interface_t *create_interface (mgs_t *mgs, backend_t *backend);
void destroy_interface (interface_t *interface);

/* user event callbacks for the backend to call appropriately */

/* called when the user interacts with a window via a gamepad controller */
void on_gamepad (window_t *window, gamepad_button_t button, int pressed,
                 interface_t *interface);

/* called when the user interacts with a window via the keyboard */
void on_keyboard (window_t *window, keyboard_key_t key, int pressed,
                  interface_t *interface);

/* called when the user attempts to close a window */
void on_close (window_t *window, interface_t *interface);

/* called when its time to draw a new frame */
void on_vsync (window_t *window, interface_t *interface);

/* called when its time to fill the audio buffer */
void on_audio (double *buffer, int n_frames, int n_channels, double rate,
               interface_t *interface);

#endif /* INTERFACE_H */
