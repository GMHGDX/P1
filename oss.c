// Name: Gabrielle Hieken
// Class: 4760 Operating Systems
// Date: 2/1/2023

#include <stdio.h>
#include <getopt.h> //Needed for optarg function
#include <stdlib.h> //EXIT_FAILURE
#include <unistd.h> //for pid_t and exec
#include <sys/types.h>
#include <sys/wait.h>

int mod(int n, int d);

int main(int argc, char *argv[]){
	//number of total children to launch
	int proc = 1;
	//how many children run at the same time
	int simul = 1;
	//number to pass to worker process (iterations) 
	int iter = 2;

    int stat;

    //Parse through command line options
	char opt;
    while((opt = getopt(argc, argv, "hn:s:t:")) != -1 )
    {
        switch (opt)
        {
        //help message
        case 'h':
			printf("To run this project: \n\n");
            printf("run the command: ./oss -n num -s num -t num\n\n");
                    printf("\tnum = can be replaced with any number below 18 | -n, -s, and -t can be typed in any order\n");
                    printf("\t-n = number of total children to launch\n");
                    printf("\t-s = how many children run at the same time\n");
                    printf("\t-t = number to pass to worker process (iterations)\n\n");
                    
                    printf("If you leave out a -n, -s, or -t it will defualt to the value 1\n\n");
                    printf("Have fun :)\n\n");

                    exit(0);
            break;
        case 'n':
			//atoi convert char to int
            proc = atoi(optarg);
			//printf("proc,n: %i \n", proc);
            break;
        case 's':
            simul = atoi(optarg);
			//printf("simul,s: %i \n", simul);
            break;
        case 't':
            iter = atoi(optarg);
			//printf("iter,t: %i \n", iter);
            break;
        default:
            printf ("Invalid option %c \n", optopt);
            return (EXIT_FAILURE);
        }
    }

    pid_t childpid = 0;

    int i;
    for (i = 1; i <= proc; i++){
        //fork process
        childpid = fork();
        if (childpid == -1) {
            perror("Failed to fork");
            return 1;
        }
        if (childpid == 0){ 
            //convert iter into a string in order to use it in the exec function
            char iterString[50];
            snprintf(iterString, sizeof(iterString), "%i", iter);

            //exec function to send children to worker
            char *args[] = {"worker", iterString, NULL};
            execvp("./worker", args);
            break;
        }
        else {
            //wait for the process to finish after running the given simul int simultaneously before starting another process
            if(i >= simul){
                wait(&stat);
            }
        }
    }
    return 0;
}





