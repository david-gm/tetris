#include "elements.h"

void drawWall(WINDOW *win)
{
    int w = 30;
    int h = 20;
    int offset = 1;
    for (unsigned int y = offset; y < h + offset; ++y)
        mvwaddch(win, y, 0, '#');

    for (unsigned int x = 0; x < w + offset; ++x)
        mvwaddch(win, h, x, '#');

    for (unsigned int y = 1; y < h + offset; ++y)
        mvwaddch(win, y, w, '#');
}

void drawElements(WINDOW *win, const int *c)
{
    mvwaddch(win, 15, 15, *c);
    drawWall(win);
}

void updateElements(){}
