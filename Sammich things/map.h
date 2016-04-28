#include <stdlib.h>
#include <stdio.h>
#include <time.h>

static char iroom[12][12] = {0};

static void defineroomfile (void) {
	FILE *fp;
	fp = fopen ("/tmp/kiburm.txt", "w");
	fprintf (fp, "");
	fclose (fp);

	fp = fopen ("/tmp/kiburm.txt", "a");
	for (int i = 0; i < 12; i++) {
		for (int ii = 0; ii < 12; ii++) {
			fprintf (fp, "%c", iroom[i][ii]);
		}
	}
	fclose (fp);
}

static void defineclutter (void) {
	for (int i = 0; i < 8; i++) {
		for (int ii = 0; ii < 8; ii++) {
			int r = rand () % 1000;
			switch (r) {
				case 0 ... 20:
					iroom[i+2][ii+2] = 2;
					break;
				case 21 ... 30:
					iroom[i+2][ii+2] = 3;
			}
		}
	}
}

static void definedoors (void) {
	iroom[6][0] = 0;
	iroom[6][11] = 0;
	iroom[5][0] = 0;
	iroom[5][11] = 0;
	iroom[0][6] = 0;
	iroom[0][5] = 0;
	iroom[11][6] = 0;
	iroom[11][5] = 0;
}

static void defineroom (void) {
	for (int i = 0; i < 12; i++) {
		for (int ii = 0; ii < 12; ii++) {
			iroom[i][ii] = 0;
		}
	}
	for (int i = 0; i < 12; i++) {
		iroom[0][i] = 1;
		iroom[11][i] = 1;
		iroom[i][0] = 1;
		iroom[i][11] = 1;
	}
}

int makeroom (void) {
	defineroom ();
	definedoors ();
	defineclutter ();
	defineroomfile ();
	return EXIT_SUCCESS;
}
