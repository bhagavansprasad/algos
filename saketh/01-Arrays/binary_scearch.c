#include <stdio.h>
#define n 5
int binary(int se,int a[])
{
	int l=0,h=n-1,m=(l+(h-1))/2;
	for(l=0,h=n-1,m=(l+(h-1))/2 ;	l<=h ; m=l+(h-1)/2 )
	{	
		if(a[m]<h)
		{
			l=m;
			h=h;
		}	
		if(a[m]<h)
		{
			h=m;
			l=l;
		}
		if(a[m]==se)
		{
			printf("\n  %d is found at %d\n ",se,m );
			return m;
		}
		else 
			h=m-1;
	}
}	
int main()
{
    int a[4] = {5, 9, 1, 3};
	int se=9;
	binary(se,a);
}

