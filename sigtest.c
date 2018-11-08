#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>



int main(){
  while(1){
    printf("PID: %d\n",getpid());
    sleep(1);
  }
}
