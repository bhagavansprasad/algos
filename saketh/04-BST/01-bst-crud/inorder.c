#include "stdio.h"
#include "stdlib.h"
#define max 15
struct node 
{
	struct node *left;
	struct node *right;
	int value;
};
struct node* stack[max];
struct node *H = NULL;
int needle = -1;
int isempty(void) 
{
    if (needle == -1) 
        return 1; 
	return 0; 
}
int isfull(void) 
{
    if (needle == max - 1) 
        return 1;
	return 0;
}
int push(struct node *p)
{
	if (needle > max)
	{
		printf("Stack overflow\n");
		return 0;
	}
	needle++;
	stack[needle]=p;
	return 1;
}
struct node* pop(void)
{
	struct node *node;
	if(needle < 0)
	{
		printf("  \n stack is empty \n");
		return NULL;
	}	
	node = stack[needle];
	needle--;
	return node;
}
void printstack(void)
{
	printf("\nstack:\n");
	int i=0;
	struct node *p=NULL;
	while(1)
	{
		p=pop();
		if(p == NULL)
			break;
		printf("%d:%d\n", i++, p->value);
	}
}
int add_node(int val)
{
	struct node *t = H;
	struct node *p = NULL;
	
	p = malloc(sizeof(struct node));
	p->value=val;
	p->right=NULL;
	p->left=NULL;
	if(H==NULL)
	{
		H = p;
		return 0;
	}
	while(t!=NULL)
	{
		if(val> t->value)
		{
			if(t->right == NULL)
			{
				t->right = p;
				return 0;
			}
			t=t->right;
		}
		if(val < t->value)
		{
			if(t->left==NULL)
			{
				t->left=p;
				return 0;
			}
			t=t->left;
		}	
	}
}
void inorder(void)
{
	struct node *c=NULL, *p;
	c = H;
	while(1)
	{
		if(c != NULL)
			push(c);
		if(c==NULL && isempty()==0)
		{
			p = pop();
			c = p->right;
			if(c!=NULL)
				push(c);
			printf(" %d,",p->value);
		}
		if(c != NULL)
			c=c->left;
		if(c == NULL && isempty() == 1)
			break;
	}
}
void printstack(void);
int main()
{
	printf("inorder traversal = ");
	int temp[12]={8,12,10,7,32,16,14,11,4,6,1};
	for(int i=0;i<=11;i++)
		add_node(temp[i]);
	inorder();
	printf("\n");
}

