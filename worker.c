#include<stdio.h>
#include<stdlib.h>

int worker(int iter){
	printf("You are in worker.c\n");

    printf("Amount of loops: %i", iter);
}
