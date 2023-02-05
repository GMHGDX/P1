#include<stdio.h>
#include<getopt.h> //Needed for optarg function
#include<stdlib.h> //EXIT_FAILURE
#include "oss.h"

int main(int argc, char *argv[]){
	printf("You are in oss.c\n");
	
	int proc, simul, iter;

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
			printf("proc,n: %i", proc);
			printf("\n");
            break;
        case 's':
            simul = atoi(optarg);
			printf("simul,s: %i", simul);
			printf("\n");
            break;
        case 't':
            iter = atoi(optarg);
			printf("iter,t: %i", iter);
			printf("\n");
            break;
        default: /* '?' */
            printf ("Invalid option %c\n", optopt);
            return (EXIT_FAILURE);
        }
    }
	Worker(iter);
return 0;
}

