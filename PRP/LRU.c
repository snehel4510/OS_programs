#include <stdio.h>
#include <stdlib.h>
int find(char a[], int f, char c)
{
    for (int i = 0; i < f; i++)
    {
        if (a[i] == c)
            return 1;
    }
    return 0;
}
int main()
{
    printf("Enter the referance string : ");
    char *str = (char *)malloc(sizeof(char) * 100);
    scanf("%s", str);
    printf("Enter the frame no : ");
    int f, i, m, h;
    i = m = h = 0;
    scanf("%d", &f);
    char a[f];
    for (int i = 0; i < f; i++)
        a[i] = '.';
    while (str[i] != '\0')
    {
        int e = 1;
        if (find(a, f, str[i]))
            h++;
        else
        {
            m++;
            for (int j = 0; j < f; j++)
            {
                if (a[j] == '.')
                {
                    a[j] = str[i];
                    e = 0;
                    break;
                }
            }
            if (e)
            {
                int late[f], min = 1e5, ind = -1;
                for (int k = 0; k < f; k++)
                {
                    late[k] = 1e-5;
                    for (int j = i - 1; j >= 0; j--)
                    {
                        if (str[j] == a[k])
                        {
                            late[k] = j;
                            break;
                        }
                    }
                }
                for (int k = 0; k < f; k++)
                {
                    if (late[k] < min)
                        min = late[k];
                    if (min == late[k])
                        ind = k;
                }
                a[ind] = str[i];
            }
        }
        i++;
    }
    printf("\nThe no of page faults are : %d\n", m);
    return 0;
}