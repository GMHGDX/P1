#include<stdio.h>
#include<getopt.h> //optarg
#include<stdlib.h> //EXIT_FAILURE

int main(int argc, char *argv[]){
	printf("You are in oss.c");
	
	int proc, simul, iter;

	char opt;
    while((opt = getopt(argc, argv, optarg)) != -1 )
    {
        switch (opt)
        {
        case 'h':
			printf("This is your help message!");
            break;
        case 'n':
            proc = atoi(optarg);
			printf("proc/n: " + proc);
            break;
        case 's':
            simul = atoi(optarg);
			printf("simul/s: " + proc);
            break;
        case 't':
            iter = atoi(optarg);
			printf("iter/t: " + proc);
            break;
        default: /* '?' */
            printf ("Invalid option %c\n", optopt);
            return (EXIT_FAILURE);
        }
    }
return 0;
}

