#include <stdio.h>
#include <stdlib.h>
struct node
{
	int value;
	struct node* l;
	struct node* r;
};

#define STACK_SIZE 5
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

void dump_list(void)
{
}

int main()
{
	//add_node(8);
	//add_node(6);
	//add_node(9);
}

int test_stack()
{
#if 0
	printf("is_stack_empty :%d\n", is_stack_empty());
	printf("is_stack_full  :%d\n", is_stack_full());
	push(10);
	push(20);
	push(30);
	printf("stack_peek     :%d\n", stack_peek());

	push(40);
	printf("stack_peek     :%d\n", stack_peek());

	push(50);
	printf("stack_peek     :%d\n", stack_peek());

	push(60);
	printf("stack_peek     :%d\n", stack_peek());

	printf("pop            :%d\n", pop());
	printf("pop            :%d\n", pop());
	printf("pop            :%d\n", pop());
	printf("stack_peek     :%d\n", stack_peek());

	printf("pop            :%d\n", pop());
	printf("pop            :%d\n", pop());
	printf("stack_peek     :%d\n", stack_peek());

	printf("pop            :%d\n", pop());
	printf("stack_peek     :%d\n", stack_peek());

	return 0;
#endif
}

