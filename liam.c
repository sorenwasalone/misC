// programmed by soren ily liam ur my bestie evr <3 <3 <3
#include <stdio.h>

int main(){
	char ch;
	int mewcounter=0;
	printf("\n\n\n\nWelcome to the Liam simulator V1.0\n");
	scanf("%c", &ch);
	while(ch!='q'){
		printf("\n\n\n\nInput command...\n[1] liam\n[2] anime?\n[3] melodic house?\n[4] ochinchin\n");
		ch = getchar();
		if(ch=='1' && mewcounter<2){
			printf("\n\n\n\nmew\n");
			mewcounter++;
			ch = getchar();
		}
		if(ch=='1' && mewcounter==2){
			printf("\n\n\n\nMEW! :D\n");
			mewcounter=0;
			ch = getchar();
		}
		if(ch=='2'){
			printf("\n\n\n\nyes\n");
			ch = getchar();
		}
		if(ch=='3'){
			printf("\n\n\n\nno thank you\n");
			ch = getchar();
		}
		if(ch=='4'){
			printf("\n\n\n\nga daisuki\n");
			ch = getchar();
		}
	}
	return 0;
}
