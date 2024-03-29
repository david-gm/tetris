#include <stdlib.h>
#include <stdio.h>

#include <curses.h>
#include <unistd.h>

#include "elements.h"

#define WINDOW_WIDTH 40
#define WINDOW_HEIGHT 25

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
  
  keypad(stdscr, TRUE); // enable arrow keys and function keys; stdscr is the regular screen
  curs_set(0); // hides cursor
  clear();

  int maxlines, maxcols;
  maxlines = LINES - 1;
  maxcols = COLS - 1;

  mvaddstr(maxlines, 0, "Press x to quit");
  refresh();

  current_win = newwin(WINDOW_HEIGHT, WINDOW_WIDTH, 0, 0);
  nodelay(current_win, TRUE); // no delay with getch()
  int c = 0;

  initElements();
  drawElements(current_win);
  wrefresh(current_win);

  /* waits for 250 ms for a getch to trigger */
  timeout(250);
  while (c != 'x')
  {
    //sleep(50);
    c = getch();
    updateElements(&c);

    wclear(current_win);
    drawElements(current_win);

    char out[20];
    sprintf(out, "%c", c);
    mvwaddstr(current_win, 22, 15, out);

    wrefresh(current_win);

  }

  delwin(current_win);
  endwin();
  exit(0);

  return 0;
}
