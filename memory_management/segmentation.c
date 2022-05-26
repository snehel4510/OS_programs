#include <stdio.h>
#include <math.h>
int main()
{
    // printf("Enter the no of segments : ");
    // int n;
    // scanf("%d", &n);
    // int seg[n][2];
    // printf("Enter base address and bound of each segment :-\n");
    // for (int i = 0; i < n; i++)
    // {
    //     printf("For segement %d : ", i);
    //     scanf("%d %d", &seg[i][0], &seg[i][1]);
    // }
    // int las, lab;
    // printf("Enter the logical address(segment and length) :");
    // scanf("%d %d", &las, &lab);
    // if (las >= n)
    //     printf("wrong segment entered\n");
    // else if (lab <= seg[las][1])
    //     printf("Physical address : %d\n", lab + seg[las][0]);
    // else
    //     printf("Address out of bounds\n");

    int seg[4][2];
    seg[2][0] = -1, seg[2][1] = -1;
    printf("Enter base address and size of each segment :-\n");
    char s[4][20] = {"Program Code", "Heap", "", "Stack"};
    for (int i = 0; i < 4; i++)
    {
        if (i == 2)
            continue;
        printf("For %s : ", s[i]);
        scanf("%d %d", &seg[i][0], &seg[i][1]);
    }
    int va;
    printf("Enter the virtual address :");
    scanf("%d", &va);
    int b[14];
    for (int i = 0; i < 14; i++)
    {
        b[i] = va % 2;
        va = va / 2;
    }
    for (int i = 0; i < 7; i++)
    {
        int temp = b[i];
        b[i] = b[13 - i];
        b[13 - i] = temp;
    }
    int segment = b[1] + b[0] * 2;
    if (segment == 2)
    {
        printf("Invalid segment\n");
        return 0;
    }
    int offset = 0;
    for (int i = 13; i >= 2; i--)
    {
        if (b[i])
            offset += pow(2, 13 - i);
    }
    printf("Segment : %s\nOffsset : %d\n", s[segment], offset);
    printf("Physical address : %d\n", offset + seg[segment][0]);
    return 0;
}