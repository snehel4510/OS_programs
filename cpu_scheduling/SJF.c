#include <stdio.h>
#include <stdlib.h>

struct process
{
    int at, bt, ct, wt, tat, p;
} process[10];

struct process temp;
int main()
{
    int number, i, j, min;
    float atat = 0, awt = 0;
    printf("enter the number process : ");
    scanf("%d", &number);
    printf("enter arrival and burst time :-\n");
    for (i = 0; i < number; i++)
    {
        printf("p[%d]:", i + 1);
        scanf("%d %d", &process[i].at, &process[i].bt);
        process[i].p = i + 1;
    }
    // sort the processes by arrival time
    for (i = 0; i < number - 1; i++)
    {
        for (j = i; j < number; j++)
        {
            if (process[i].at > process[j].at)
            {
                temp = process[i];
                process[i] = process[j];
                process[j] = temp;
            }
            if (process[i].at == process[j].at) // if same arrival time then sort by burst time
            {
                if (process[i].bt > process[j].bt)
                {
                    temp = process[i];
                    process[i] = process[j];
                    process[j] = temp;
                }
            }
        }
    }
    // first process will be the one with least arrival time
    if (process[0].at > 0)
        printf("cpu was idle for 0 to %d\n", process[0].at - 1);
    process[0].ct = process[0].at + process[0].bt;
    process[0].tat = process[0].bt;
    printf("process in order : %d\n", process[0].p);
    // to check how many process will be in the readyqueue till cuurrent process completion's time
    int time = process[0].ct;
    for (i = 1; i < number; i++)
    {
        // when CPU will be Idle
        if (process[i].at > time)
        {
            process[i].ct = process[i].at + process[i].bt;
            printf("cpu was idle for %d to %d\n", time, process[i].at - 1);
            time = process[i].ct;
            process[i].wt = 0;
            process[i].tat = process[i].bt;
            printf("process in order : %d\n", process[i].p);
        }
        else
        {
            // swapping current process with the one having least burst time and is in the readyqueue
            min = process[i].bt;
            for (j = i; j < number; j++)
            {
                if (process[j].at <= time && process[j].bt < min)
                {
                    min = process[j].bt;
                    temp = process[i];
                    process[i] = process[j];
                    process[j] = temp;
                }
            }
            printf("process in order : %d\n", process[i].p);
            process[i].ct = time + process[i].bt;
            time = process[i].ct;
            process[i].tat = process[i].ct - process[i].at;
            process[i].wt = process[i].tat - process[i].bt;
        }
        atat += process[i].tat;
        awt += process[i].wt;
    }
    printf("process\t\tat\tbt\twt\ttat\tct\n");
    for (i = 0; i < number; i++)
        printf("%d\t\t%d\t%d\t%d\t%d\t%d\t\n", process[i].p, process[i].at, process[i].bt, process[i].wt, process[i].tat, process[i].ct);
    printf("average waiting time : %f\n", awt / number);
    printf("average turn around time : %f\n", atat / number);
    return 0;
}