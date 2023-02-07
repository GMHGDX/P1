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
        case 'h':
			printf("This is your help message!\n");
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
            //Parent waits until the children are done (after the simul number of processes)
            // if(mod(i, simul) == 0){
            //     childpid = waitpid(childpid, &stat, 0);
            // }
            if(i >= simul){
                //childpid = waitpid(-1, &stat, 0);
                wait(&stat);
                printf("---------------------------mkamin a baby");
            }

            //wait again on the very last process if proc isnt evenly divisible by simul
            if(i == proc){
                childpid = waitpid(childpid, &stat, 0);
            }
        }
    }
    return 0;
}

// //Modulus calculation in order to determine how many run simultaneously before doing wait function
// int mod(int n, int d){
//     int remainder = n - (d * ((int)(n/d)));
//     return remainder;
// }





