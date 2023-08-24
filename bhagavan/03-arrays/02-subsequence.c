#include <stdbool.h>
#include <stdio.h>

bool isSubsequence(char * s, char * t){
	int sp, fp;

	for(sp = 0, fp = 0; s[sp] &&  t[fp]; )
	{
		//printf("sp :%d, fp :%d\n", sp, fp);
		if (s[sp] == t[fp])
		{
			sp++;
			fp++;
		}
		else
		{
			fp++;
		}
	}

	if (s[sp] == '\0')
		return true;
	else
	{
		//printf("\n");
		//printf("sp :%d, fp :%d\n", sp, fp);
		return false;
	}
}

typedef struct strings_data
{
	char s[1024];
	char t[1024];
	bool r;
}strings;

strings data[] = {
	{"abc", "bhagbavcan", true},
	{"axc", "bhagbavcan", false},
	{"bhagbavcan", "axc", false},
	{"axc", "axc", true},
	{"a", "a", true},
	{"b", "a", false},
	{"mnop", "abcdef", false},
};

int main()
{
	char *s, *t;
	int retval, res = 0, i;
	for(i = 0; i < sizeof(data)/sizeof(strings); i++)
	{
		s = data[i].s;
		t = data[i].t;
		res = data[i].r;
		retval = isSubsequence(s, t);
		if(res != retval)
			printf("FAILED : %d. %s--%s--%d--%d\n", i+1, s, t, res, retval);
		else
			printf("SUCCESS: %d. %s--%s--%d--%d\n", i+1, s, t, res, retval);
	
	}

	return 0;
}
