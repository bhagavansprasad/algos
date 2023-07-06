#include<stdio.h>

int linear_ser(int* p, int v, int s)
{
	int i;
	for(i=0; i<s; i++)
	{
		if(p[i] == v)
		{
			return i;
		}
	}
	return -1;
}

int bin_ser(int* arr, int l, int h, int v)
{
	int mid;
	while(h!=l)
	{
		mid = (h+l)/2;
		if(arr[mid] == v)
			return mid;
		else if(arr[mid] > v)
		{
			h = mid-1;
		}
		else
		{
			l = mid+1;
		}

    }
}


int main()
{
	int arr[] = {1, 2, 4, 6, 7, 8, 9};
	int l, h;
	l = 0; 
	h = sizeof(arr)/sizeof(arr[0]);
	//int v = linear_ser(arr, 1, h);
	int b = bin_ser(arr, l, h, 9);
	printf("%d\n", b);
}




