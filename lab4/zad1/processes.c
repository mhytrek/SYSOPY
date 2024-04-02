#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int arc, char** argv[]){
    pid_t m_pid = getpid();
    int p_number = atoi(argv[1]);
    for(int i=0; i < p_number; i++){
        pid_t my_pid = getpid();
        pid_t p_pid = getppid();
        printf("my:%i , parent:%i \n", (int)my_pid, (int)p_pid);
        pid_t fpid = fork();
        if(fpid != 0){
            break;
        }
        
    }
    wait(NULL);
    if(m_pid == getpid()){
        printf("argv:%i \n", p_number);
    }
    return 0;
}