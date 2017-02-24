#include <sys/types.h>
#include <sys/stat.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <time.h>
#include <stdlib.h>

int main(){
    //Create a shared memory
    int shm_fd;
    void *ptr;
    shm_fd = shm_open("ROME",O_CREAT | O_EXCL | O_RDWR,0666);
    printf("Return value: %d\n",shm_fd);
    if (shm_fd==-1)
        shm_unlink("ROME");
    shm_fd = shm_open("ROME",O_CREAT | O_EXCL | O_RDWR,0666);
    printf("Return value: %d\n",shm_fd);
    ftruncate(shm_fd,4096);
    ptr=mmap(0, 4096, PROT_WRITE, MAP_SHARED, shm_fd, 0);
    srand(time(NULL));
    int num=0;
    while(1){
        int tmp =rand()%25;
        tmp+=65;
        printf("%c\n",(char)tmp);
        sprintf(ptr+num,"%c",(char)tmp);
        num = num+1;
        sleep(1);
        fflush(stdout);
    }
    exit(0);
}
