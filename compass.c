#include <stdio.h>

int bearing;
char bChar1;
char bChar2=' ';

int getBearing(){ //Gets the bearing and converts it if needed
	printf("What is your compass bearing?\n>");
	scanf("%d", &bearing);
	bearing=bearing%360;
	return 0;
}

int bChecks(){ //Checks which quadrant the bearing falls into
	if (bearing==0)
		bChar1='N';
	
	if (bearing>0 && bearing<90){
		bChar1='N';
		bChar2='E';
	}
	
	if (bearing==90)
		bChar1='E';
	
	if (bearing>90 && bearing<180){
		bChar1='S';
		bChar2='E';
		bearing-=180;
		bearing=bearing*(-1);
	}
	
	if (bearing==180)
		bChar1='S';
	
	if (bearing>180 && bearing<270){
		bChar1='S';
		bChar2='W';
		bearing-=180;
	}
	
	if (bearing==270)
		bChar1='W';
	
	if (bearing>270 && bearing<360){
		bChar1='N';
		bChar2='W';
		bearing-=360;
		bearing=bearing*(-1);
	}
	
	return 0;
}

int bPrint(){ //Prints the stuff
	if(bChar2==' ')
		printf("Your direction is %c.\n", bChar1);
	if(bChar2!=' ')
		printf("Your direction is %c, %d° %c.\n", bChar1, bearing, bChar2);
	return 0;
}

int main(void){
	getBearing();
	bChecks();
	bPrint();
	return 0;
}
