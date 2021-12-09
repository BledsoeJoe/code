#ifndef THE_GAME_H
#define THE_GAME_H

#include "video.h"
#include "window.h"

int size;

video vid;

window win;

int * cells;

int * cells_next;

void copy_ar();

void add_frame();

void alive(int neighbors, int i, int j);

void cycle();

#endif
