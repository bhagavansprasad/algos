#include<stdio.h>
#include<stdlib.h>
char* merge_alter(char* a, char* b)
{
    char* c = malloc(256);
    int i, j;
    for(i = 0, j = 0; a[i] != '\0'; i++, j++)
    {
        if(b[i] == '\0')
        {
            for(i=i,j=j; a[i] != '\0'; i++, j++)
                c[j] = a[i];
            return c;
        }
        c[j] = a[i];
        j++;
        c[j] = b[i];
    }

    if(b[i] != '\0')
    {
        for(i=i,j=j; b[i] != '\0'; i++, j++)
            c[j] = b[i];
        return c;
    }
    return c;
}
void main()
{
    char a[] = "abcf";
    char b[] = "th";
    char* c = merge_alter(a, b);
	printf("\n%s\n",c);
	
}
