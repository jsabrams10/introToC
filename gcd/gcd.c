#include <stdio.h>
#include <stdlib.h>
#include <string.h>

signed gcdCalc(signed* a, signed* b){

	if(*b == 0)	return *a;
	
	do{	*a -= *b;}

	while(*a > *b);

	return gcdCalc(b, a);
}

int main(int argc, char** argv){

	if(argc != 3){

		printf("Must enter 2 arguments. Try again.\n");
		return 1;
	}

	signed a = atoi(argv[1]);
	signed b = atoi(argv[2]);
	signed temp = 0;

	if(b > a){

		temp = a;
		a = b;
		b = temp;
	}

	printf("%d\n", gcdCalc(&a, &b));
	return 0;
}
