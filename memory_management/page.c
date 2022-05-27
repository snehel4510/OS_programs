// paging concept in OS using formula -> page no = virtual address / page size and offset = virtual address % page size
#include <stdio.h>
int main()
{
    printf("Enter logical address size and Page size in Bytes : ");
    int ls, ps, va;
    scanf("%d %d", &ls, &ps);
    int nop = ls / ps;
    int ptable[nop];
    printf("Enter the page table (Base size for each page) : \n");
    for (int i = 0; i < nop; i++)
    {
        printf("For page %d : ", i);
        scanf("%d", &ptable[i]);
    }
    printf("Enter the virtual address(press 0 to exit) : ");
    scanf("%d", &va);
    while (va)
    {
        int pno = va / ps, ofs = va % ps;
        if (pno >= nop)
        {
            printf("Virtual address out of bounds\n");
            break;
        }
        printf("Physical address : %d\n", ps * ptable[pno] + ofs);
        scanf("%d", &va);
    }
    return 0;
}