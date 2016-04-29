#include <stdio.h>

int main(){
	int array[] = {11,13,17,20};
	
	int *aptr;
	aptr=array;
	aptr=aptr+2;
	*aptr=0;
	
	for(int x=0; x<4; x++){
		printf("Element %d: %d\n", x+1, array[x]);
	}
	char *string = ("I'm just a string. I have a bunch of text inside me. Isn't that cool?");
	puts(string);
	printf("%p\n",&string);
	printf("%lu\n",sizeof(string));
	
	return 0;
}
