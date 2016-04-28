#include <time.h>
#include <stdlib.h>

//In format randint(Min Int, Max Int, seed);

int randint (int min, int max, int seed){
	if(rand()%1!=1){
		clock_t t;
		srand((unsigned)time(&t));
	}
	int n = (rand()%((max-min)*seed)/seed);
	return n;
}
