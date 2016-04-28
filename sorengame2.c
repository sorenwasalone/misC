// This is the re-programmed version to test how much I know from memory.

#include <ncurses.h>
#include <stdlib.h>

char ch;
char quitBool;
char pName[20];
int spikeCheckInt;
int waterCheckInt;
int fieldCheckInt;
int health = 500;
int hunger = 100;
int map[20][20]={0};
int pond[6][6]={0};
int field[6][6]={0};
int spikeLine[20][20]={0};
int key[10][10]={0};
int usrx = 10;
int usry = 10;
int moveCheckInt;

// Color Content
int colorContent(){
	init_pair(1, COLOR_GREEN, COLOR_GREEN); //Grass
	init_pair(2, COLOR_BLUE, COLOR_BLUE); //Water
	init_pair(3, COLOR_YELLOW, COLOR_YELLOW); //Field
	init_pair(4, COLOR_WHITE, COLOR_BLACK); //Text
	init_pair(5, COLOR_MAGENTA, COLOR_BLACK); //Player
	init_pair(6, COLOR_RED, COLOR_BLACK); //Spikes
	init_pair(7, COLOR_CYAN, COLOR_GREEN); //NPC
	
	return 0;
}

// Map Stuff

int printKey(int offX, int offY){
	for(int i = 0; i < 10; i++){
		attron(COLOR_PAIR(4));
		key[0][i]='_';
		mvprintw((0)+offY,(i*2)+offX,"%c",key[0][i]);
		key[9][i]='_';
		mvprintw((9)+offY,(i*2)+offX,"%c",key[9][i]);
		key[i-2][0]='|';
		mvprintw((i)+offY,(0)+offX,"%c",key[i-2][0]);
		key[i][9]='|';
		mvprintw((i)+offY,(9*2)+offX,"%c",key[i][9]);
		mvprintw(offY,offX,"_");
		mvprintw(1+offY,1+offX,"KEY:");
		attron(COLOR_PAIR(5));
		mvprintw(2+offY,1+offX,"@ = %s",pName);
		attron(COLOR_PAIR(1));
		mvprintw(3+offY,1+offX,". = Grass");
		attron(COLOR_PAIR(2));
		mvprintw(4+offY,1+offX,"w = Water");
		attron(COLOR_PAIR(3));
		mvprintw(5+offY,1+offX,"f = Farm");
		attron(COLOR_PAIR(6));
		mvprintw(6+offY,1+offX,"^ = Spike");
		attron(COLOR_PAIR(7));
		mvprintw(7+offY,1+offX,"& = NPC");
	}
	return 0;
}

int printGrid(){
	attron(COLOR_PAIR(1));
	for(int i = 0; i < 40; i++){
		for(int ii = 0; ii < 20; ii++){
			map[ii][i]='.';
			mvprintw(ii,i,"%c",map[ii][i]);
		}
	}
	for(int iii = 0; iii < 20; iii++){
		attron(COLOR_PAIR(6));
		spikeLine[iii][iii]='^';
		mvprintw(iii,18*2,"%c",spikeLine[iii][iii]);
		mvprintw(iii,19*2,"%c",spikeLine[iii][iii]);
	}
	return 0;
}

int printPond(){
	attron(COLOR_PAIR(2));
	for(int i = 0; i < 12; i++){
		for(int ii = 0; ii < 6; ii++){
			pond[ii][i]='w';
			mvprintw(ii+13,(i)+2,"%c",pond[ii][i]);
		}
	}
	return 0;
}

int printField(){
	attron(COLOR_PAIR(3));
	for(int i = 0; i < 12; i++){
		for(int ii = 0; ii < 6; ii++){
			field[ii][i]='f';
			mvprintw(ii+13,(i+22),"%c",field[ii][i]);
		}
	}
	return 0;
}

int steve(int x,int y){
	attron(COLOR_PAIR(7));
	mvprintw(x,y*2,"&");
	if((usrx-x==1 && usry==y) || (x-usrx==1 && usry==y) || (usry-y==1 && usrx==x) || (y-usry==1 && usrx==x))
		mvprintw(6,40,"Yo, %s. I'm Steve. I'm just a test NPC tbh.", pName);
	return 0;
}

int drawMap(){
	printGrid();
	printPond();
	printField();
	steve(8,8);
	printKey(40,10);
	attron(COLOR_PAIR(5));
	mvprintw(usry,usrx*2,"@");
	attron(COLOR_PAIR(4));
	mvprintw(0,40,"Player name: %s",pName);
	mvprintw(1,40,"Health: %dHP",health);
	mvprintw(2,40,"Hunger: %d", hunger);
	mvprintw(4,40,"Description:");
	return 0;
}

// Input Stuff

int pInput(m){
	switch(m){
		case 'a':
		if(usrx != 0){
			usrx--;
			moveCheckInt = 1;
			return 1;
		}
		break;
		
		case 's':
		if(usry != 19){
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
		if(usry != 0){
			usry--;
			moveCheckInt = 1;
			return 1;
		}
	}
	return 0;
}

// Check Stuff

int spikeCheck(){
	if(usrx == 18 || usrx == 19)
		spikeCheckInt = 1;
	return 0;
}

int waterCheck(){
	if(usry >=13 && usry <= 18 && usrx >= 1 && usrx <= 6)
		waterCheckInt = 1;
	return 0;
}

int fieldCheck(){
	if(usry >=13 && usry <= 18 && usrx >= 11 && usrx <= 16)
		fieldCheckInt = 1;
	return 0;
}

int varReset(){
	spikeCheckInt = 0;
	waterCheckInt = 0;
	moveCheckInt = 0;
	fieldCheckInt = 0;
	return 0;
}

int caps(){
	if(health > 500)
		health = 500;
	if(hunger > 100)
		hunger = 100;
	if(hunger < 0)
		hunger = 0;
	return 0;
}

int checks(){
	spikeCheck();
	waterCheck();
	fieldCheck();
	return 0;
}

int checkMath(){
	if(moveCheckInt==1 && spikeCheckInt==1){
		health-=20;
		mvprintw(5,40,"You tread on some sharp spikes! (-20HP)");
	}
	if(moveCheckInt==1 && waterCheckInt==1){
		health+=20;
		mvprintw(5,40,"You wade through a healing pond! (+20HP)");
	}
	if(moveCheckInt==1 && fieldCheckInt==1){
		hunger+=5;
		mvprintw(5,40,"You wander through a field and find some food! (-5 Hunger)");
	}
	if(hunger < 0 && moveCheckInt==1){
		health-=20;
		attron(COLOR_PAIR(6));
		mvprintw(6,40,"WARNING: Your Hunger has hit 0! (-20HP)");
	}
	return 0;
}

int quitBoolChoice(){
	if(ch=='q'){
		erase();
		printw("Are you sure you want to quit?[y/n]");
		if((ch=getch())=='y'){
			quitBool = 1;
		}
		else if((ch=getch())=='n'){
			quitBool = 0;
		}
	}
	return 0;
}

// Main Stuff

int main(){
	initscr();
	start_color();
	colorContent();
	printw("What's your name?\n");
	scanw("%s",pName);
	printw("Wow, %s? That's a really gay name.", pName);
	noecho();
	while((ch=getch()) != 'q' && health > 0){
		varReset();
		erase();
		if(pInput(ch)==1)
			hunger--;
		checks();
		checkMath();
		caps();
		drawMap();
	}
	erase();
	attron(COLOR_PAIR(6));
	printw("GAME OVER");
	getch();
	printw("\n");
	attron(COLOR_PAIR(4));
	if(ch=='q'){
		printw("\nYou quit.");
	}
	else if(health==0){
		printw("\nYou died.");
	}
	printw("\nPress 'q' to exit.");
	while((ch=getch())!='q'){
		attron(COLOR_PAIR(6));
		mvprintw(3,0,"Press 'q' to exit.");
	}
	endwin();
	return 0;
}