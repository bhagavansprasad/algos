#include <stdio.h>
#include <stdlib.h>
struct student 
{
	int no;
	struct student* pnext;
};
struct student* H = NULL;

int ordered_insertion(int n)
{
	struct student* new = NULL;
	struct student* t = H;
	

	new = (struct student*)malloc(sizeof(struct student));
	new->no = n;
	new->pnext = NULL;
	if(H ==	NULL || H->no >= n)
	{
		new->pnext = H;
		H = new;
		return 0;
		printf("%d\n",new->no);
	}
	while(t->pnext != NULL)
	{
		if(t->pnext->no >= n)
		{
			new->pnext = t->pnext;
			t ->pnext = new;
			return 0;
			//printf("%d\n",t->no);
		}
		else{
			t = t->pnext;
		}

	}
	t->pnext = new;


}
void dump_list()
{
	struct student *t = H;
	while(t->pnext != NULL)
	{
		printf("%d\n", t->no);
		t = t->pnext;
	}
		printf("%d\n", t->no);

}

int main() 
{
	ordered_insertion(3);
	ordered_insertion(1);
	ordered_insertion(4);
	ordered_insertion(2);
	ordered_insertion(5);
	dump_list();
     return 0;
}
