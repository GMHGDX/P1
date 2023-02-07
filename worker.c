#include<stdio.h>
#include<stdlib.h>
#include <unistd.h> //for sleep() and pid_t 
// #include "oss.h"

//int worker(int iter){
int main(int argc, char *argv[]){
    int iter = atoi(argv[1]);

    int i;
    for(i = 1; i < (iter + 1); i++){
        //EX: WORKER PID:6577 PPID:6576 Iteration:3 before sleeping
        printf("WORKER PID: %ld PPID: %ld Iteration: %i before sleeping \n", (long)getpid(), (long)getppid(), i);
        sleep(1);
        printf("WORKER PID: %ld PPID: %ld Iteration: %i after sleeping \n", (long)getpid(), (long)getppid(), i);
    }
    return 0;
}

