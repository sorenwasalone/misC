#include <ncurses.h>

char vmap[10][10] = {0};
bool dmap[2][10][10] = {0};
int imap[10][10] = {0};

int playx = 5;
int playy = 5;

int playhp = 50;
int playhun = 500;
char playname[24] = {0};

char playrace = 'a';

int playint = 0;
int playstr = 0;
int playdex = 0;

int definemaps (void)
{
	imap[8][8] = 2;

	for (int i = 0; i <= 9; i++)
	{
		imap[i][0] = 1;
		imap[i][9] = 1;
		imap[0][i] = 1;
		imap[9][i] = 1;
	}
	for (int i = 0; i <= 9; i++)
	{
		for (int ii = 0; ii <= 9; ii++)
		{
			switch (imap[i][ii])
			{
			case 0:
				vmap[i][ii] = '.';
				dmap[0][i][ii] = 0;
				break;
			case 1:
				vmap[i][ii] = '#';
				dmap[0][i][ii] = 1;
				break;
			case 2:
				vmap[i][ii] = '^';
				break;
			default:
				return 1;
			}
		}
	}
	dmap[1][playy][playx] = '1';
	vmap[playy][playx] = '@';

	return 0;
}

int dispmap (void)
{
	erase ();
	move (0, 0);
	for (int i = 0; i <= 9; i++)
	{
		for (int ii = 0; ii <= 9; ii++)
		{
			printw ("%c", vmap[i][ii]);
		}
		printw ("\n");
	}
	return 0;
}

int runcom (char ch)
{
	switch (ch)
	{
	case 113:
		erase ();
		mvprintw (20, 0, "Are you sure you want to quit? y/n");
		char quit = getch ();
		if (quit == 121)
		{
			return 1;
		} else {
			dispmap ();
			break;
		}
	case 119:
		if (dmap[0][playx][playy - 1] == 0)
		{
			playy--;
			definemaps ();
			erase ();
			dispmap ();
			mvprintw (10, 0, "Player moved north");
			break;
		} else {
			erase ();
			dispmap ();
			mvprintw (10, 0, "Impassable terrain");
			break;
		}
	case 115:
		if (dmap[0][playx][playy + 1] == 0)
		{
			playy++;
			definemaps ();
			erase ();
			dispmap ();
			mvprintw (10, 0, "Player moved south");
			break;
		} else {
			erase ();
			dispmap ();
			mvprintw (10, 0, "Impassable terrain");
			break;
		}
	case 97:
		if (dmap[0][playx - 1][playy] == 0)
		{
			playx--;
			definemaps ();
			erase ();
			dispmap ();
			mvprintw (10, 0, "Player moved west");
			break;
		} else {
			erase ();
			dispmap ();
			mvprintw (10, 0, "Impassable terrain");
			break;
		}
	case 100:
		if (dmap[0][playx + 1][playy] == 0)
		{
			playx++;
			definemaps ();
			erase ();
			dispmap ();
			mvprintw (10, 0, "Player moved east");
			break;
		} else {
			erase ();
			dispmap ();
			mvprintw (10, 0, "Impassable terrain");
			break;
		}
	default:
		erase ();
		dispmap ();
		mvprintw (10, 0, "No such command");
		playhun++;
		break;
	}

	return 0;
}

int dispplay (void)
{
	mvprintw (0, 21, "Character data:");
	mvprintw (1, 23, "Name is %s", playname);
	mvprintw (2, 23, "HP is %d", playhp);
	mvprintw (3, 23, "Hunger is %d", playhun);
	if (playrace == 'a')
	{
		mvprintw (4, 23, "Species is wolf");
	} else if (playrace == 'b') {
		mvprintw (4, 23, "Species is cat");
	} else if (playrace == 'c') {
		mvprintw (4, 23, "Species is fox");
	}

	return 0;
}

int checkdead (void)
{
	if (playhp <= 0 || playhun <= 0)
	{
		erase ();
		mvprintw (0, 0, "You are dead");
		return 1;
	}

	return 0;
}

int checkloc (void)
{
	switch (imap[playx][playy])
	{
	case 2:
		mvprintw (11, 0, "The spikes hurt you");
		playhp += - 10;
		break;
	}

	return 0;
}

int speciescreate (void)
{
	erase ();
	mvprintw (0, 0, "Choose your species:\n");
	mvprintw (2, 4, "a	wolf	+4 str\n");
	mvprintw (3, 4, "b	cat	+4 dex\n");
	mvprintw (4, 4, "c	fox	+4 int\n");
	mvprintw (6, 0, "");
	playrace = getch ();

	switch (playrace)
	{
	case 'a':
		playstr += 4;
		break;
	case 'b':
		playdex += 4;
		break;
	case 'c':
		playint += 4;
		break;
	}

	return 0;
}

int main (void)
{
	initscr ();
	raw ();
	echo ();

	printw ("Please enter your hero's name:\n # ");
	scanw ("%s", playname);
	noecho ();

	speciescreate();

	definemaps ();
	dispmap ();
	dispplay ();
	
	bool error = 0;
	char plaact = 0;
	while (error == 0)
	{
		plaact = getch ();
		error = runcom (plaact);
		checkloc ();
		playhun--;
		dispplay ();
		definemaps ();
		if (checkdead () == 1)
		{
			error = 1;
			getch ();
		}
	}

	endwin ();

	return 0;
}
