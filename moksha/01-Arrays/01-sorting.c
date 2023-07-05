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
	printf("slection sorted :");
	for(i = 0;i < len; i++)
		printf("%d\n",p[i]);
	
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
	printf(" bubble sorted :");
	for(i = 0;i < len; i++)
		printf("%d\n",p[i]);
	
	return 0;
}

int insertion_sort(int *p, int len)
{


}


int main()
{
	int a[] = {3, 5, 1, 6, 4};
	int len;
	len = sizeof(a)/sizeof(a[0]);
//	selection_sort(a, len);
	bubble_sort(a, len);

}


