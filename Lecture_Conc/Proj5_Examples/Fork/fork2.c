#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(){
    printf("hi dad!!!\n");
    sleep(1);
    printf("What's up?!\n");
    //sleep(5);
    exit(100);
    
}
