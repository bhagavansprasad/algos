#include<stdio.h>
#include<stdlib.h>
struct student{
	int x;
	struct student* next;
};
struct student *h;

int add_node(int v)
{
	struct student *p, *t, *c;
	p = malloc(sizeof(struct student));
	p->x = v;
	t = h;
	if(h == NULL || h->x > v)
	{
		p->next = h;
		h=p;
		return 0;
	}
	while(t->next!=NULL)
	{	
        if(t->next->x >= v)
		{
			p->next = t->next;
			t->next = p;
			return 0;
			printf("%d\n", t->x);
		}

		else if(t->next->x < v && t->next!=NULL)
		{
          t = t-> next;
		}
	}
	t->next = p;
	return 0;
}


	void dump_list()
	{
		struct student *t = h;
		while(t->next != NULL)
		{
			printf("%d\n", t->x);
				t = t->next;
		}
	}

int main()
{
 add_node(10);
 add_node(12);
 add_node(9);
 add_node(3);
 add_node(5);
 add_node(45);
 add_node(62);
 add_node(73);
 dump_list();
 return 0;
}



