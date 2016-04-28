#include <stdio.h>
int main(){
	int sentence=1;
	while(sentence==1){
		printf("1");
		sentence=2;
		while(sentence==2){
			printf("2");
			sentence=1;
		}
	}
	return 0;
}