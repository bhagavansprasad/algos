#include <stdbool.h>
#include <stdio.h>
bool canPlaceFlowers(int* a, int n, int f)
{
    int c = 0;
	bool t;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            t = true;
            if (i > 0 && a[i - 1] == 1)
                t = false;
            if (i < n - 1 && a[i + 1] == 1)
                t = false;
            if (t)
            {
                a[i] = 1;
                c++;
            }
        }
    }
	if(c>=f)
        return 1;
    return 0;
}
int main()
{
    int a[] = {0, 0, 1, 0, 0};
    int n = sizeof(a) / sizeof(a[0]);  
    int f = 2;
    bool r = canPlaceFlowers(a, n, f);
    printf("%s\n", r ? "true" : "false");
    return 0;
}

