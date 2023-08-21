#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int check_n_string(const char* str, int gcd)
{
    int len = strlen(str);
    int i = 0, retval = 0;
	printf("gcd :%d, str :%s\n", gcd, str);

    for (i = gcd; i < len; i = i + gcd)
    {
        retval = strncmp(str, str + i, gcd);
		printf("i :%d, retval :%d\n", i, retval);
		continue;
        if (retval != 0)
            return -1;
    }
	printf("\n");
    return 1;
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

char* gcd_string(const char *a, const char *b)
{
    int lena = strlen(a);
    int lenb = strlen(b);
    int g = gcd(lena, lenb);
    int t = check_n_string(a, g);
    int k = check_n_string(b, g);
    char *ss = malloc((g + 1) * sizeof(char));

	printf("t :%d\n", t);
	printf("k :%d\n", k);

    if (k == 1 && t == 1)
    {
        strncpy(ss, a, g);
        ss[g] = '\0';
    }
	printf("ss :%s\n", ss);
	return ss;
}

struct testdata
{
	char s1[128];
	char s2[128];
};

struct testdata data[] = {
	{"abcabcabc", "abc"},
	{"ababab", "abab"},
	{"LEET", "CODE"}
};

int main()
{
	int i = 0;
	char *s1, *s2;

	for (i = 0; i < sizeof(data)/sizeof(struct testdata); i++)
	{
		s1 = data[i].s1;
		s2 = data[i].s2;

		char* r = gcd_string(s1, s2);
		printf("%s\n", r);
	}
    return 0;
}
