// Program to implement shortest job first non-preamptive CPU scheduling algorithm with arrival time
#include <stdio.h>
void swap(int a[], int i, int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}
int max(int a, int b)
{
    if (a >= b)
        return a;
    return b;
}
int main()
{
    int i, j, n, p[30], at[30], bt[30], tat[30], wt[30], q[30], v[30];
    float awt = 0, att = 0;
    printf("Enter the number of processes : ");
    scanf("%d", &n);
    printf("Enter the arrival time and burst time of processes :-\n");
    for (i = 0; i < n; i++)
    {
        p[i] = i;
        v[i] = 0;
        printf("Process %d : ", i);
        scanf("%d %d", &at[i], &bt[i]);
    }
    // sort the processes on the basis of arrival time, if arrival time is same, then sort on the basis of burst time
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (at[i] > at[j])
            {
                swap(at, i, j);
                swap(bt, i, j);
                swap(p, i, j);
            }
            else if (at[i] == at[j])
            {
                if (bt[i] > bt[j])
                {
                    swap(at, i, j);
                    swap(bt, i, j);
                    swap(p, i, j);
                }
            }
        }
    }
    i = 1;
    q[0] = p[0];
    v[0] = 1;
    int end = at[q[0]] + bt[q[0]];
    while (i < 4)
    {
        int k = i;
        for (j = 0; j < n; j++)
        {
            if (!v[j] && at[j] <= end)
            {
                v[j] = 1;
                q[i] = p[j];
                end = max(end, at[q[i]] + bt[q[i]]);
                i++;
            }
        }
        }
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", q[i]);
    }
    // // calculate waiting time and turn around time
    // printf("\nProcess\t\tArrival Time\tBurst Time\tWaiting Time\tTurn Around Time\n");
    // for (i = 0; i < n; i++)
    // {
    //     if (i == 0)
    //         wt[i] = 0;
    //     else
    //         wt[i] = wt[i - 1] + bt[i - 1];
    //     tat[i] = wt[i] + bt[i];
    //     awt = awt + wt[i];
    //     att = att + tat[i];
    //     printf("\nP[%d]\t\t%d\t\t%d\t\t%d\t\t%d", p[i], at[i], bt[i], wt[i], tat[i]);
    // }
    // awt = awt / n;
    // att = att / n;
    // printf("\nAverage Waiting Time : %f", awt);
    // printf("\nAverage Turn Around Time : %f", att);
    return 0;
}