//DLL
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    struct node* Rlink;
    char d;
    struct node* Llink;
};
struct node* ptr;
struct node* header;
void insert_end(char a)
{
    struct node* t=(struct node*)malloc(sizeof(struct node));
    t->Rlink=NULL;
    t->d=a;
    if(header->Rlink!=NULL)
    {
        ptr=header->Rlink;
        while(ptr->Rlink!=NULL)
        {
            ptr=ptr->Rlink;
        }
        ptr->Rlink=t;
        t->Llink=ptr;
    }
    else
    {
        header->Rlink=t;
        t->Llink=header;
    }
}
void insert_beg(char a)
{
    struct node* t=(struct node*)malloc(sizeof(struct node));
    t->d=a;
    if(header->Rlink==NULL)
    {
        header->Rlink=t;
        t->Rlink=NULL;
        t->Llink=header;
    }
    else
    {
        t->Rlink=header->Rlink;
        header->Rlink=t;
        t->Llink=header;
    }
}
char delete_beg()
{
    char c;
    if(header->Rlink!=NULL)
    {
        ptr=header->Rlink;
        header->Rlink=ptr->Rlink;
        if(ptr->Rlink!=NULL)
        (ptr->Rlink)->Llink=header;
        c=ptr->d;
        free(ptr);
    }
    else
    printf("list is empty\n");
    return c;
}
char delete_end()
{
    char c;
    if(header->Rlink!=NULL)
    {
        ptr=header->Rlink;
        if(ptr->Rlink!=NULL)
        {
            while((ptr->Rlink)->Rlink!=NULL)
            {
                ptr=ptr->Rlink;
            }
             struct node* t=ptr->Rlink;
             ptr->Rlink=NULL;
             c=t->d;
             free(t);
        }
        else
        {
            delete_beg();
        }
    }
    else
    printf("list is empty\n");
    return c;
}
void display()
{
    if(header->Rlink!=NULL)
    {
        printf("\nLIST : ");
        ptr=header->Rlink;
        while(ptr!=NULL)
        {
            printf("%c ",ptr->d);
            ptr=ptr->Rlink;
        }
        printf("\n\n");
    }
    else
    printf("LIST IS EMPTY\n");
}
int main()
{
    header=(struct node*)malloc(sizeof(struct node));
    header->Rlink=NULL;
    header->Llink=NULL;
    int n,i=0,flag=0;
    char s[50],a,b;
    printf("enter a string:\n");
    scanf("%s",s);
    n=strlen(s);
    while(i<n)
    {
       insert_end(s[i]);
       i++;
    }
    display();
    i=1;
    while(i<=(n/2))
    {
        a=delete_beg();
        b=delete_end();
        if(a!=b)
        {
            flag=1;
            break;
        }
        i++;
    }
    if(header->Rlink!=NULL)
    free(header->Rlink);
    free(header);
    if(flag==0)
    printf("palindrome \n");
    else
    printf("not palindrome \n");
    return 0;
}
