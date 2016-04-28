#include <stdio.h>
#include <ncurses.h>

void fib(int minValue, int maxValue){
	int a = minValue-1;
	int b = minValue;
	while (b > 0 && b < maxValue){
		printw("%d\n",b);
		int c = a + b;
		a = b;
		b = c;
	}
}

int main(){
	noecho();
	initscr();
	printw("Welcome to Fib.");
	getch();
	erase();
	printw("Put in your maximum value.");
	int second;
	second = getch();
	fib(1,second);
	endwin();
	return 0;
}