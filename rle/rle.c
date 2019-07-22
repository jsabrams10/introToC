#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* rleCalc(char* origStr){

	size_t origLen = strlen(origStr);
	char* newStr = (char*)malloc(sizeof(char) * (3 * origLen));
	
	if(newStr == NULL){

		printf("ERROR:	INSUFFICIENT MEMORY\n");
		exit(EXIT_FAILURE);
	}

        int origIndex = 0;
	int newIndex = 0;

	while(origIndex < origLen){

		char currChar = origStr[origIndex];

		if(currChar == '0' || currChar == '1' ||
			currChar == '2' || currChar == '3' ||
			currChar == '4' || currChar == '5' ||
			currChar == '6' || currChar == '7' ||
			currChar == '8' || currChar == '9'){

			printf("error\n");
			exit(EXIT_FAILURE);
		}

		int origEndex = origIndex + 1;

		while(origEndex < origLen && origStr[origEndex] == currChar){

			origEndex++;
		}

		newStr[newIndex] = currChar;

		int currNumOccInt = origEndex - origIndex;

		if(currNumOccInt < 10){

			newStr[newIndex + 1] = currNumOccInt + '0';
			newIndex += 2;
		}

		else{

			char* currNumOccStr = (char*)malloc(sizeof(char) * 12);

			if(currNumOccStr == NULL){

				printf("ERROR:  INSUFFICIENT MEMORY\n");
				exit(EXIT_FAILURE);
			}

			sprintf(currNumOccStr, "%d", currNumOccInt);
			size_t currNumOccDigits = strlen(currNumOccStr);
			
			int tempDex = 0;

			for(; tempDex < currNumOccDigits; tempDex++){

				newStr[newIndex + tempDex + 1] =
					 currNumOccStr[tempDex];
			}

			free(currNumOccStr);
			newIndex += currNumOccDigits + 1;
		}
	
		origIndex = origEndex;
	}

	newStr[newIndex + 1] = '\0';

	if(strlen(newStr) > origLen){

		free(newStr);
		return origStr;
	}

	return newStr;
}

int main(int argc, char** argv){

	if(argc != 2){

		printf("Must enter 1 argument. Try again.\n");
		return 1;
	}

	printf("%s\n", rleCalc(argv[1]));
	return 0;
}
