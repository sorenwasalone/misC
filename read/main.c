#include <stdio.h>

int main(){
	FILE *fp;
	char buff[255];
	fp = fopen("/Volumes/Storage/cFiles/Read/test.txt", "r");
	fgets(buff,  255, (FILE*)fp);
	printf("%s\n", buff );
	fclose(fp);
	return 0;
}