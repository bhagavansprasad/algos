#include <stdio.h>
#define n 5
void s(void)
{
    int i=0, j=i+1,t=0,k,v;
    int a[4] = {5, 9, 1, 3, 7};
    printf("\n before sorting \n");
    for (k = 0; k <= n - 1; k++)
		printf(" %d  ",k);
	printf("\n");
	for (v = 0; v <= n - 1; v++)
		printf(" %d  ",a[v]);
    for (i = 0; i <= n - 1; i++)
    {
        for (j = i+1 ; j <= n - 1; j++)
		{
			if(a[i]>a[j])
			{	
				t=a[i];
				a[i]=a[j];
				a[j]=t;
				t=0;
			}
		}
    }

    printf("\n \n\n\n after sorting \n");
    for (k = 0; k <= n - 1; k++)
		printf(" %d  ",k);
	printf("\n");
    for (v = 0; v <= n - 1; v++)
		printf(" %d  ",a[v]);
	printf("\n");
	printf("\n");
}	
int main()
{
	s();
}	

		
		
