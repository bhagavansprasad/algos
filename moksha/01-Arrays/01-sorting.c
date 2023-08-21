#include <stdio.h>
int selection_sort(int *p, int len)
{
	int temp,i,j;
	for (i = 0; i < len; i++)
	{
		for(j = i+1; j < len;j++)
		{
			if(p[i] > p[j])
			{
				temp = p[j];
				p[j] = p[i];
				p[i] = temp;
			}
		}
	}

	return 0;
}



int bubble_sort(int *p, int len)
{
	int temp,i,j;
	for (i = 0; i < len - 1; i++)
	{
		for(j = i+1; j < len;j++)
		{
			if(p[i] > p[j])
			{
				temp = p[j];
				p[j] = p[i];
				p[i] = temp;
			}
		}
	}
	return 0;
}

int insertion_sort(int *p, int len)
{


}

void dump_array(int *p, int size)
{
	int i = 0;

	for (i = 0; i < size; i++)
	{
		printf("%3d", *(p+i));
	}
	printf("\n");
}

int main()
{
	int a[] = {3, 5, 1, 6, 4, 0};
	int len;
	len = sizeof(a)/sizeof(a[0]);

	printf("Before sorting...\n");
	dump_array(a, len);
//	selection_sort(a, len);
	bubble_sort(a, len);

	printf("After sorting...\n");
	dump_array(a, len);

}


