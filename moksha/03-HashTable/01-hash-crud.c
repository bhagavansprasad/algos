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

	return hkey;
}
int add_node(char* c) 
{
	struct node* new = NULL;
	struct node* t = NULL;
	int key = get_key(c);
	new = (struct node*)malloc(sizeof(struct node));
	strcpy(new->name, c);
	new->next = NULL;
	if (h[key] == NULL) 
	{
		h[key] = new;
		return 0;
	}
	for (t = h[key]; t->next != NULL; t = t->next) 
	{
	}
	t->next = new;
	return 0;
}
int delete_node(char* n) 
{
	struct node* p = NULL;
	struct node* c = NULL;
	int key = get_key(n);
	p = c = h[key];
	if (h[key] == NULL) 
	{
		return 1;
	}
	if (strcmp(h[key]->name, n) == 0) 
	{
		h[key] = h[key]->next;
		free(c);
		return 0;
	}
	for (c = h[key]->next; c != NULL; p = c, c = c->next) 
	{
		if (strcmp(c->name, n) == 0) 
		{
			break;
		}
	}
	if (c == NULL) 
	{
		return 1;
	}
	p->next = c->next;
	free(c);
	return 0;
}
int update_node(char* x, char* a) 
{
	struct node* t = NULL;
	int length = sizeof(h) / sizeof(h[0]);
	int i;
	for(i = 0; i<length;i++)
	{
		for (t = h[i]; t != NULL; t = t->next) 
		{
			if(strcmp(t->name, x)== 0) 
			{
				strcpy(t->name, a);
				break;
			}
		}

		if (t != NULL) 
		{
			printf("%s\n", t->name);
		}
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
	"Moksha",
	"Yagna",
	"Affifa",
	"Ammu",
	"Yagna",
	"Ammu",
	"Amrutha"
};

int main()
{
	int dlen = sizeof(names)/sizeof(names[0]);
	int i = 0;
	printf("dlen :%d\n", dlen);
	for (i = 0; i < dlen; i++)
	{
		add_node(names[i]);
		//if(i >= 4)
		if(0)
		{
			break;
		}
		//dump_list();
		//del_node(names[3]);
	}
	delete_node(names[3]);
	dump_list();
	return 0;
}

