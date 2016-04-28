#include <stdlib.h>
#include <time.h>
#include <ncurses.h>
#include "map.h"

char vroom[12][12];
int plax = 1;
int play = 1;
int playhp = 100;
int maxplayhp = 100;

void definevroom (void) {
	for (int i = 0; i < 12; i++) {
		for (int ii = 0; ii < 12; ii++) {
			switch ((int)iroom[i][ii]) {
			case 0:
				vroom[i][ii] = '.';
				break;
			case 1:
				vroom[i][ii] = '#';
				break;
			case 2:
				vroom[i][ii] = 'X';
				break;
			case 3:
				vroom[i][ii] = '^';
				break;
			}
		}
	}
}

void printroom (void) {
	erase ();
	for (int i = 0; i < 12; i++) {
		for (int ii = 0; ii < 12; ii++) {
			printw ("%c", vroom[i][ii]);
		}
		printw ("\n");
	}
}

char playact (char inp) {
	char place;
	switch (inp) {
	case 'w':
		if (iroom[plax][play-1] != 1)
			play--;
		break;
	case 's':
		if (iroom[plax][play+1] != 1)
			play++;
		break;
	case 'a':
		if (iroom[plax-1][play] != 1)
			plax--;
		break;
	case 'd':
		if (iroom[plax+1][play] != 1)
			plax++;
		break;
	}

	place = vroom[play][plax];
	return place;
}

int event (char place) {
	switch (place) {
	case '.':
		mvprintw (12, 0, "The cold cobbles chill your feet");
		break;
	case '^':
		playhp -= 10;
		mvprintw (12, 0, "You tread on some sharp spikes.\nYou loose 10 hp.");
		break;
	}

	return 0;
}

int main (void) {
	clock_t t;
	srand ((unsigned) time(&t));
	initscr ();
	noecho ();
	nonl ();

	makeroom ();
	definevroom ();
	printroom ();
	mvprintw (play, plax, "@");
	mvprintw (11, 11, "");

	bool quit = 0;
	while (quit != 1) {
		char inp = getch ();
		definevroom ();
		printroom ();
		event (playact (inp));
		mvprintw (play, plax, "@");
		mvprintw (14, 0, "You have %d health", playhp);
		mvprintw (0, 13, "%d %d", plax, play);
		if (inp == 'q' || playhp <= 0)
			quit = !quit;
		if (inp == 's' && play == 11) {
			makeroom ();
			play = -1;
		}
		if (inp == 'w' && play == 0) {
			makeroom ();
			play = 12;
		}
		if (inp == 'a' && plax == 0) {
			makeroom ();
			plax = 12;
		}
		if (inp == 'd' && plax == 11) {
			makeroom ();
			plax = -1;
		}
	mvprintw (11, 11, "");
	}
	endwin ();

	return EXIT_SUCCESS;
}
