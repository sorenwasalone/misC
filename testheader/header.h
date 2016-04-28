#include <ncurses.h>

int zero[2][2]={0};

int square0(int Len, int Width, int y, int x){
	for(int i = 0; i < Len; i++){
		for(int ii = 0; ii < Width; ii++){
			mvprintw(y,x,"%d",zero[1][1]);
		}
	}
	return 0;
}