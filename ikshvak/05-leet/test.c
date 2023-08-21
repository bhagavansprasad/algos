#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int vowel(char v)
{
	char c = tolower(v);
	switch(c)
	{
		case 'a':
			return 0;
		case 'e':
			return 0;
		case 'i':
			return 0;
		case 'o':
			return 0;
		case 'u':
			return 0;
		default:
			return 1;
	}
}
char *rev(char *w)
{
	int i, len =0, j = 0;
	len = sizeof(w)/sizeof(w[0]);
	char *w1 = (char *)malloc(sizeof(len)+1);
		for(i = 0; i<len; i++)
		{
			if(vowel(w[i]) == 0)
			{
				w1[i] = '\0';
				printf("index = %d\n", i);
			}
			else
			{
				w1[i] = w[i];
			}
		}

	for(i = len-1; i>=0; i--)
	{
		if(vowel(w[i]) == 0)
		{
			while(w1[j]!='\0')
			{
				j++;
			}
			w1[j] = w[i];

		}
	}
	w1[len] = '\0';
	return w1;
}




	int main()
	{
		char w[10] = "hello";
		char *w1 = rev(w);
		printf("%s\n", w1);
		return 0;
	}










