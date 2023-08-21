#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
bool* Candies(int* candy, int Size, int n)
{
	bool *tf = (bool *)malloc(sizeof(candy));
	int i, j;
	for(i = 0; i<Size; i++)
	{
		for(j=0; j<Size; j++)
		{
			if(candy[i]+n <= candy[j])
				break;
		}
		if(j == Size)
		{
			tf[i] = true;
		}
		else{
			tf[i] = false;
		}
	}
	return tf;
}

int main()
{
	bool a = true;
	printf("%d\n, %B\n, %s\n", a, a, a); 
	/*int candy[5] = {2, 3, 5, 1, 3};
	int size = sizeof(candy)/sizeof(candy[0]);
	int n = 3, i=0;
	bool *tf = Candies(candy, size, n);
	while(i<size)
	{
		printf("%B\n", tf[i]);
		i++;
	}*/
	return 0;
}



