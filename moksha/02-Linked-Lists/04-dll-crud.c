#include <stdio.h>
#include <stdlib.h>
struct student
{
	int data;
	struct student* n;
	struct student* p;
};
struct student* h = NULL;

int add_node(int v)
{
	struct student* new = NULL;
	struct student* t = NULL;
	new = (struct student*)malloc(sizeof(struct student));
	new->n = new->p = NULL;
	new->data = v;
	if(h == NULL)
	{
		h = new;
		return 0;
	}
	for(t = h;t->n != NULL;t=t->n)
	{
	}
	t->n = new;
	new->p = t;
	return 0;
}
int delete_node_by_value(int v)
{
	struct student* t=h;
	if(h->data == v)
	{
		struct student* t=h;
		h->n->p = h->p;
		h = h->n;
		free(t);
		return 0;
	}
	for(t=h;t->data != v && t != NULL;t = t->n);
	if(t != NULL)
	{
		t->p->n = t->n;
		if(t->n != NULL)
		{
			t->n->p = t->p;
			return 0;
		}
		t->p = NULL;
		free(t);
		return 0;
	}
  printf("the value is not available\n");
  return -1;
}
int dump_list(void) 
{
	struct student* t = NULL;
	for (t = h; t != NULL; t = t->n) 
	{
		printf("%d\n", t->data);
	}

	return 0;
}
int main() 
{
	add_node(10);
	add_node(20);
	add_node(30);
	add_node(40);
	delete_node_by_value(30);
	dump_list();

	return 0;
}
