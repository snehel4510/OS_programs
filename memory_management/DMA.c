#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *ptr1, *ptr2;
    int n;
    printf("Enter number of elements : ");
    scanf("%d", &n);
    printf("Memory allocation using Malloc : \n");
    ptr1 = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i)
        printf("Value and Address of block %d : %d , %p\n", i + 1, ptr1[i], &ptr1[i]);
    printf("Memory allocation using Calloc : \n");
    ptr2 = (int *)calloc(n, sizeof(int));
    for (int i = 0; i < n; ++i)
        printf("Value and Address of block %d : %d , %p\n", i + 1, ptr2[i], &ptr2[i]);
    free(ptr1);
    free(ptr2);
    return 0;
}
