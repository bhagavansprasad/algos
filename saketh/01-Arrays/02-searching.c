#include <stdio.h>

int linear_search (int *p, int size, int se)
{
    int i = 0;

	for(i = 0; i < size; i++)
	{
		if(p[i] == se)
			return i;
	}
	return -1;
}	

int binary_search(int *p, int size, int se)
{
	int l=0,h = size-1;
    int m=(l+(h-1))/2;

	for(l=0,h = size-1, m = (l+(h-1))/2 ; l <= h; m = l + (h-1)/2 )
	{	
		if(p[m] < h)
		{
			l = m;
			h = h;
		}	
		if(p[m] < h)
		{
			h = m;
			l = l;
		}
		if(p[m] == se)
		{
			return m;
		}
		else 
			h=m-1;
	}

    return -1;
}	

void dump_array(int *p, int size)
{
	int i = 0;

	printf("Positions-->");
	for (i = 0; i < size; i++)
		printf("%3d", i);

	printf("\n");

	printf("Values   -->");
	for (i = 0; i < size; i++)
		printf("%3d", *(p+i));
	printf("\n\n");
}

int main()
{
	int a[] = {2, 4, 1, 6, 5 };
	int len, index = 0;
	int sv = 5;
	len = sizeof(a)/sizeof(a[0]);

	printf("Array elements...\n");
	dump_array(a, len);

	//index = linear_search(a, len, sv); 

	index = binary_search(a, len, sv);
	if (index < 0)
	{
		printf("Value '%d' NOT FOUND\n\n", sv);
		return 0;
	}
	printf("Value '%d' FOUND at POSITION '%d'\n\n", sv, index);
	return 0;
}




