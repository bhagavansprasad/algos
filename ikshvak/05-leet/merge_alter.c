#include<stdio.h>
#include<stdlib.h>

char* merge_alter(char *w1, char *w2)
{
	char *w3 = malloc(256);
	int i = 0;
	int b = 0;

	while(w1[i]!='\0')
	{

		if(w2[i]=='\0')
		{
	 		//printf("%c\n", w2[i-1]);
			while(w1[i]!='\0')
			{
				w3[b] = w1[i];
				i++;
				b++;
			}
			return w3;
	 	}
		w3[b] = w1[i];
		b++;
	//	printf("%c\n", w3[b]);
		w3[b] = w2[i];
		//printf("%c\n", w3[b]);
		i++;
		b++;
	}
	if(w2[i] != '\0')
	{
		while(w2[i]!='\0')
		{
			w3[b] = w2[i];
			i++;
			b++;
		}
		return w3;
	}
	return w3;
}

int main()
{
	char w1[] = "abcd";
	char w2[] = "jaibalayya";
	char *w3  = merge_alter(w1, w2);
	printf("%s\n", w3);
	return 0;
}

