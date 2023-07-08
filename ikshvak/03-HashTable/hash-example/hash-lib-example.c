#include "stdio.h"
#include "strmap.h"

StrMap *studen_ht = NULL;

static void iter(const char *key, const char *value, const void *obj)
{
    printf("key: %s value: %s\n", key, value);
}

int dump_all()
{
	sm_enum(studen_ht, iter, NULL);
}

int hash_example()
{
	char buf[255];
	int result;
	int retval;

	studen_ht = sm_new(10);
	if (studen_ht == NULL)
	{
		printf("Failure\n");
		return 0;
	}

	/* Insert a couple of string associations */
	sm_put(studen_ht, "5", "Test data with 5   Moksha");
	sm_put(studen_ht, "10", "Test data with 10 Bhagavan");
	sm_put(studen_ht, "20", "Test data with 10 Bhagavan");

	dump_all();

	/* Retrieve a value */
	result = sm_get(studen_ht, "5", buf, sizeof(buf));
	printf("results :%d\n", result);
	if (result == 0) {
		printf("Did not find the data\n");
	}
	else
	{
		printf("value: %s\n", buf);
	}

	retval = sm_exists(studen_ht, "5");
	printf("retval :%d\n", retval);

	retval = sm_exists(studen_ht, "10");
	printf("retval :%d\n", retval);

	retval = sm_exists(studen_ht, "20");
	printf("retval :%d\n", retval);
}

int main()
{
	hash_example();
}
