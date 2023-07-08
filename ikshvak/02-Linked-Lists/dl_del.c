#include<stdio.h>
#include<stdlib.h>
struct node
{
	int x;
	struct node *next;
	struct node *per;
};
struct node *h;
int add_node(int v)
{
	struct node *t, *p;
	t = h;
	p = malloc(sizeof(struct node));
	p->x = v;
	p->next = NULL;
	p->per = NULL;
	if(h==NULL)
	{
		h=p;
		return 0;
	}
	while(t->next!=NULL)
	{
		t=t->next;
	}
	t->next = p;
	p->per = t;
	return 0;
}
int del_node(int v)
{
	struct node *t = h;
	if(h->x == v)
	{
		t = h;
		h = h->next;
		free(t);
		return 0;
	}


	while(t->x!=v&&t!=NULL)
	{
		t = t->next;
	}
	if(t!=NULL)
	{
		t->per->next = t->next;
		if(t->next!=NULL)
		{
			t->next->per = t->per;
			return 0;
		}
		t->per = NULL;
		free(t);
		return 0;
	}
	printf("the value is not available\n");
	return -1;
}
void dumplist()
{
	struct node *t = h;
	while(t!=NULL)
	{
		printf("%d\n", t->x);
		t = t->next;
	}
}
int main()
{
	add_node(10);
	add_node(30);
	add_node(70);
	add_node(88);
	add_node(43);
	add_node(27);
	add_node(54);
	printf("before deleting\n");
	dumplist();
	del_node(30);
	del_node(10);
	printf("after deleting\n");
	dumplist();
	return 0;
}

