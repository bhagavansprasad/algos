#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
int isvowel(char c)
{
	if (c == 'a'||c == 'e'||c == 'i'||c == 'o'||c == 'u'||c == 'A'||c == 'E'||c == 'I' || c == 'O' || c == 'U')
		return 1;
	return 0;
}
char * reverseVowels(char *a)
{
	int i, j, f, len;
	len = strlen(a);
	char *new = (char *)malloc(len + 1);
	j = 0;
	for (i = 0; a[i]; i++)
	{
		f = isvowel(a[i]);
		new[i]=(f==1?'\0':a[i]);
	}
	new[i] = '\0';
	j = 0;
	for (i = len-1; i>=0; i--)
	{
		f = isvowel(a[i]);
		if(f)
		{
			for(;new[j]!='\0';j++);
			new[j]=a[i];
		}
	}
	return new;
}	
int main()
{
	char str[] = "saketh";
	char *res =  reverseVowels(str);
	printf("\n%s\n",res);
	return 0;
}
