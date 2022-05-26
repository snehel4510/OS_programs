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
    int freq[10];
    for (int i = 0; i < 10; i++)
        freq[i] = 0;
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
        freq[str[i] - 48]++;
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
                int max = -1e5, ind = -1;
                for (int j = f - 1; j >= 0; j--)
                {
                    if (freq[a[j] - 48] >= max)
                    {
                        max = freq[a[j] - 48];
                        ind = j;
                    }
                }
                freq[a[ind] - 48] = 0;
                for (int j = ind; j < f - 1; j++)
                    a[j] = a[j + 1];
                a[f - 1] = str[i];
            }
        }
        i++;
        // printf("fram : ");
        // for (int j = 0; j < f; j++)
        //     printf("%c ", a[j]);
        // printf("\n");
        // printf("freq : ");
        // for (int j = 0; j < f; j++)
        //     printf("%d ", freq[a[j] - 48]);
        // printf("\n");
    }
    printf("The no of page faults are : %d\n", m);
    return 0;
}