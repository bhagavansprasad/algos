#include <stdio.h>

void selection_sort(int *p, int size)
{
    int i=0, j=i+1,t=0,k,v;

    for (i = 0; i <= size-1; i++)
    {
        for (j = i+1 ; j <= size - 1; j++)
		{
			if(p[i] > p[j])
			{	
				t = p[i];
				p[i]= p[j];
				p[j]=t;
				t=0;
			}
		}
    }
}	

int bubble_sort(int *p, int size)
{
    int i,j,t,k,v;

    for (i=0; i < size; i++)
    {    
        for (j = 0; j < size - i - 1; j++)
        {
            if (p[j] > p[j + 1])
            {    
                t = p[j];
                p[j] = p[j + 1];
                p[j + 1] = t;
            }    
        }
    }

	return 0;
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
	//selection_sort(a, len);
	bubble_sort(a, len);

	printf("After sorting...\n");
	dump_array(a, len);
}
