#include "elements.h"

#include <string.h>

#define WALL_WIDTH 30

/*
 *  dimensions = 2 x 4:
 *  in 2D:  ..xx
 *          xx..
 *  indexing with x = 0 - 3; y = 0 - 1; width = 4
 *      i = x + y * width
 */
char element1[] = "..xxxx..";

struct Tetrix
{
    char element[8];
    struct Coords coords;
};

struct Tetrix t1 = {.coords = {.x = 5, .y = 1}};

void initElements()
{
    memcpy(t1.element, element1, 8);
}

void drawWall(WINDOW *win)
{
    int w = WALL_WIDTH;
    int h = 20;
    int offset = 1;
    for (unsigned int y = offset; y < h + offset; ++y)
        mvwaddch(win, y, 0, '#');

    for (unsigned int x = 0; x < w + offset; ++x)
        mvwaddch(win, h, x, '#');

    for (unsigned int y = 1; y < h + offset; ++y)
        mvwaddch(win, y, w, '#');
}

void drawElements(WINDOW *win)
{
    for (unsigned int y = 0; y < 2; ++y)
        for (unsigned int x = 0; x < 4; ++x)
        {
            int index = getElementIndex(x, y);
            if (element1[index] != '.')
            {
                mvwaddch(win,
                         t1.coords.y + y,
                         t1.coords.x + x,
                         t1.element[index]);
            }
        }

    char out[20];
    sprintf(out, "%d, %d", t1.coords.x, t1.coords.y);
    mvwaddstr(win, 21, 15, out);
    drawWall(win);
}

void updateElements(const int *key_press)
{
    
    if(*key_press == KEY_LEFT && t1.coords.x > 1)
            t1.coords.x -= 1;
    if(*key_press == KEY_RIGHT && t1.coords.x < WALL_WIDTH)
            t1.coords.x += 1;

    t1.coords.y += 1;
}

int getElementIndex(int x, int y)
{
    int width = 4;
    return x + y * width;
}