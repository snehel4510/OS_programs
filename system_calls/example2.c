#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
    printf("No we are in ex2 (PID : %d)\n", getpid());
    printf("Hello world");
    return 0;
}