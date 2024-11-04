//POLYNOMIAL product
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
void product(struct node* a, struct node* b,struct node* c)
{
    ptr=a->link;
    struct node* ptr2;
    struct node* ptr3;
    int cf,ex;
    while(ptr!=NULL)
    {
        ptr2=b->link;
        while(ptr2!=NULL)
        {
            cf=ptr->c * ptr2->c;
            ex=ptr->e + ptr2->e;
            ptr3=c->link;
            while(ptr3!=NULL)
            {
                if(ex==ptr3->e)
                {
                    ptr3->c+=cf;
                    break;
                }
                ptr3=ptr3->link;
            }
            if(ptr3==NULL)
            {
                insert_beg(c,cf,ex);
            }
            ptr2=ptr2->link;
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
    struct node* res;
    header1=(struct node*)malloc(sizeof(struct node));
    header1->link=NULL;
    header2=(struct node*)malloc(sizeof(struct node));
    header2->link=NULL;
    res=(struct node*)malloc(sizeof(struct node));
    int c,item,key;
    printf("ENTER FIRST POLYNOMIAL\n");
    read(header1);
    printf("\nENTER SECOND POLYNOMIAL\n");
    read(header2);
    printf("FIRST POLYNOMIAL:\n");
    display(header1);
    printf("SECOND POLYNOMIAL:\n");
    display(header2);
    product(header1,header2,res);
    printf("PRODUCT IS :\n");
    display(res);
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
    while(res->link!=NULL)
    {
        delete_beg(res);
    }
    free(res);
    return 0;
}
