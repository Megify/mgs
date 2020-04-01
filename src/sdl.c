#include <config.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "sdl.h"

void init_sdl () {

    /* TODO: also init audio */

    if (SDL_Init (SDL_INIT_VIDEO) < 0) {

        printf ("Unable to initialize SDL: %s\n", SDL_GetError ());
        exit (EXIT_FAILURE);
    }
}

void quit_sdl () {

    SDL_Quit ();
}

SDL_Window *create_sdl_window (const char *title, int width, int height) {

    SDL_Window *sdl_window = SDL_CreateWindow (title, SDL_WINDOWPOS_CENTERED,
                                                      SDL_WINDOWPOS_CENTERED,
                                                      width, height,
                                                      SDL_WINDOW_SHOWN);
    if (sdl_window == NULL) {
 
        printf ("Unable to create SDL window: %s\n", SDL_GetError());
        exit (EXIT_FAILURE);
    }

    return sdl_window;
}

void destroy_sdl_window (SDL_Window *sdl_window) {

    SDL_DestroyWindow (sdl_window);
}
