#include <stdio.h>
void main(void)
{
    int i=0, j=i+1,t=0,k,v,n=5;
    int a[4] = {5, 9, 1, 3};
	printf("\n before sorting \n");
    for (k = 0; k <= n - 1; k++)
		printf(" %d  ",k);
	printf("\n");
	n=n-1;
	for (v = 0; v <= n - 1; v++)
		printf(" %d  ",a[v]);
	for(i=0;i<=4;i++,n--)
	{	
		for (j=0; j <= n - 1;j++)
		{
			if(a[j]>a[j+1])
			{	
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}	
		}
		printf("\n");
	}
	n=4;
    printf("\n \n\n\n after sorting \n");
    for (k = 0; k <= n - 1; k++)
		printf(" %d  ",k);
	printf("\n");
    for (v = 0; v <= n - 1; v++)
		printf(" %d  ",a[v]);
	printf("\n");
	printf("\n");
	
}	
