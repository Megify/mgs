#ifndef SDL_H
#define SDL_H

/* some interface to sdl stuff */

void init_sdl ();
void quit_sdl ();

SDL_Window *create_sdl_window (const char *title, int width, int height);
void destroy_sdl_window (SDL_Window *sdl_window);

#endif /* SDL_H */
