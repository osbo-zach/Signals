#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int pid;
void custom(int signal)
{
    int i;
    for (i = 1; i < 100; i++)
    {
        printf("%d:%d\n", pid, i);
        fflush(stdout);
    }
    printf("%d:DONE\n", pid);
    fflush(stdout);
    exit(0);
}

int main()
{
    fork();
    fork();
    pid = getpid();
    (void) signal(SIGINT, custom);
    while(1);
    
    return 0;
}