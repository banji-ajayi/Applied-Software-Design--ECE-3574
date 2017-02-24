#include <iostream>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
 
using namespace std;

int main() {
    int pipefd[2];
    int status = 0;
    pipe(pipefd);
    pid_t pid1, pid2;
    pid1 = fork();
    
    if(pid1 == 0) { // this is the child process     
        dup2 (pipefd[1], 1); //redirect output to write end of pipe
        close (pipefd[0]); //close the read end of the pipe
        execve("./generator", NULL, NULL);
    }
    
    else
        close(pipefd[1]);
            
    pid2 = fork();    
    if(pid2 == 0) { // this is the child process
        dup2 (pipefd[0], 0); //redirect input to read end of pipe
        close (pipefd[1]); //close the write end of the pipe
        execve("./consumer", NULL, NULL);
    }
    
    else
        close(pipefd[0]);
    
    sleep(1);
    
    kill(pid1, SIGTERM);
    waitpid(pid1, &status, WSTOPPED);
    cerr << "child[" << pid1 << "] exited with status " << status << endl;
    
    waitpid(pid2, &status, WEXITED);
    cerr << "child[" << pid2 << "] exited with status " << status << endl;
        
return 0;
}

