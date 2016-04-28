#include "random.h"
#include <ncurses.h>

int potato;

int main(){
	initscr();
	noecho();
	char ch;
	while((ch=getch())!='q'){
		potato=randint(1,10,4);
		printw("%d",potato);
	}
	endwin();
	return 0;
}