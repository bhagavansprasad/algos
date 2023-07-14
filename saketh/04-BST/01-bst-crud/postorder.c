#include "stdio.h"
#include "stdlib.h"
#define max 15
struct node 
{
	struct node *left;
	struct node *right;
	int value;
};
struct node* stack1[max];
struct node* stack2[max];
struct node *H = NULL;
int needle1 = -1;
int needle2 = -1;
int isempty1(void) 
{
    if (needle1 == -1) 
        return 1; 
	return 0; 
}
int push1(struct node *p)
{
	needle1++;
	stack1[needle1]=p;
	return 1;
}
int push2(struct node *p)
{
	needle2++;
	stack2[needle2]=p;
	return 1;
}
struct node* pop1(void)
{
	struct node *node;
	if(needle1 < 0)
	{
		printf("  \n stack1 is empty \n");
		return NULL;
	}	
	node = stack1[needle1];
	needle1--;
	return node;
}
struct node* pop2(void)
{
	struct node *node;
	if(needle2 < 0)
		return NULL;
	node = stack2[needle2];
	needle2--;
	return node;
}

void printstack2(void)
{
	int i=0;
	struct node *p=NULL;
	while(1)
	{
		p=pop2();
		if(p == NULL)
			break;
		printf("%d ,", p->value);
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
void postrder(void)
{
	struct node *c=NULL, *p;
	c = H;
	if(c!=NULL)
		push1(c);

	while(isempty1()==0)
	{
			p = pop1();
			push2(p);
			if(p->left)
				push1(p->left);
			if(p->right)
				push1(p->right);
	}
	printstack2();
}
void printstack2(void);
int main()
{
	printf("\n");
	printf("postorder traversal = ");
	int temp[12]={8,12,10,7,32,16,14,11,4,6,1};
	for(int i=0;i<=11;i++)
		add_node(temp[i]);
	postrder();
	printf("\n");
}

