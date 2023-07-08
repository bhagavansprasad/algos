#include<stdio.h>
#include<stdlib.h>
struct student
{
	int x;
	struct student *next;
};
struct student *h;

int add_node(int v)
{
	struct student *p, *t;
	t = h;
	p = malloc(sizeof(struct student));
	p->x = v;
	p->next = NULL;
	if(h==NULL)
	{
		h=p;
		return 0;
	}
	while(t->next!=NULL)
	{
		t = t->next;
	}
	t->next = p;
	return 0;
}
int search(int v)
{
	struct student *t =h;
	int i=0;
	while(t->next!=NULL)
	{
		if(t->x == v)
		{
			return i;
		}
		t=t->next;
		i++;
	}
	printf("there is no such value present in the list\n");
	return -1;
}
int main(){
	int i;
	add_node(23);
	add_node(25);
	add_node(45);
	add_node(53);
	i = search(25);
	printf("%d\n", i);
}




