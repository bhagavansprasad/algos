#include<stdio.h>
#include<stdlib.h>
struct student
{
	int x;
	struct student * next;
};
struct student *h;
int create(int v)
{
	struct student *t, *p;
	t = h;
	p = malloc(sizeof(struct student));
	p->x = v;
	p->next = NULL;
	if(h==NULL)
	{
		h=p;
		return 0;
	}
	while(t->next!=NULL)
	{
		t = t->next;
	}
	t->next =p;
}

int update_by_pos(int v, int i)
{
	struct student *t=h;
	int u=0;
		while(u<i && t->next!=NULL)
		{
			t = t->next;
             u++;
		}
		//printf("%d\n", u);
	if(u == i)
	{
		t->x = v;
		return 0;
	}
	printf("the value is not updated\n");
	return -1;
}
int update_by_val(int v, int s)
{
	struct student *t = h;
	while(t->x != s && t->next!=NULL)
	{
		t = t->next;
	}
	if(t->x == s)
	{
		t->x = v;
		return 0;
	}
	printf("the value is not available\n");
	return -1;
}

int del_by_pos(int i)
{
	struct student *t = h;
	int z = 0;
	while(z!=i-1 && t->next!=NULL)
	{
		t = t->next;
		z++;
	}
    if(t->next == NULL)
	{
	printf("the position is not available\n");
	return -1;
    }

    else if(i == 0)
	{
		struct student *c = h;
		h = h->next;
		free(c);
	}
	
	else if(t->next->next == NULL)
	{
		t->next=NULL;
		return 0;
	}

    	else if(z == i)
	{
		struct student *c = t->next;
		t->next = t->next->next;
		free(c);
		return 0;
	}
  
	else if(t->next == NULL)
	{
	printf("the position is not available\n");
	return -1;
    }
	
 }
int del_by_val(int v)
{
	struct student *t = h;
	if(t->x == v)
	{
		struct student *c = t->next;
		h = t->next;
		free(c);
		return 0;
	}
	while(t->next->x!=v && t->next->next!=NULL)
	{
		 if(t->next->x == v){
			 struct student *c = t->next;
			 t->next = t->next->next;
			 free(c);
			 return 0;
		 }
		 t = t->next;
	}

	if(t->next->next == NULL && t->next->x == v)
	{
		t->next = NULL;
		return 0;
	}
	printf("there is no such value");
	return -1;
}
void dumplist()
{
	struct student *t = h;
	while(t->next != NULL)
	{
		printf("%d\n", t->x);
		t=t->next;
	}
	printf("%d\n", t->x);
}


int main()
{
	create(2);
	create(33);
	create(44);
	create(54);
	create(62);
	create(73);
	create(84);
	create(95);
	dumplist();
	update_by_pos(43, 2);
	update_by_val(75,73);
	del_by_pos(7);
	del_by_val(84);
	printf("after operations\n");
	dumplist();
	return 0;
}







