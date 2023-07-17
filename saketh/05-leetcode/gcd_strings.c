#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int check_n_string(const char* str, int gcd)
{
    int len = strlen(str);
    int i = 0, retval = 0;
    for (i = gcd; i < len; i = i + gcd)
    {
        retval = strncmp(str, str + i, gcd);
        if (retval != 0)
            return -1;
    }
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
    if (k == 1 && t == 1)
    {
        strncpy(ss, a, g);
        ss[g] = '\0';
    }
	*ss = '\0';  
	return ss;
}
int main()
{
    const char* str1 = "abcabcabca";
    const char* str2 = "ab";
    char* r = gcd_string(str1, str2);
    printf("%s\n", r);
    return 0;
}
