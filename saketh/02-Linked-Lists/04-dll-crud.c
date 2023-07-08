#include<stdio.h>
#include<stdlib.h>
struct student
{
	struct student *prev;
	int v;
	struct student *next;
};
struct student *h;
int add_node(int val)
{ 
	struct student *new=malloc(sizeof(struct student));
	new->v = val;
	new->next = NULL;
	new->prev = NULL;
	if(h==NULL)
	{
		h=new;
		return 0;
	}
	//struct student *s=h;
	struct student *t;
	for(t=h;t->next!=NULL;t=t->next);
	t->next=new;
	new->prev = t;
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
int del_node_by_value(int val) 
{
	struct student* t = h;
	if (h == NULL) 
		return 1;
	if (h->v == val) 
	{
		h = h->next;
		free(0);
		return 0;
	}
	for (t=h;t!=NULL;t=t->next) 
	{
		if (t->v == val) 
		{
			t->next->prev=t->next;
			t->prev->next=t->prev;
		}
	}
	if (t == NULL) 
		return -1;
}
int del_node(int val)
{
	struct student *t = h;
	while(t->v!=val	&&	t!=NULL)
		t = t->next;
	if(t!=NULL)
	{
		t->prev->next = t->next;
		if(t->next!=NULL)
		{
			t->next->prev = t->prev;
			return 0;
		}
		t->prev = NULL;
		free(t);
		return 0;
	}
	printf("the value is not available\n");
	return -1;
}
int delete_by_value(int val)
// no number is not working
// first node deletion is not working
{
	struct student *t = h;
	if(h->v==val)
	{
		h->next->prev=h->prev;
		h=h->next;
	}
	for(t=h ; t->v!=val && t!=NULL;t->next);
	if(t!=NULL)
	{
		t->prev->next = t->next;
		if(t->next!=NULL)
		{
			t->next->prev = t->prev;
			return 0;
		}
		t->prev = NULL;
		free(t);
		return 0;
	}
	if(t==NULL)
		return -1;

}
int main()
{
	add_node(1);
	add_node(25);
	add_node(6);
	add_node(10);
	add_node(4);
	dump_list();
	del_node(1);
	dump_list();
	return 0;
}	
