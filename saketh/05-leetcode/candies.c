#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
bool* k(int* c, int cs, int e, int* rs)
{
    bool* r = (bool*)malloc(sizeof(bool) * cs);
    *rs = cs;
    int m = c[0], i, j, t;
    bool b;
    for (i = 1; i < cs; i++)
    {
        if (c[i] > m)
            m = c[i];
    }
    for (j = 0; j < cs; j++)
    {
        t = c[j] + e;
        b = (t > m) ? true : false;
        r[j] = b;
    }
    return r;
}
void dump_r(bool* r, int rs)
{
    printf("\n");
    int i;
    printf("Result: ");
    for (i = 0; i < rs; i++)
    {
        if (r[i]==1)
            printf("true ");
		printf("false ");
    }
    printf("\n");
}
int main()
{
    int c[] = {2, 3, 5, 1, 3};
    int cs = sizeof(c) / sizeof(c[0]);
    int e = 3,rs,i ;
    bool* r = k(c, cs, e, &rs);
    dump_r(r,rs); 
	free(r);
    return 0;
}
