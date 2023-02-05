#include<stdio.h>
#include<getopt.h> //optarg
#include<stdlib.h> //EXIT_FAILURE

int main(int argc, char *argv[]){
	printf("You are in oss.c1\n");
	
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
            proc = atoi(optarg);
			printf("proc,n: %c" + proc);
			printf("\n");
            break;
        case 's':
            simul = atoi(optarg);
			printf("simul,s: %c", simul);
			printf("\n");
            break;
        case 't':
            iter = atoi(optarg);
			printf("iter,t: %c" + iter);
			printf("\n");
            break;
        default: /* '?' */
            printf ("Invalid option %c\n", optopt);
            return (EXIT_FAILURE);
        }
    }
return 0;
}

