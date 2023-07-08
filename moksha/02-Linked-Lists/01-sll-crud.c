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

int update_node_by_value(int x, int a) 
{
	struct student* t = NULL;
	for (t = H; t != NULL; t = t->pnext) 
	{
		if (t->no == x) 
		{
			t->no = a;
			break;
		}
	}

	if (t != NULL) 
	{
		//printf("%d\n", t->no);
	}
	return 0;
}

int del_node_by_value(int n) 
{
	struct student* p = NULL;
	struct student* c = NULL;

	p = c = H;

	if (H == NULL) 
	{
		return 1;
	}

	if (H->no == n) 
	{
		H = H->pnext;
		free(c);
		return 0;
	}

	for (c = H->pnext; c != NULL; p = c, c = c->pnext) 
	{
		if (c->no == n) 
		{
			break;
		}
	}

	if (c == NULL) 
	{
		return 1;
	}

	p->pnext = c->pnext;
	free(c);
	return 0;
}
int dump_list(void) 
{
	struct student* t = NULL;
	for (t = H; t != NULL; t = t->pnext) 
	{
		printf("%4d", t->no);
	}
	printf("\n\n");

	return 0;
}
int main() 
{
	add_node(10);
	add_node(20);
	add_node(30);
	add_node(40);
	dump_list();
	update_node_by_value(10, 15);
	dump_list();
	del_node_by_value(30);
	dump_list();

	return 0;
}
