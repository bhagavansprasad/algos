
#include <stdio.h>

void bubble(int a[])
{
    int i,j,t,k,v,n=5;
    for (v = 0;v<= n-1;v++)
        printf(" %d  ",a[v]);
    for (i=0;i<4;i++,n--)
    {    
        for (j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {    
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }    
        }
        printf("\n");
    }
    n = 5;
    printf("\n\n\nAfter sorting:\n");
    for (k = 0; k < n; k++)
        printf(" %d  ", a[k]);
    printf("\n");
    printf("\n");
}
void main()
{
    int a[] = {5, 9, 1, 3, 7};
    bubble(a);
}
