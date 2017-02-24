/*****************************************************************************
* FILE: join1.cpp
* DESCRIPTION:
*   This example demonstrates how to "wait" for thread completions by using
*   the Pthread join routine.  Since not all current implementations of
*   Pthreads create threads in a joinable state, the threads in this
*   example are explicitly created in a joinable state so that they can
*   be joined later.
* AUTHOR: 8/98 Blaise Barney
* LAST REVISED:  04/06/05
******************************************************************************/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_THREADS	4

long final_result;

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
     //final_result += tmp;
   }
   printf("Thread %d result = %lu\n",id_thr, result);
   final_result += result;
   pthread_exit((void *) result);
}

int main(int argc, char *argv[])
{
   pthread_t thread[NUM_THREADS];
   pthread_attr_t attr;
   int rc;
   long status;
   long t;

   /* Initialize and set thread detached attribute */
   pthread_attr_init(&attr);
   pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

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
   printf("The final sum is %lu\n",final_result);
   printf("The final local sum is %lu\n",local_final_sum);
   pthread_exit(NULL);
}
