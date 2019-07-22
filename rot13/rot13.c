#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* rot13Calc(char* targetStr){

	size_t strLen = strlen(targetStr);
	int index = 0;

	for(; index <strLen; index++){

		char currChar = targetStr[index];

		if((currChar >= 'A' && currChar <= 'M') || 
			(currChar >= 'a' && currChar <= 'm')){

			targetStr[index] += 13;
		}

		else if((currChar >= 'N' && currChar <= 'Z') ||
			(currChar >= 'n' && currChar <= 'z')){

			targetStr[index] -= 13;
		}
	}

	return targetStr;
}

int main(int argc, char** argv){

	if(argc != 2){

		printf("Must enter 1 argument. Try again.\n");
		return 1;
	}

	printf(rot13Calc(argv[1]));
	printf("\n");
	return 0;
}
