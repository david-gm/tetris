#ifndef _MY_ELEMENTS_H
#define _MY_ELEMENTS_H

#include <stdbool.h>
#include <curses.h>

struct Coords
{
  int y;
  int x;
};

void initElements();

void drawWall(WINDOW *win);

void drawElements(WINDOW *win);

void updateElements(const int *key_press);

int getElementIndex(int x, int y);

bool collision_bottom();

#endif