#ifndef VISUALS_H
#define VISUALS_H

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <math.h>
#include <SDL2/SDL.h>

#define COLOR_WARN "\x1b[33m"
#define COLOR_ERRO "\x1b[31m"
#define COLOR_NORM "\x1b[0m"




static SDL_Window * window;
static SDL_Renderer * renderer;

void create(int, int);
void create_board_lines();

void draw(int, int, int, int);

void draw_x(int, int, int);
void draw_c(int, int);

void refresh();

int check_window();
int check_renderer();

void clean_up();



#endif
