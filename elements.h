#ifndef _MY_ELEMENTS_H
#define _MY_ELEMENTS_H

#include <curses.h>

void drawWall(WINDOW *win);


void drawElements(WINDOW *win, const int *c);

void updateElements();

#endif