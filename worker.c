#include<stdio.h>
#include<stdlib.h>

int worker(int argc, char *argv[]){
	printf("You are in worker.c\n");
    if(argc == 2){
        char *n = argv[1];
        int loop = atoi(n);
        printf("Amount of loops: %i", loop);

    } else {
        printf("ERROR: Incorrect amount of arguments on the command line for worker");
    }
}
