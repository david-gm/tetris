#include <stdlib.h>
#include <stdio.h>

#include <curses.h>

#include "elements.h"

#define WINDOW_WIDTH 40
#define WINDOW_HEIGHT 25

struct Coords
{
  int y;
  int x;
};

int main()
{
  struct Coords coords;
  coords.x = 5;
  coords.y = 15;

  WINDOW *current_win;

  /* initialize curses */
  initscr();
  cbreak();
  noecho();
  curs_set(0); // hides cursor
  clear();

  int maxlines, maxcols;
  maxlines = LINES - 1;
  maxcols = COLS - 1;

  mvaddstr(maxlines, 0, "Press x to quit");
  refresh();

  current_win = newwin(WINDOW_HEIGHT, WINDOW_WIDTH, 0, 0);

  int c = 0;

  drawElements(current_win, &c);
  wrefresh(current_win);

  while (c != 'x')
  {
    c = getch();

    updateElements();

    wclear(current_win);
    drawElements(current_win, &c);
    wrefresh(current_win);
  }

  delwin(current_win);
  endwin();
  exit(0);

  return 0;
}
