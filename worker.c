#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
	printf("You are in worker.c\n");
    if(argc == 2){
        int loop = argv[1];
        printf("Amount of loops: %i", loop);

    } else {
        printf("ERROR: Incorrect amount of arguments on the command line for worker");
    }
}
