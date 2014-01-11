#include "fantasy.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/* PROPRETÉ */
void bye(){
	printf( "\n-----\n"
		"Merci d'avoir joué!\n");
	sleep(2);
	system("clear");
}

void purger(void){
	int c;
	while((c=getchar()) != '\n' && c != EOF)
		{}
}

char* concat(char *s1, char *s2)
{
    char *result = malloc(strlen(s1)+strlen(s2)+1);//+1 for the zero-terminator
    //in real code you would check for errors in malloc here
    strcpy(result, s1);
    strcat(result, s2);

    return result;
}

