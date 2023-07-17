#include <string.h>
#include<stdio.h>
#include<stdlib.h>
char* merge(char* a, char* b)
{
	int la = strlen(a);
	int lb = strlen(b);
	int i, j;
	char* c = (char*)malloc((2 * la + 1) * sizeof(char));

	if (la == lb)
	{
		for (i = 0, j = 0; i < la; i++)
		{
			c[j++] = a[i];
			c[j++] = b[i];
		}
		c[j] = '\0';
		return c;
	}
	if (la < lb)
	{
		for (i = 0, j = 0; i < la; i++)
		{
			c[j++] = a[i];
			c[j++] = b[i];
		}
		for (; b[i] != '\0'; i++, j++)
			c[j] = b[i];
		c[j] = '\0';
		return c;
	}
	if (la > lb)
	{
		for (i = 0, j = 0; i < lb; i++)
		{
			c[j++] = a[i];
			c[j++] = b[i];
		}
		for (; a[i] != '\0'; i++, j++)
			c[j] = a[i];
		c[j] = '\0';
		return c;
	}
	return c;
}	
int main()
{
	char a[] = "saketh";
	char b[] = "syi";
	char* c = merge(a, b);
	printf("\n%s\n", c);
	free(c);
	return 0;
}
