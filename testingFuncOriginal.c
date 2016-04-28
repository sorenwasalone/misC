#include <stdio.h>

void fib(int minValue, int maxValue){
	int a = minValue - 1;
	int b = minValue;
        while (b > 0 && b < maxValue){
                printf("%d\n",b);
				int c = a + b;
				a = b;
				b = c;
        }
}

int main(){
	fib(1, 10);
	return 0;
}
