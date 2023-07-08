#include<stdio.h>
#include<stdlib.h>
struct student
{
	int v;
	struct student *prev;
	struct student *next;
};
struct student *h;
int c(int n)
{ 	
	struct student *t;
	struct student *new=malloc(sizeof(struct student));
	new->v=n;
	new->next = NULL;
	new->prev
	if(h==NULL)
	{
		h=new;
		return 0;
	}
