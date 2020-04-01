#ifndef BACKEND_H
#define BACKEND_H

#include <SDL2/SDL.h>

/* a function to fill a realtime audio buffer */

typedef void (audio_callback_t) (double *buffer,
                                 int n_frames,
                                 int n_channels,
                                 double rate,
                                 void *data);

/* a struct to hold an audio callback and an associated piece of data */

typedef struct registered_audio_callback_t {

    audio_callback_t *callback; /* the function to call */
    void *data;                 /* the user data to give it as an argument */

} registered_audio_callback_t;

/* state for a connection to the host's windowing system */

typedef struct backend_t {

    /* TODO: vector of open windows */
    /* TODO: vector of register audio callbacks */
    int tmp;

} backend_t;

/* use these functions to create and destroy backend instances */

backend_t *create_backend (void);
void destroy_backend (backend_t *backend);

/* enter the event polling loop which will drive clients of opened windows */

void run_backend (backend_t *backend);

/* add and remove audio callbacks associated with a piece of data */

void register_audio_callback (backend_t *backend,
                              audio_callback_t *callback,
                              void *data);
void unregister_audio_callback (backend_t *backend,
                                audio_callback_t *callback,
                                void *data);
void unregister_all_audio_callbacks (backend_t *backend);

/* a struct to represent an open window */

typedef struct window_t {

    backend_t *backend;     /* the backend that this window is opened on */
    SDL_Window *sdl_window; /* the associated SDL window object */

} window_t;

/* use these functions to spawn and destroy windows on the backend */

window_t *create_window (backend_t *backend, const char *title,
                                             int width, int height);
void destroy_window (window_t *window);
void destroy_all_windows (backend_t *backend);

/* some ui event types */

typedef int keyboard_key_t;
typedef int gamepad_button_t;

#endif /* BACKEND_H */
