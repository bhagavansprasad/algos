#include "stdio.h"
#include "strmap.h"

static void iter(const char *key, const char *value, const void *obj)
{
    printf("key: %s value: %s\n", key, value);
}

int dump_all()
{
	StrMap *sm;
	sm_enum(sm, iter, NULL);
}

int hash_example()
{
	StrMap *sm;
	char buf[255];
	int result;

	sm = sm_new(10);
	if (sm == NULL)
	{
		printf("Failure\n");
		return 0;
	}

	/* Insert a couple of string associations */
	sm_put(sm, "application name", "Test Application");
	sm_put(sm, "application version", "1.0.0");

	dump_all();
	/* Retrieve a value */
	result = sm_get(sm, "application name", buf, sizeof(buf));
	if (result == 0) {
		/* Handle value not found... */
	}
	printf("value: %s\n", buf);
	sm_delete(sm);
}

int  hash_intersection(int *p1, int size1, int *p2, int size2)
{
	int *p;
	int n = 0;
	int count = 0, i, j, t, retval;
	StrMap *sm;
	char buff[255];
	int result;

	if (size1 < size2)
	{
		p = p1;
		p1 = p2;
		p2 = p;

		n = size1;
		size1 = size2;
		size2 = n;
	}

	sm = sm_new(size1);

	for (i = 0; i < size1; i++)
	{
		sprintf(buff, "%d", p1[i]);
		sm_put(sm, buff, buff);
	}

	for (i = 0; i < size2; i++)
	{
		sprintf(buff, "%d", p2[i]);
		retval = sm_exists(sm, buff);
		if (retval > 0)
			printf("value :%d\n", p2[i]);
	}

}

int  intersection1(int *p1, int size1, int *p2, int size2)
{
	int *p;
	int n = 0;
	int count = 0, i, j, t;
	if (size1 < size2)
	{
		p = p1;
		p1 = p2;
		p2 = p;

		n = size1;
		size1 = size2;
		size2 = n;
	}

	for (i = 0; i < size1; i++)
	{
		for (j = 0; j < size2; j++)
		{
			if(p1[i] == p2[j])
			{
				count++;
				printf("%d: %d : %d\n", count, p1[i], p2[j]);
			}
		}
	}


}

int main()
{
	int a[] = {5, 2, 1, 8, 5, 9};
	int b[] = {1, 3, 10, 8, 9, 4, 20, 30};

	//intersection1(a, sizeof(a)/sizeof(int), b, sizeof(b)/sizeof(int));
	hash_intersection(a, sizeof(a)/sizeof(int), b, sizeof(b)/sizeof(int));

}
