#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int find_gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return find_gcd(b, a % b);
    }
}

int check(char *w, char *s, int gcd)
{
	int len, i;
	i = 0;
	if(strlen(w) == 0)
		return -1;
	len = strlen(w);
	//printf("length = %d\n", len);
	while(i<len)
	{
	 //printf("w = %s\n", w);
	 //printf("w+%d = %s\n", i,w+i);
		if(strncmp(s, w+i, gcd)!=0)
			break;

		i = i+gcd;
	}
		if(i < len)
		{
			return -1;
		}
	return 0;
}

char *gcdOfStrings(char *w1, char *w2)
{
		char *w3 = (char *)malloc(1000);
		int gcd;
		if(strlen(w1) == strlen(w2))
		{
			int z = strcmp(w1, w2);
			if(z == 0)
			{
				strcpy(w3, w2);
				w3[strlen(w2)] = '\0';
				return w3;
			}
			w3[0] = '\0';
			return w3;
		}	

		gcd = find_gcd(strlen(w1),strlen(w2));
		strncpy(w3, w2, gcd);
		
		if(check(w1, w3, gcd)!=-1 && check(w2,w3,gcd)!=-1)
		{
			strncpy(w3, w2, gcd);
			w3[gcd] = '\0';
			return w3;
		}
		w3[0]= '\0';
		return w3;

}

int main()
{
 char w1[100] = "AAAAAAAAA";
 char w2[100] = "AA";
 char *w3 = gcdOfStrings(w1, w2);
 printf("%s\n", w3);
 return 0;
 }



