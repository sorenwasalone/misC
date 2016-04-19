#include <ncurses.h>

char ch;
int bord[12][12]={0};
int fill[11][11]={0};
int usrx=10;
int usry=5;
int moveCheckInt;
int grassCheck;
int waterCheck;
int voidCheck;


// Map Stuff
int colorStuff(){
	init_pair(1, COLOR_GREEN, COLOR_GREEN); //Grass
	init_pair(2, COLOR_RED, COLOR_RED); //Outline
	init_pair(3, COLOR_BLUE, COLOR_BLUE); //Water
	init_pair(5, COLOR_BLACK, COLOR_BLACK); //Void
	init_pair(6, COLOR_WHITE, COLOR_BLACK); //Text
	return 0;
}

int drawOutline(){
	attron(COLOR_PAIR(2));
	for(int i = 0; i < 10; i++){ //left
		bord[i][0]='X';
		mvprintw(i,0,"%c",bord[i][0]);
	}
	for(int i = 0; i < 10; i++){ //right
		bord[i][10]='X';
		mvprintw(i,20,"%c",bord[i][10]);
	}
	for(int i = 0; i < 20; i++){ //top
		bord[0][i]='X';
		mvprintw(0,i,"%c",bord[0][i]);
	}
	for(int i = 0; i < 21; i++){ //Bottom
		bord[10][i]='X';
		mvprintw(10,i,"%c\n",bord[10][i]);
	}
	return 0;
}

int drawMap(){
	attron(COLOR_PAIR(1));
	for(int i = 0; i < 19; i++){
		for(int ii = 0; ii < 9; ii++){
			fill[ii][i]='.';
			mvprintw(ii+1,i+1,"%c",fill[ii][i]);
		}
	}
	return 0;
}

int water(){
	attron(COLOR_PAIR(3));
	mvprintw(4,5,"w");
	return 0;
}

int voidBlock(){
	attron(COLOR_PAIR(5));
	mvprintw(4,6,"v");
	return 0;
	
}

int draw(){
	drawOutline();
	drawMap();
	water();
	voidBlock();
	attron(COLOR_PAIR(6));
	mvprintw(12,0,"Block Type:");
	return 0;
}

//CHECKS

int checks(){
	if(usrx == 5 && usry == 4){
		init_pair(4, COLOR_WHITE, COLOR_BLUE);
		attron(COLOR_PAIR(6));
		mvprintw(13,0,"Water.");
	}
	else if(usrx == 6 && usry == 4){
		init_pair(4, COLOR_WHITE, COLOR_BLACK);
		attron(COLOR_PAIR(6));
		mvprintw(13,0,"Void.");
	}
	else{
		init_pair(4, COLOR_BLACK, COLOR_GREEN);
		attron(COLOR_PAIR(6));
		mvprintw(13,0,"Grass.");
	}
	refresh();
	return 0;
}

// Some player movement stuff

int plinp(m){
	switch(m){
		case 'a':
		if(usrx != 1){
			usrx--;
			moveCheckInt = 1;
			return 1;
		}
		break;
		
		case 's':
		if(usry != 9){
			usry++;
			moveCheckInt = 1;
			return 1;
		}
		break;
		
		case 'd':
		if(usrx != 19){
			usrx++;
			moveCheckInt = 1;
			return 1;
		}
		break;
		
		case 'w':
		if(usry != 1){
			usry--;
			moveCheckInt = 1;
			return 1;
		}
	}
	return 0;
}

int drawPlayer(){
	attron(COLOR_PAIR(4));
	mvprintw(usry,usrx,"@");
	return 0;
}

int main(){
	
	initscr();
	start_color();
	colorStuff();
	noecho();
	while((ch=getch())!='q'){
		erase();
		curs_set(0);
		plinp(ch);
		checks();
		draw();
		drawPlayer();
	}
	endwin();
	curs_set(1);
	return 0;
}