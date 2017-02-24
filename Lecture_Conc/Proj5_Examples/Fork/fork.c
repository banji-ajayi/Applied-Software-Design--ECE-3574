#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
    printf("Hi buddy\n");
    pid_t pid;
    int ret_wait = -50;
    pid = fork();
    if (pid<0)
        printf("Error");
    else if (pid == 0){
        sleep(1);
        if (execlp("lss","lss",NULL) < 0)
            printf("What the hell!\n");
        //if (execlp("echo","echo","NICE call",NULL) < 0)
        //    printf("What the hell!\n");
        // if (execlp("./aaa","aaa",NULL) < 0)
        //    printf("What the hell!\n");
        sleep(5);
        printf("Something went wrong, let me kill myself!\n");
        exit(13);
    }
    else{
        wait(&ret_wait);
        printf("Nothing, you returned with %d, I was just checking", WEXITSTATUS(ret_wait));
        while(1){
            printf(".");
            sleep(1);
            fflush(stdout);
        }
    }
    return 0;
    
}
