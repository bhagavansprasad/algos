#include <stdio.h>
#include <stdlib.h>
  struct student
{
	int no;
	struct student *pnext;
};
struct student *H = NULL;
int add_node(int n)
{
	struct student *new = NULL;
	struct student *t = NULL;
	new = (struct student*) malloc(sizeof(struct student));
	new->no = n;
	new->pnext = NULL;
	if (H == NULL)
	{
		H = new;
		return 0;
	}
	for(t=H; t->pnext != NULL; t=t->pnext);
	t->pnext = new;
	return 0;
}
int update_node(int x)
{
	struct student *t = NULL;
	int a = 15;
    for(t = H; t != NULL; t = t->pnext)
    {
		if(t->no == x)
			t->no = a;
		break;
    }
		printf("%d\n", t->no);
}

int dump_list(void)
{
    struct student *t = NULL;    
    for(t = H; t != NULL; t = t->pnext)
    {
        printf("%d\n", t->no);
    }
}
int main()
{
	add_node(10);
	add_node(20);
	add_node(30);
	add_node(40);
	dump_list();
	update_node(20);
	return 0;
}


