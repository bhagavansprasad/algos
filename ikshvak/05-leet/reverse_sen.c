#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *reverse( char *w)
{
int i, j, b = 0, len;
len = strlen(w);
char *new = (char *)malloc(sizeof(len + 1));
char *w1 = (char *)malloc(sizeof(len + 1));
const char delimeter[] = " ";
i = len-1;
	while(i>=0)
	{
		if(w[i] == ' ')
		{
			j = i+1;
			while(j<len)
			{
				new[b] = w[j];
				b++;
				j++;
			}
			printf("b = %d\n", b);
			new[b] = ' ';
			b++;
			len = i;
			printf("length = %d\n", len);
		}
		i--;
	}
		j = 0;
		printf("length2 = %d\n", j); 
		while(j<len)
		{
			new[b] = w[j];
			b++;
			j++;
		}
		new[b] = '\0';
		i=0;
		while(w1[i]!='\0')
		{
	    	w1 = strtok(new, delimeter);
			i++;
		}
		return w1;
}
int main()
{
char w[100] = "the sky is    blue";
char *rev = reverse(w);
printf("%s\n", rev);
return 0;
}
