#include<stdio.h>
#include<stdlib.h>
#include "oss.h"

int worker(int iter){
	printf("You are in worker.c\n");

    printf("Amount of loops: %i", iter);
    printf("\n");
}
