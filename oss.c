#include<stdio.h>
#include<getopt.h> //Needed for optarg function
#include<stdlib.h> //EXIT_FAILURE
#include "oss.h"

int main(int argc, char *argv[]){
	printf("You are in oss.c\n");
	
	//number of total children to launch
	int proc;
	//how many children run at the same time
	int simul;
	//number to pass to worker process (iterations) 
	int iter;

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

	worker(iter);
return 0;
}

