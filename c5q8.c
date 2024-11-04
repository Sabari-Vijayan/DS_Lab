//POLYNOMIAL LL sum2
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int c;
    int e1;
    int e2;
    struct node* link;
};
struct node* ptr;
void sort(struct node* a)
{
    int t1,t2,t3;
    struct node* header=a;
    ptr=header->link;
    while(ptr!=NULL)
    {
        if(ptr->c ==0)
        {
            ptr->e1=0;
            ptr->e2=0;
        }
        ptr=ptr->link;
    }
    ptr=header->link;
    struct node* ptr2;
    if(ptr->link!=NULL && ptr->link->link!=NULL)
    {
        while(ptr!=NULL)
        {
            ptr2=ptr->link;
            while(ptr2!=NULL)
            {
                if(ptr->e1<ptr2->e1)
                {
                    t1=ptr->c;
                    t2=ptr->e1;
                    t3=ptr->e2;
                    ptr->c=ptr2->c;
                    ptr->e1=ptr2->e1;
                    ptr->e2=ptr2->e2;
                    ptr2->c=t1;
                    ptr2->e1=t2;
                    ptr2->e2=t3;
                }
                ptr2=ptr2->link;
            }
            ptr=ptr->link;
        }
        ptr=header->link;
        while(ptr->link!=NULL)
        {
            if(ptr->e1==(ptr->link)->e1)
            {
                if(ptr->e2 < (ptr->link)->e2)
                {
                    t1=ptr->c;
                    t2=ptr->e2;
                    ptr->c=(ptr->link)->c;
                    ptr->e2=(ptr->link)->e2;
                    (ptr->link)->c=t1;
                    (ptr->link)->e2=t2;
                }
            }
            ptr=ptr->link;
        }
    }
}

void insert_beg(struct node* a,int b,int c,int d)
{
    struct node* header=a;
    struct node* t=(struct node*)malloc(sizeof(struct node));
    t->c=b;
    t->e1=c;
    t->e2=d;
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
    int c,e1,e2;
    printf("enter no of terms : ");
    scanf("%d",&n);
    while(i<=n)
    {
        printf("\nenter coefficient and exponents of variable X and Y of term %d : ",i);
        scanf("%d%d%d",&c,&e1,&e2);
        insert_beg(a,c,e1,e2);
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
            if(ptr->e1==ptr2->e1 && ptr->e2==ptr2->e2)
            {
                int s=ptr->c + ptr2->c;
                insert_beg(c,s,ptr->e1,ptr->e2);
                break;
            }
            ptr2=ptr2->link;
        }
        if(ptr2==NULL)
        {
            insert_beg(c,ptr->c,ptr->e1,ptr->e2);
        }
        ptr=ptr->link;
    }
    ptr=b->link;
    while(ptr!=NULL)
    {
        ptr2=c->link;
        while(ptr2!=NULL)
        {
            if(ptr->e1==ptr2->e1 && ptr->e2==ptr2->e2)
            {
                break;
            }
            ptr2=ptr2->link;
        }
        if(ptr2==NULL)
        {
            insert_beg(c,ptr->c,ptr->e1,ptr->e2);
        }
        ptr=ptr->link;
    }
    sort(c);
}
void display(struct node* a)
{
    struct node* header=a;
    if(header->link!=NULL)
    {
        ptr=header->link;
        while(ptr!=NULL)
        {
            if(ptr->c!=0)
            {
                if(ptr->e1==0 && ptr->e2==0)
                printf("+[%d]",ptr->c);
                else if(ptr->e1==0 && ptr->e2!=0)
                printf("+[%d(Y^%d)]",ptr->c,ptr->e2);
                else if(ptr->e1!=0 && ptr->e2==0)
                printf("+[%d(X^%d)]",ptr->c,ptr->e1);
                else
                printf("+[%d(X^%d)(Y^%d)]",ptr->c,ptr->e1,ptr->e2);
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
    printf("\nFIRST POLYNOMIAL:\n");
    display(header1);
    printf("\nSECOND POLYNOMIAL:\n");
    display(header2);
    add(header1,header2,sum);
    printf("\nSUM IS :\n");
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
