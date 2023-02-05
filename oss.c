#include<stdio.h>
#include<getopt.h> //Needed for optarg function
#include<stdlib.h> //EXIT_FAILURE
#include <unistd.h> //for pid_t 
#include <sys/types.h>
#include "oss.h"

int main(int argc, char *argv[]){
	printf("You are in oss.c\n");

	//number of total children to launch
	int proc;
	//how many children run at the same time
	int simul;
	//number to pass to worker process (iterations) 
	int iter;
    

    pid_t getpid(void);
    pid_t getppid(void);

    printf("I am process %ld\n", (long)getpid());
    printf("My parent is %ld\n", (long)getppid());

	char opt;
    while((opt = getopt(argc, argv, "hn:s:t:")) != -1 )
    {
        switch (opt)
        {
        case 'h':
			printf("This is your help message!\n");
            break;
        case 'n':
			//atoi convert char to int
            proc = atoi(optarg);
			printf("proc,n: %i \n", proc);
            break;
        case 's':
            simul = atoi(optarg);
			printf("simul,s: %i \n", simul);
            break;
        case 't':
            iter = atoi(optarg);
			printf("iter,t: %i \n", iter);
            break;
        default: /* '?' */
            printf ("Invalid option %c \n", optopt);
            return (EXIT_FAILURE);
        }
    }

    pid_t childpid = 0;

    int i;
    for (i = 1; i <= proc; i++){
        childpid = fork();
        if (childpid == -1) {
            perror("Failed to fork");
            return 1;
        }
        if (childpid == 0){ /* child code */
            printf("I am child %ld and my parent is: %ld\n", (long)getpid(), (long)getppid());
            worker(iter);
            break;
        }
        else /* parent code */
            printf("I am parent %ld I created %ld\n", (long)getpid(), (long)childpid);

            if(i == proc){
                childpid = wait(NULL);
                if (childpid != -1){
                    printf("Waited for child with pid %ld\n", childpid);
                }
            }
    }
    return 0;
}

