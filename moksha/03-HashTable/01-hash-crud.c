#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node 
{
	char name[100];
	struct node* next;
};
struct node* h[100] = {NULL};

int get_key(char* p) 
{
	int key = p[0] - 65;
	return key;
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
		int length, i;
		struct node* t = NULL;
		length = sizeof(h) / sizeof(h[0]);
		for (i = 0; i < length; i++) 
		{
			for (t = h[i]; t != NULL; t = t->next) 
			{
				printf("%s\n", t->name);
			}
		}
	}
	int main() 
	{
		char name[100] = "Moksha";
		add_node(name);
		char p[100] = "Yagna";
		add_node(p);
		char s[100] = "Affifa";
		add_node(s);
		char u[100] = "Ammu";
		add_node(u);
		char v[100] = "Yagna";
		delete_node(v);
		char w[100] = "Ammu";
		char b[100] = "Amrutha";
		update_node(w, b); 
		dump_list();
		return 0;
	}
