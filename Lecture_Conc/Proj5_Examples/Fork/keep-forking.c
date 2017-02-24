#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
    printf("Hi buddy\n");
    pid_t pid;
    int ret_wait = -50;
    for(int i=0;i<50;i++){
        pid = fork();
        if (pid<0)
            printf("Error with chil#: %d",i);
        else if (pid == 0){
            sleep(2);
            //printf("I am the child #: %d. I'm done, let me kill myself.\n",i);
            //exit(i);
            printf("I am the child #: %d.\n",i);
        }
    }
    if (pid > 0){
        wait(&ret_wait);
        printf("The child # %d, finished\n\n", WEXITSTATUS(ret_wait));
        
    }
    
    return 0;
    
}
