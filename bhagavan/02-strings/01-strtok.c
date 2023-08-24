#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char src[] = "   Aura Networks   Bengaluru   ";
	char deli[] = " ";
	char *token = src;
	int retval = 0;
	char *new = (char *)malloc(strlen(src)+1);
	char *t = new;
	int pos = 0, len = 0;

	token = strtok(src, deli);
	printf("token :%s, pos :%d\n", token, pos);
	strcat(t, token);
	printf("t :--%s--\n", t);
	len = strlen(token);
	t[len] = ' ';
	t[len+1] = '\0';
	printf("t :--%s--\n", t);
	while (token != NULL)
	{
		token = strtok(NULL, deli);
		if (token == NULL)
			break;
		printf("token :%s, pos :%d\n", token, pos);
		strcat(t, token);
		printf("t :--%s--\n", t);
		len = strlen(token);
		t[len] = ' ';
		t[len+1] = '\0';
	}
	printf("new   :%s, pos :%d\n", new, pos);


	/*
	for (int j = 1, str1 = argv[1]; ; j++, str1 = NULL) {
		token = strtok_r(str1, argv[2], &saveptr1);
		if (token == NULL)
			break;
		printf("%d: %s\n", j, token);

		for (str2 = token; ; str2 = NULL) {
			subtoken = strtok_r(str2, argv[3], &saveptr2);
			if (subtoken == NULL)
				break;
			printf(" --> %s\n", subtoken);
		}
	}
	*/
	return 0;
}

