#include <stdio.h>
#include <stdlib.h>
struct node
{
	int value;
	struct node* l;
	struct node* r;
};

struct node *h = NULL;

int add_node(int v)
{
	struct node *new = NULL;
	struct node *t = NULL; 

	new = (struct node*)malloc(sizeof(struct node));
	new->r = new->l = NULL;
	new->value = v;

	if(h == NULL)
	{
		h = new;
		return 0;
	}

	t = h;

	while(t != NULL)
	{
		if(v >= t->value)
		{
			if(t->r == NULL)
			{
				t->r = new;
				return 0;
			}
			t = t->r;
		}
		else 
		{
			if(t->l == NULL)
			{
				t->l = new;
				return 0;
			}
			t = t->l;
		}
	}
	return 0;
}

void dump_list(void)
{
}

int main()
{
	add_node(8);
	add_node(6);
	add_node(9);
	return 0;
}

