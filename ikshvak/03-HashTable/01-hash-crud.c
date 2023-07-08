#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
	char name[100];
	struct node *next;
};

struct node *h[26] = {NULL};

int get_key(char *p)
{
	int hkey = 0;

	hkey = p[0]-65;
	printf("hkey :%d\n", hkey);

	return hkey;
}

int add_node(char *c)
{
	struct node *t, *p;
	int hkey;

	p = malloc(sizeof(struct node));
	strcpy(p->name, c);
	p->next = NULL;

	hkey = get_key(p->name);
	t = h[hkey];
	if (h[hkey] == NULL)
	{
		h[hkey] = p;
		return 0;
	}

	while(t->next != NULL)
	{
		t = t->next;
	}

	t->next = p;
	return 0;
}
int del_node(char *c)
{
	struct node *t;
	int l = get_key(c);
	//printf("%d\n", l);
	t = h[l];
	printf("I am here\n");
	if(h[l] == NULL)
	{
		printf("the name does not exist to delete\n");
		return -1;
	}

	if(strcmp(c, h[l]->name) == 0)
	{
		printf("I am here1st\n");
		t = h[l];
		h[l] = h[l]->next;
		free(t);
		return 0;
	}
	while(strcmp(t->next->name, c )!=0 && t->next != NULL)
	{
		t = t->next;
	}
	if(t->next==NULL)
	{
		printf("the name u want to delete doesnt exist\n");
		return -1;
	}
	else 
	{
		struct node *f = t->next;
		t->next = t->next->next;
		free(f);
		return 0;
	}
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
};

int main()
{
	int dlen = sizeof(names)/sizeof(names[0]);
	int i = 0;
	printf("dlen :%d\n", dlen);
	for (i = 0; i < dlen; i++)
	{
		add_node(names[i]);
		if(i >= 4)
		{
			break;
		}
		//dump_list();
		//del_node(names[3]);
	}
	del_node(names[3]);
	dump_list();
	return 0;
}





