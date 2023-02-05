#include<stdio.h>
#include<stdlib.h>
#include <unistd.h> //for sleep() and pid_t 
#include "oss.h"

int worker(int iter){
	printf("You are in worker.c \n");

    printf("Amount of loops: %i \n", iter);

    for(int i = 1; i < (iter + 1); i++){
        //EX: WORKER PID:6577 PPID:6576 Iteration:3 before sleeping
        printf("WORKER PID: %i PPID: %i Iteration: %i before sleeping \n", 1, 2, i);
        sleep(5);
        printf("WORKER PID: %i PPID: %i Iteration: %i after sleeping \n", 1, 2, i);
    }
}
