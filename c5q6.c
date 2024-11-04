#include<stdio.h>
#include<stdlib.h>
struct node
{
    int c;
    int e;
    struct node* link;
};
struct node* ptr;
void sort(struct node* a)
{
    struct node* header=a;
    ptr=header->link;
    struct node* ptr2;
    if(ptr->link!=NULL && ptr->link->link!=NULL)
    {
        while(ptr!=NULL)
        {
            ptr2=ptr->link;
            while(ptr2!=NULL)
            {
                if(ptr->e<ptr2->e)
                {
                    int t1=ptr->e;
                    int t2=ptr->c;
                    ptr->e=ptr2->e;
                    ptr->c=ptr2->c;
                    ptr2->e=t1;
                    ptr2->c=t2;
                }
                ptr2=ptr2->link;
            }
            ptr=ptr->link;
        }
    }
}

void insert_beg(struct node* a,int b,int c)
{
    struct node* header=a;
    struct node* t=(struct node*)malloc(sizeof(struct node));
    t->c=b;
    t->e=c;
    if(header->link==NULL)
    {
        header->link=t;
        t->link=NULL;
    }
    else
    {
        t->link=header->link;
        header->link=t;
    }
}

void read(struct node* a)
{
    int i=1,n;
    int c,e;
    printf("enter no of terms : ");
    scanf("%d",&n);
    while(i<=n)
    {
        printf("\nenter coefficient and exponent of term %d : ",i);
        scanf("%d%d",&c,&e);
        insert_beg(a,c,e);
        i++;
    }
    sort(a);
}

void delete_beg(struct node* a)
{
    struct node* header=a;
    if(header->link!=NULL)
    {
        ptr=header->link;
        header->link=ptr->link;
        free(ptr);
    }
}
void add(struct node* a, struct node* b,struct node* c)
{
    ptr=a->link;
    struct node* ptr2;
    while(ptr!=NULL)
    {
        ptr2=b->link;
        while(ptr2!=NULL)
        {
            if(ptr->e==ptr2->e)
            {
                int s=ptr->c + ptr2->c;
                insert_beg(c,s,ptr->e);
                break;
            }
            ptr2=ptr2->link;
        }
        if(ptr2==NULL)
        {
            insert_beg(c,ptr->c,ptr->e);
        }
        ptr=ptr->link;
    }
    ptr=b->link;
    while(ptr!=NULL)
    {
	ptr2=c->link;
	while(ptr2!=NULL)
        {
		if(ptr->e==ptr2->e)
  	        break;
                ptr2=ptr2->link;
	}
	if(ptr2==NULL)
	{
		insert_beg(c,ptr->c,ptr->e);
	}
       ptr= ptr->link;
    }
    sort(c);
}
void display(struct node* a)
{
    struct node* header=a;
    if(header->link!=NULL)
    {
        printf("\n");
        ptr=header->link;
        while(ptr!=NULL)
        {
            if(ptr->c!=0)
            {
                if(ptr->e==0)
                printf("+[%d]",ptr->c);
                else
                printf("+[%d(X^%d)]",ptr->c,ptr->e);
            }
            ptr=ptr->link;
        }
        printf("\n\n");
    }
}
int main()
{
    struct node* header1;
    struct node* header2;
    struct node* sum;
    header1=(struct node*)malloc(sizeof(struct node));
    header1->link=NULL;
    header2=(struct node*)malloc(sizeof(struct node));
    header2->link=NULL;
    sum=(struct node*)malloc(sizeof(struct node));
    int c,item,key;
    printf("ENTER FIRST POLYNOMIAL\n");
    read(header1);
    printf("\nENTER SECOND POLYNOMIAL\n");
    read(header2);
    printf("FIRST POLYNOMIAL:\n");
    display(header1);
    printf("SECOND POLYNOMIAL:\n");
    display(header2);
    add(header1,header2,sum);
    printf("SUM IS :\n");
    display(sum);
    while(header1->link!=NULL)
    {
        delete_beg(header1);
    }
    free(header1);
    while(header2->link!=NULL)
    {
        delete_beg(header2);
    }
    free(header2);
    while(sum->link!=NULL)
    {
        delete_beg(sum);
    }
    free(sum);
    return 0;
}
