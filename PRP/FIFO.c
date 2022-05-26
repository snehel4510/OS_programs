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
                for (int j = 0; j < f - 1; j++)
                    a[j] = a[j + 1];
                a[f - 1] = str[i];
            }
        }
        i++;
    }
    printf("The no of page faults are : %d\n", m);
    return 0;
}