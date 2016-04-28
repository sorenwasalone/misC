#include <ncurses.h>

int map[10][10]={0};

int mapdraw(){
	for(int i=0;i<20;i++){
		for(int ii=0;ii<20;i++){
			map[ii][i]='.';
			mvprintw(ii,i,"%s",map[ii][i]);
		}
	}
	return 0;
}

int main(){
	char ch;
	initscr();
	noecho();
	while((ch=getch()) != 'q'){
		erase();
		mapdraw();
	}
	endwin();
	return 0;
}