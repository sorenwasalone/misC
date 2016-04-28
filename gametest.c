#include <ncurses.h>

char ch;
int movecheck = 0;
int usrx = 5;
int usry = 5;
int health = 500;
int hunger = 500;
char grid[10][10] = {0};

int printGrid(){
	for (int i = 0; i < 10; i++){
		for (int ii = 0; ii < 10; ii++){
			grid[ii][i]= '.';
			mvprintw(ii,i*2,"%c",grid[ii][i]);
		}
	}
	return 0;
}

int plinp(char m){
	switch(m){
		case 'a':
		if(usrx != 0){
			usrx--;
			movecheck=1;
			return 0;
		}
		return 1;
		
		case 'd':
		if(usrx != 9){
			usrx++;
			movecheck=1;
			return 0;
		}
		return 1;
		
		case 's':
		if(usry !=9){
			usry++;
			movecheck=1;
			return 0;
		}
		return 1;
		
		case 'w':
		if(usry != 0){
			usry--;
			movecheck=1;
			return 0;
		}
		return 1;
	}
	return 1;
}

int main(){
	initscr();
	noecho();
	printw("Welcome to the game. o 3 o");
	while((ch = getch())!='q' && health > 0 && hunger > 0){
			erase();
			movecheck=0;
			printGrid();
			if (plinp(ch)==0)
				hunger--;
			if (usrx == 9 && usry == 9 && movecheck==1)
				health -= 20;
			mvprintw(9,18,"^");
			mvprintw(12,0,"Hunger: %d",hunger);
			mvprintw(11,0,"Health: %d",health);
			mvprintw(usry,usrx*2,"@");
	}
	endwin();
	return 0;
}