#include <ncurses.h>

int main(){
	initscr();
	noecho();
	mvprintw(5,10,"Hello world!");
	getch();
	endwin();
	return 0;
}