#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"
struct node 
{
	char name[100];
	struct node *next;
};
struct node *h[26]={NULL};
int get_hashkey(char *word)
{
    char f= tolower(word[0]);
    return f - 'a';
}

int add_node(char *p)
{
	struct node *new=malloc(sizeof(struct node));
	struct node *t;
	int i=get_hashkey(p);
	strcpy(new->name,p);
	new->next=NULL;
	if(h[i]==NULL)
	{
		h[i]=new;
		return -1;
	}
	t=h[i];
	while(t->next!=NULL)
		t=t->next;
	t->next=new;
}
void dump_list(void)
{
	struct node *t=h[0];
	int i=0;
	int n=25;
	for(i=0;i<=n;i++)
	{
		if(h[i]!=NULL)
		{
			for(t=h[i];t!=NULL;t=t->next)
				printf("%5s , ",t->name);
			printf("\n");
		}	
	}	
}
int del(char *ov)
{
	struct node *t;
	struct node *s;
	int i=get_hashkey(ov);
	int j,temp;
	t=h[i];
	if(h[i]==NULL)
		return -1;
	if(strcmp(ov,h[i]->name)==0)
	{
		t = h[i];
		h[i] = h[i]->next;
		free(t);
		return 0;
	}
	if(j==0)
	{
		free(h[i]->next);
		h[i]=h[i]->next;
	}
	for(t=h[i];strcmp(t->next->name,ov)!=0 && t->next!=NULL; t=t->next);
	if(t->next==NULL)
		return -1;
	s = t->next;
	t->next = t->next->next;
	free(s);
	return 0;
}
int main()
{
	char name[100]="saketh";
	char name3[100]="sakeath";
	char name2[100]="IKSHwAK";
    add_node(name);
    add_node(name3);
    add_node(name2);
	dump_list();
	del(name);
	dump_list();
	return 0;
}
