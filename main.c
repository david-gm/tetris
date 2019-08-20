#include <stdlib.h>
#include <stdio.h>

#include <curses.h>

#define WINDOW_WIDTH 50
#define WINDOW_HEIGHT 20

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
  clear();

  int maxlines, maxcols;
  maxlines = LINES - 1;
  maxcols = COLS - 1;

  mvaddstr(maxlines, 0, "Press x to quit");
  refresh();

  current_win = newwin(WINDOW_HEIGHT, WINDOW_WIDTH, 0, 0);

  int c = 0;
  while (c != 'x')
  {
    c = getch();

    //wclear(current_win);
    mvwaddch(current_win, 15, 15, c);
    wrefresh(current_win);
  }

  delwin(current_win);
  endwin();
  exit(0);

  return 0;
}
