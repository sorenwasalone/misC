#include <ncurses.h>

int map[30][30]={0};
int px=5;
int py=5;


int mapdraw(){
	for(int i = 0; i < 20; i++){
		for(int ii = 0; ii < 20; ii++){
			map[ii][i]='.';
			mvprintw(ii,i,"%c",map[ii][i]);
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