#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <semaphore.h>

#define NUM_THREADS	8

long final_result;
pthread_mutex_t my_lock;
sem_t my_sem;

void *BusyWork(void *par)
{
    int i;
    int id_thr = (long) par;
    long result=0;
    srand (time(NULL));
    for (i=0; i<1000000; i++)
    {
        long tmp = (long)rand();
        result = result + tmp;
        //pthread_mutex_lock(&my_lock);
        sem_wait(&my_sem);
        final_result += tmp;
        //pthread_mutex_unlock(&my_lock);
        sem_post(&my_sem);
    }
    printf("Thread %d result = %lu\n",id_thr, result);
    //final_result += result;
    pthread_exit((void *) result);
}

int main(int argc, char *argv[])
{
    pthread_t thread[NUM_THREADS];
    pthread_attr_t attr;
    int rc, lock_res;
    long status;
    long t;
    double time_spent;
    clock_t begin, end;
    
    lock_res = pthread_mutex_init(&my_lock, NULL);
    if(lock_res == -1)
        exit(-1);
    lock_res = sem_init(&my_sem, 0, 1);
    if(lock_res == -1)
        exit(-1);
    
    /* Initialize and set thread detached attribute */
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
    
    //counting execution time application
    begin = clock();
    
    for(t=0;t<NUM_THREADS;t++)
    {
        printf("Creating thread %d\n", t);
        rc = pthread_create(&thread[t], &attr, BusyWork, (void *) t);
        if (rc)
        {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }
    
    /* Free attribute and wait for the other threads */
    pthread_attr_destroy(&attr);
    long local_final_sum = 0;
    for(t=0;t<NUM_THREADS;t++)
    {
        rc = pthread_join(thread[t], (void **)&status);
        if (rc)
        {
            printf("ERROR return code from pthread_join() is %d\n", rc);
            exit(-1);
        }
        printf("Completed join with thread %d sum= %lu\n",t, status);
        local_final_sum += status;
    }
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    
    if(pthread_mutex_destroy(&my_lock) == -1)
        exit(-1);
    
    printf("The final sum is %lu\n",final_result);
    printf("The final local sum is %lu\n",local_final_sum);
    printf("\n...And the sum is...");
    if(final_result == local_final_sum)
        printf("CORRECT :)\n");
    else
        printf("WRONG :(\n");
    
    printf("Application execution time %f\n",time_spent);
    pthread_exit(NULL);
}
