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
	char f = tolower(word[0]);
	return f - 'a';
}

int add_node(char *p)
{
	struct node *new=malloc(sizeof(struct node));
	struct node *t;
	int i = get_hashkey(p);
	strcpy(new->name, p);
	new->next=NULL;
	if(h[i] == NULL)
	{
		h[i]=new;
		return -1;
	}
	t=h[i];
	while(t->next!=NULL)
		t=t->next;
	t->next=new;
}



int delete_node(char *ov)
{
	struct node *t;
	struct node *s;
	int i=get_hashkey(ov);
	int j,temp;
	t=h[i];
	if(h[i]==NULL)
		return -1;
	if(strcmp(ov, h[i]->name)==0)
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
	for(t=h[i];strcmp(t->next->name,ov)!= 0 && t->next!=NULL; t=t->next);
	if(t->next==NULL)
		return -1;
	s = t->next;
	t->next = t->next->next;
	free(s);
	return 0;
}

void dump_list()
{
	int size, i;
	struct node *t;
	size = sizeof(h)/sizeof(h[0]);
	for(i=0; i < size; i++)
	{
		printf("%4d:%3c: ", i, 'A'+i);
		t = h[i];
		while( t != NULL)
		{
			printf("%-15s", t->name);
			t = t->next;
		}
		printf("\n");
	}
}

char names[][100] = {
	"Saketh", 
	"Ikshwak", 
	"Yoga", 
	"Samhitha",
	"Ilindar", 
	"saketh",
	"sakeath",
	"IKSHwAK"
};

int main()
{
	int dlen = sizeof(names)/sizeof(names[0]);
	int i = 0;
	printf("dlen :%d\n", dlen);
	for (i = 0; i < dlen; i++)
	{
		add_node(names[i]);
		if(0)
		{
			break;
		}
	}
	delete_node(names[3]);
	delete_node(names[2]);
	dump_list();
	return 0;
}


