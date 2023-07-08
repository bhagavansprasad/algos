#include<stdio.h>
#include<stdlib.h>

struct student
{
	int v;
	struct student *next;
};

struct student *h;

int add_node(int val)
{ 
	struct student *t;
	struct student *new=malloc(sizeof(struct student));
	new->v = val;
	new->next = NULL;
	if(h==NULL)
	{
		h=new;
		return 0;
	}
	for(t = h; t->next != NULL; t = t->next);
	t->next = new;
	return 0;
}

int dump_list(void)
{
	struct student *t=h;
	if(h==NULL)
		return -1;
	for(t=h;t!=NULL	;t=t->next)
		printf("%3d ",t->v);
	printf("\n");
}
int update_by_pos(int ov, int nv)
{
	struct student *t=H;
	for(t=h;t->next!=NULL;t=t->next)
	{
		if(t->v==ov)
		{	
			t->v =nv;
			return 0;
		}
	}	
	if(t->v==ov)
	{
			t->v==ov;
			return 0;
	}		
	return -1;
}
int del_node_by_value(int val) 
{
	struct student* t = NULL;
	if (h == NULL) 
		return 1;
	if (h->v == val) 
	{
		h = h->next;
		return 0;
	}
	for (t=h;t!=NULL;t=t->next) 
	{
		if (t->v == val) 
		{
			t->next->prev=t->next;
			t->prev->next=t->prev;
			t->next=NULL;
			t->prev=NULL;
			free(t);
		}
	}
	if (t == NULL) 
		return -1;
}
int main()
{	
	add_node(5);
	add_node(6);
	add_node(7);
	add_node(8);
	add_node(9);
	del_node_by_value(7);
	dump_list();
}	
