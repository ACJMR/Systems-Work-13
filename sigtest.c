//Colin Hosking
//Systems Work 13
//2018-11-13

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>

static void sighandler(int signo){
    if (signo == SIGUSR1){
        printf("Parent PID: %d\n",getppid());
    }
    if (signo == SIGINT){
       int fd = open("logs", O_WRONLY | O_CREAT | O_APPEND, 0666);
        if(fd < 0){
            printf("Error opening logs\n");
            exit(0);
        }
        write(fd,"Exited program due to SIGINT\n", sizeof("Exited program due to SIGINT\n"));
        exit(0);
    }
}

int main(){
    signal(SIGINT, sighandler);
    signal(SIGUSR1, sighandler);
    
    while(1){
        printf("PID: %d\n",getpid());
        sleep(1);
    }
}
