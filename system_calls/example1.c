// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include <sys/wait.h>
// int main(int argc, char *argv[])
// {
//     int f = fork();
//     if (f == 0)
//     {
//         // child
//         printf("child process start (pid:%d)\n", (int)getpid());
//         sleep(2);
//         printf("child process end (pid:%d)\n", (int)getpid());
//     }
//     else if (f != -1)
//     {
//         // parent
//         printf("parent process of %d in wait mode (pid:%d)\n", f, (int)getpid());
//         int w = wait(NULL);
//         printf("parent process end (pid:%d) (w : %d)\n", (int)getpid(), w);
//     }
//     else
//     {
//         // fork failed
//         fprintf(stderr, "fork failed\n");
//         exit(1);
//     }
//     return 0;
// }

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    printf("PID of ex1 = %d\n", getpid());
    int p = fork();
    if (p == -1)
    {
        printf("fork failed\n");
        exit(1);
    }
    else if (p == 0)
    {
        printf("child process running (pid:%d)\n", (int)getpid());
        printf("calling ex2 from child process\n");
        char *args[] = {NULL};
        execv("ex2", args);
    }
    else
    {
        printf("kjhefkjhf\n");
        // int w = wait(NULL);
        printf("parent process of %d in running (pid:%d)\n", p, (int)getpid());
    }
    return 0;
}
