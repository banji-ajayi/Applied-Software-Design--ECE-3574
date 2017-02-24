#include <stdlib.h>

int main ()
{
	printf("Hi buddy\n");
	pid_t pid;
	int ret_wait = -50;
	pid = fork();

	if (pid < 0)
	{
		printf("Error\n");

	}
	else if (pid == 0)
	{
		sleep(1);
		if (execlp("ls","ls",NULL) < 0)
		{
			printf("What the hell!\n");
		}
		if (execlp("echo","echo","Nice Call",NULL) < 0)
		{
			printf("What the hell!?\n");
		}
		if (execlp("./aaa","aaa",NULL) < 0)
		{
			printf("What the hell 2?\n");
		}
		sleep(5);
		printf("Something went wrong, let me kill myself\n"); // this part executes 
		exit(13);
	}
	else
	{
		wait(&ret_wait);
		printf("Nothing, you returned with %d, I was just checking\n", WEXITSTATUS(ret_wait)); // expects value of 13
		while(1)
		{
			printf(".");
			sleep(1);
			fflush(stdout);
		}

	}



	return 0;
}