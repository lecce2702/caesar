#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

const char *str = "Testsatz zum verschluesseln";

int main(void){
	int shift;
	char num[16];

	printf("Bitte Zahl fuer Verschiebung eingeben (1-26)!");
	fflush(stdout);

	if (fgets(num, 16, stdin) == NULL){

		exit(EXIT_FAILURE);
	}

	shift = (int) strtol(num, NULL, 0);

	if (shift < 1 || shift > 26){
		fprintf(stderr, "Zahl fuer Verschiebung ist ausserhalb der Grenzen!");
		exit(EXIT_FAILURE);
	}

	while (*str){
		if(!isspace(*str) || !isblank(*str)){
			printf("%c", (((*str - 97) + shift) %26) + 97);
		}
		else{
			printf("%c", *str);
		}

		str += 1;
	}
	exit(EXIT_SUCCESS);
}
