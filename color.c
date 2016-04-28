#include <curses.h>

int main(void) {
    initscr();
    start_color();

    init_pair(1, COLOR_RED, COLOR_GREEN);
    init_pair(2, COLOR_BLACK, COLOR_GREEN);

    attron(COLOR_PAIR(1));
    printw("This should be printed in black with a red background!\n");

    attron(COLOR_PAIR(2));
    printw("And this in a green background!\n");
    refresh();

    getch();

    endwin();
}