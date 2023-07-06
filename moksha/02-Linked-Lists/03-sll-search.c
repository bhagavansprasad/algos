#include <stdio.h>
#include <stdlib.h>
struct student {
	int no;
	struct student* pnext;
};
struct student* H = NULL;

int add_node(int n) 
{
	struct student* new = NULL;
	struct student* t = NULL;

	new = (struct student*)malloc(sizeof(struct student));
	new->no = n;
	new->pnext = NULL;

	if (H == NULL) 
	{
		H = new;
		return 0;
	}

	for (t = H; t->pnext != NULL; t = t->pnext) 
	{
	}

	t->pnext = new;
	return 0;
}
int linear_search(int n)
{
	int i;
	struct student *t;
	for(i = 0,t = H; t != NULL; i++, t = t->pnext)
	{
		if(n == t->no)
			return i;
	}
}
int main() 
{

	add_node(10);
	add_node(20);
	add_node(30);
	add_node(40);
	int y = linear_search(40);
	printf("%d\n",y);

	return 0;
}

