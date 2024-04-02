#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>


int global = 100;

int main(int arc, char** argv[]){
    printf("Name: %s \n", argv[0]);
    int local = 1;
    pid_t pid_fork = fork();
    if(pid_fork == 0){
        printf("Child process\n");
        local ++;
        global ++;
        printf("Child pid = %d, parent pid = %d\n", getpid(), getppid());
        printf("Child's local = %d, child's global = %d\n", local, global);
        int s = execl("/bin/ls", "ls", "-l", argv[1], NULL);
        exit(s);
    } else {
        int stat=0;
        wait(&stat);
        printf("Prent process\n");
        printf("Parent pid = %d, child pid = %d\n", getpid(), pid_fork);
        printf("Child exit code: %ls\n", stat);
        printf("Parent's local = %d, parent's global = %d\n", local, global);
        return WEXITSTATUS(stat);
    }
    
    return 0;
}