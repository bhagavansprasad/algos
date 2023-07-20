#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

bool flower_bed(int *a, int s, int n)
{
  int i = s-1;
  int c = 0;
	while(i-1!=0)
	{
		if(a[i]==0 && a[i-1]==0 )
		{
			c++;
		}
		i--;
	}	
	if((c-1)>=n)
		return true;
	else
		return false;
}

int main()
{
int a[] ={1, 0, 0, 0, 1};
int s = sizeof(a)/sizeof(a[0]);
bool tf = flower_bed(a, s, 2);
printf("%d\n", tf);
return 0;
}








