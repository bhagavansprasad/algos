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
int main()
{	
	c(5);
	c(6);
	c(8);
	r();
	d(6);
	r();
}	
