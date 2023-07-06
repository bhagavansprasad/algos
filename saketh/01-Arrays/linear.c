#include <stdio.h>
#define n 5
int linear(int se,int a[])
{
	for(int i=0;i<=n;i++)
	{
		if(a[i]==se)
		{
			printf("\n  %d is found at %d\n ",se,i );
			return i;
		}
	}
	printf("\n  %d is not found at\n ",se);
	return -1;
}	
int main()
{
    int a[4] = {5, 9, 1, 3};
	int se=9;
	linear(se,a);
}
