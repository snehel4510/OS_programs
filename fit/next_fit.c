#include <stdio.h>
int main()
{
    printf("Enter the no. of memory paritions and processes : ");
    int n1, n2;
    scanf("%d %d", &n1, &n2);
    int pro[n2][2], part[n1];
    printf("Enter the size of each memory partitions one by one :- \n");
    for (int i = 0; i < n1; i++)
        scanf("%d", &part[i]);
    printf("Enter the size for each process one by one : ");
    for (int i = 0; i < n2; i++)
    {
        scanf("%d", &pro[i][0]);
        pro[i][1] = -1;
    }
    int k = -1;
    for (int i = 0; i < n2; i++)
    {
        k++;
        k >= n2 ? k = 0 : k;
        for (int j = k; j < n1; j++)
        {
            if (pro[i][0] <= part[j])
            {
                part[j] -= pro[i][0];
                pro[i][1] = j + 1;
                k = j;
                break;
            }
        }
    }
    printf("processes allocated to partitions :- \n");
    for (int i = 0; i < n2; i++)
        printf("%d\t%d\n", pro[i][0], pro[i][1]);
    return 0;
}