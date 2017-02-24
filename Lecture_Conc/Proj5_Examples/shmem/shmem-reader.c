#include <sys/types.h>
#include <sys/stat.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>

int main(){
    //Create a shared memory
    int shm_fd;
    void *ptr;
    shm_fd = shm_open("ROME", O_RDONLY,0666);
    ptr=mmap(0, 4096, PROT_READ, MAP_SHARED, shm_fd, 0);
    printf("[Reader]: Return value: %d\n",shm_fd);
    while(1){
        //for (int k=0;k<500;k++){
        //    printf("%d: %c\n",k,(char)(ptr+k));
        //}
        printf("\n====\n[Reader]: %s\n====\n",ptr);
        sleep(3);
        fflush(stdout);
    }
    exit(0);
    
}


