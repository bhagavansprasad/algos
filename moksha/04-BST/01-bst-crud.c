#include <stdio.h>
#include <stdlib.h>
struct node
{
	int value;
	struct node* l;
	struct node* r;
};

#define STACK_SIZE 15
struct node *stack[STACK_SIZE] = {NULL};
//int stack[STACK_SIZE] = {0};
int top = 0;
struct node *H = NULL;

struct node *pop()
	//int pop()
{
	struct node *temp = NULL;
	//int temp = 0;
	if(top <= 0)
	{
		return NULL;
		//return -1;
	}
	temp = stack[top-1];
	top--;
	return temp;
}

int push(struct node *ptr)
	//int push(int n)
{
	struct node *temp = NULL;
	if(top > STACK_SIZE-1)
	{
		return -1;
	}
	stack[top] = ptr;
	//stack[top] = n;
	top++;
	return top;
}

int is_stack_empty(void)
{
	if(top <= 0)
	{
		return 1;
	}
	return 0;
}

int is_stack_full(void)
{
	if(top > STACK_SIZE-1)
	{
		return 1;
	}
	return 0;
}

int stack_peek(void)
{
	return top;
}



int add_node(int v)
{
	struct node *new = NULL;
	struct node *t = NULL; 

	new = (struct node*)malloc(sizeof(struct node));
	new->r = new->l = NULL;
	new->value = v;

	if(H == NULL)
	{
		H = new;
		return 0;
	}

	t = H;

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

void in_order_traversal(struct node* root)
{
	struct node* current = root;
	struct node *temp = NULL;
	while(1)
	{
		while(current != NULL)
		{
			push(current);
			current = current->l;
		}
		if(current == NULL && is_stack_empty() == 0)
		{
			temp = pop();
			printf("%3d",temp->value);
			current = temp->r;
		}

		if(current == NULL && is_stack_empty() == 1)
		{
			break;
		}
	}
	printf("\n");
}
void pre_order_traversal(struct node* root)
{
	struct node *temp = NULL;
	push(root);
	while(1)
	{
		while(is_stack_empty() == 0)
		{
			temp = pop();
			printf("%3d",temp->value);
			if(temp->r != NULL)
				push(temp->r);
			if(temp->l != NULL)
				push(temp->l);

		}
		if(is_stack_empty() == 1)
		{
			break;
		}
	}
	printf("\n");
}



void dump_list(void)
{
	pre_order_traversal(H);
	in_order_traversal(H);
}

int test_data1[] = {8, 12, 10, 7, 32, 16, 14, 11, 4, 6, 1};
int test_data2[] = {10, 12, 11, 8, 9, 5, 6};

int main()
{
	int i = 0;

	printf("In_order_traversal:\n");
	printf("pre_order_traversal:\n");


	for (i = 0; i < sizeof(test_data1)/sizeof(int); i++)
	{
		add_node(test_data1[i]);
	}

	dump_list();
	return 0;

}

