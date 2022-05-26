#include <stdio.h>
#include <math.h>
int main()
{
    printf("Enter logical address size and Page size in Bytes : ");
    int ls, ps, va;
    scanf("%d %d", &ls, &ps);
    int nop = ls / ps;
    int pt[nop];
    printf("Enter the page table (Base address for each page) : \n");
    for (int i = 0; i < nop; i++)
    {
        printf("For page %d : ", i);
        scanf("%d", &pt[i]);
    }
    printf("Enter the virtual address(press 0 to exit) : ");
    scanf("%d", &va);
    float m1 = log2(ls), n1 = log2(ps);
    int m = m1, n = n1;
    int b[m];
    for (int i = 0; i < m; i++)
    {
        b[i] = va % 2;
        va = va / 2;
    }
    for (int i = 0; i <= m / 2; i++)
    {
        int temp = b[i];
        b[i] = b[m - i - 1];
        b[m - i - 1] = temp;
    }
    printf("Virtual address represented in bits :- ");
    for (int i = 0; i < m; i++)
        printf("%d", b[i]);
    printf("\nNo of bits require to represent the virtual address : %d\n", m);
    printf("No of bits require to represent the page number : %d\n", m - n);
    printf("No of bits require to represent the offset : %d\n", n);
    int off = 0, pno = 0, x = 0;
    for (int i = m - 1; i >= m - n; i--)
    {
        if (b[i])
            off += pow(2, x);
        x++;
    }
    x = 0;
    for (int i = m - n - 1; i >= 0; i--)
    {
        if (b[i])
            pno += pow(2, x);
        x++;
    }
    printf("%d %d\n", pno, off);
    int pa = off + pt[pno] * ps;
    printf("Physical address : %d\n", pa);
    return 0;
}