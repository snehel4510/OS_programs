// Program to implement first come first serve CPU scheduling algorithm with arrival time
#include <stdio.h>
int main()
{
    int i, j, n, at[30], bt[30], tat[30], wt[30];
    float awt = 0, att = 0;
    printf("Enter the number of processes : ");
    scanf("%d", &n);
    printf("Enter the arrival time and burst time of processes :-\n");
    for (i = 0; i < n; i++)
    {
        printf("Process %d : ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
    }
    // sort the processes on the basis of their arrival time
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (at[i] > at[j])
            {
                int temp = at[i];
                at[i] = at[j];
                at[j] = temp;
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
            }
        }
    }
    // process start time
    int st = at[0];
    printf("Process\t\tArrival Time\tBurst Time\tTurnaround Time\tWaiting Time\n");
    for (i = 0; i < n; i++)
    {
        wt[i] = st - at[i];
        st += bt[i];
        tat[i] = wt[i] + bt[i];
        awt = awt + wt[i];
        att = att + tat[i];
        printf("P[%d]\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, at[i], bt[i], tat[i], wt[i]);
    }
    awt = awt / n;
    att = att / n;
    printf("Average waiting time=%f\n", awt);
    printf("Average turnaround time=%f\n", att);
    return 0;
}
