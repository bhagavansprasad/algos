#include <stdio.h>
#include <string.h>
int check_n_string(char* str, int gcd)
{
    int l = strlen(str),i;
    if (gcd >= l)
        return -1;
    for (i = 0; i < l - gcd; i++)
    {
        if (strncmp(str + i, str + i + gcd, gcd) != 0)
		{
			printf("\n not a sequence \n");
            return -1;
    
		}
	}	

    return 1;
}
int main()
{
    char str[] = "abab";
    int gcd = 2;
    int result = check_n_string(str, gcd);
    printf("\n Result: %d\n", result);
    return 0;
}
