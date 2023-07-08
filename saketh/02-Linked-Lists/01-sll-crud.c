#include<stdio.h>
#include<stdlib.h>

struct student
{
	int v;
	struct student *next;
};

struct student *H;

int add_node(int n)
{ 
	struct student *t;
	struct student *new=malloc(sizeof(struct student));
	new->v = n;
	new->next = NULL;
	if(H==NULL)
	{
		H=new;
		return 0;
	}

	for(t = H; t->next != NULL; t = t->next);
	t->next = new;
	return 0;
}

void dump_list(void)
{
	struct student *t=H;
	for(t=H;t->next!=NULL;t=t->next)
		printf("%3d",t->v);
	
	//TODO: you can print last node value inside the loop
	printf("%3d",t->v);
	printf("\n");
}

void update_node_by_value(int ov,int nv)
{
	struct student *t=H;
	//TODO: What happens if the 'ov' value doesn't exists?
	for(t=H;t->next!=NULL && t->v!=ov ;t=t->next);
	t->v=nv;
}

int delete_node_by_value(int val)
{
	//TODO: What about below deleation cases?
	//First,
	//Last,
	//Single Node,
	//No Nodes cases?
	struct student *t=H;
	for(t=H; t->next->v!= val ; t=t->next);
	t->next=t->next->next;
	return 0;
}

int main()
{	
	add_node(5);
	add_node(6);
	add_node(8);
	dump_list();
}	
