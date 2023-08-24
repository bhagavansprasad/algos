#include "stdio.h"

void dump_array(int* nums, int numsSize)
{
    int i = 0;
    printf("i    -->");
    for (i = 0; i < numsSize; i++)
	{
        printf("%3d", i);
	}
	printf("\n");
    printf("Array-->");
    for (i = 0; i < numsSize; i++)
    {
        printf("%3d", nums[i]);
    }
    printf("\n\n");
    return;
}

void moveZeroes(int* nums, int numsSize)
{
    int fp = 0, sp = 0, i = 0;
    
	printf("numsSize :%d\n", numsSize);
    dump_array(nums, numsSize);

    for (       ; sp < numsSize && nums[sp] != 0; sp++);
	if (sp == numsSize)
	{
    	dump_array(nums, numsSize);
		return;
	}

	for (fp = sp; fp < numsSize && nums[fp] == 0; fp++);
	//printf("1. sp: %d, fp :%d\n", sp, fp);

    for ( ; fp < numsSize && sp < numsSize; )
    {
		for( ; fp < numsSize && sp < numsSize && nums[fp] != 0; fp++, sp++)
			nums[sp] = nums[fp];
    	//dump_array(nums, numsSize);
		//printf("2. sp: %d, fp :%d\n", sp, fp);

		for( ; fp < numsSize && nums[fp] == 0; fp++);

		//printf("3. sp: %d, fp :%d\n", sp, fp);
    }
	for(i = sp; i < numsSize; i++)
		nums[i] = 0;
	//printf("4. sp: %d, fp :%d\n", sp, fp);
	dump_array(nums, numsSize);
}
//int arr[] = {0, 1, 0, 3, 12};
//int arr[] = {5, 1, 0, 3, 0, 8, 0, 12};
//int arr[] = {0, 0, 0, 8, 0, 0, 0};
//int arr[] = {0, 0, 0, 0, 0, 0};
//int arr[] = {8, 1, 6, 3, 12};
//int arr[] = {0};
//int arr[] = {5};
//int arr[] = {45192,0,-659,-52359,-99225,-75991,0,-15155,27382,59818,0,-30645,-17025,81209,887,64648};
int arr[] = {5, 1, 0, 3, 9, 8, 4, 6, 0, 0, 12, 8, 9, 0, 0, 1, 5};

int main()
{
	moveZeroes(arr, sizeof(arr)/sizeof(int));
	return 0;
}

