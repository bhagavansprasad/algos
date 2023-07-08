#include<stdio.h>
#include<stdlib.h>
struct student
{
	int v;
	struct student *next;
};
struct student *h;
int c(int n)
{ 
	struct student *t;
	struct student *new=malloc(sizeof(struct student));
	new->v=n;
	new->next = NULL;
	if(h==NULL){
		h=new;
		return 0;
	}
	for( t=h;t->next!=NULL;t=t->next);
	t->next=new;
	return 0;
}
void r(void)
{
	struct student *t=h;
	for(t=h;t->next!=NULL;t=t->next)
		printf("\n %d",t->v);
	printf("\n %d \n",t->v);
}
void u(int ov,int nv)
{
	struct student *t=h;
	for(t=h;t->next!=NULL && t->v!=ov ;t=t->next);
	t->v=nv;
}
int d(int val)
{
	struct student *t=h;
	for(t=h; t->next->v!= val ; t=t->next);
	t->next=t->next->next;
	return 0;
}
int s(int val)
{	
	struct student *t=h;
	int i=1;
	for(t=h; t->next!=NULL;t=t->next)
	{
		i++;
		if(t->v==val)
		{
			printf("\n the value is at node: %d \n",i-1);
			return i-1;
		}
	}
	if(t->next==NULL && t->v==val)
	{
			printf("\n the value is at node: %d \n",i);
			return i;
	}		
	printf("\n the value is not present \n");
	return -1;
}
int ins(int val)
{
	struct student *s=h;
	struct student *t=h->next;
	struct student *new=malloc(sizeof(struct student));
	new->v=val;
	new->next = NULL;
	if(h==NULL)
	{
		h=new;
		return 0;
	}
	if(val <= h->v)
	{
		new->next=h;
		h=new;
		return 0;
	}
	for(s=h,t=h->next;	t!=NULL	;s=t,t=t->next)
	{
		if(s->v <= val && t->v >= val)
		{
			s->next=new;
			new->next=t;
			return 0;
		}
	}
	if(t==NULL)
	{
		s->next=new;
		new->next=NULL;
		return 0;
	}
}	
int main()
{	
	c(1);
	c(2);
	c(4);
	r();
	ins(0);
	ins(3);
	ins(100);
	r();
}	
