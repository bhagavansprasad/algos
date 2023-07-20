#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int b;
char *rev_ovel(char *w)
{
	int i =0, b=0, size = sizeof(w)/sizeof(w[0]); int a[sizeof(size)];
	//int size2 = 0;
	char *w1 = (char *)malloc(sizeof(w)+1);
	printf("size = %d\n", size);
	while(i<size)
	{
		if(w[i] == 'a' || w[i] =='A' || w[i] == 'e' || w[i] == 'E' || w[i] ==
		'0' || w[i] == 'O' || w[i] == 'i' || w[i] == 'I' || w[i] == 'u' || w[i] ==
		'U'){
		printf("%d\n", i);
		a[b] = i;
		b++;
		}
		i++;
	}
	i = 0;
	//size2 = sizeof(a)/sizeof(a[0]);
	//printf("yo = %d\n", b);
	//size2 = size2-1;
	b = b-1;
	while(i<b)
	{
		("yo %d\n", b);
		char temp = w[a[i]];
		w[a[i]] = w[a[b]];
		w[a[b]] = temp;
		i++;
		b--;
	}
	w1 = w;
	w1[sizeof(w)]= '\0';
	return w1;
}
	int main()
	{
		char w[10] = "leetcode";
		char *rev = rev_ovel(w);
		printf("%s\n", rev);
		return 0;
	}
