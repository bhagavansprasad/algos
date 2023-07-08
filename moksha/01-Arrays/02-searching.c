#include <stdio.h>
int linear_search(int* p, int len, int n)
{
	int i;
	for(i=0; i<len; i++)
	{
		if(n == p[i])
			return i;
	}
	return -1;
}

int binary_search(int* p,int l, int h, int n)
{
	int mid;
	while(l!=h)
	{
		mid = (l+h)/2;
		if(p[mid] == n)
			return mid;
		else if(p[mid] > n)
		{
			h = mid-1;
		}
		else
		{
			l = mid+1;
		}
	}
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
	int a[] = {1, 4, 5, 7, 8 };
	int len, l=0, h = len ;
	len = sizeof(a)/sizeof(a[0]);

	printf("Array elements...\n");
	dump_array(a, len);

	//int v = linear_search(a, len, 5); 
	int y = binary_search(a, 0, len, 1);
	//printf("%d\n",v);
	printf("%d\n",y);
	return 0;

	if (index < 0)
	{
		printf("Value '%d' NOT FOUND\n\n", sv);
		return 0;
	}
	printf("Value '%d' FOUND at POSITION '%d'\n\n", sv, index);
	return 0;
}


