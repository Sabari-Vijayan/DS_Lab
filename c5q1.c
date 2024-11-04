#include<stdio.h>
#include<stdlib.h>
struct node
{
    int d;
    struct node* link;
};
struct node* ptr;
struct node* header;
void insert_end(int a)
{
    struct node* t=(struct node*)malloc(sizeof(struct node));
    t->link=NULL;
    t->d=a;
    if(header->link!=NULL)
    {
        ptr=header->link;
        while(ptr->link!=NULL)
        {
            ptr=ptr->link;
        }
        ptr->link=t;
    }
    else
    {
        header->link=t;
    }
}
void insert_beg(int a)
{
    struct node* t=(struct node*)malloc(sizeof(struct node));
    t->d=a;
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
void insert_pos(int key,int a)
{
    if(header->link!=NULL)
    {
        struct node* t=(struct node*)malloc(sizeof(struct node));
        t->d=a;
        ptr=header->link;
        while(ptr!=NULL && ptr->d!=key)
        {
            ptr=ptr->link;
        }
        if(ptr!=NULL)
        {
            t->link=ptr->link;
            ptr->link=t;
        }
        else
        {
            printf("key not found in list\n");
            free(t);
        }
    }
    else
    printf("key not found\n");
}
void delete_beg()
{
    if(header->link!=NULL)
    {
        ptr=header->link;
        header->link=ptr->link;
        free(ptr);
    }
    else
    printf("list is empty\n");
}
void delete_end()
{
    if(header->link!=NULL)
    {
        ptr=header->link;
        if(ptr->link!=NULL)
        {
            while((ptr->link)->link!=NULL)
            {
                ptr=ptr->link;
            }
             struct node* t=ptr->link;
             ptr->link=NULL;
             free(t);
        }
        else
        {
            delete_beg();
        }
    }
    else
    printf("list is empty\n");
}
void delete_pos(int key)
{
    if(header->link!=NULL)
    {
        ptr=header->link;
        if(ptr->link!=NULL)
        {
            while(ptr->link!=NULL && (ptr->link)->d !=key)
            {
                ptr=ptr->link;
            }
            if(ptr->link==NULL)
            printf("element not found\n");
            else
            {
                struct node* t=ptr->link;
                ptr->link=t->link;
                free(t);
            }
        }
        else
        {
            if(ptr->d==key)
            {
                header->link=NULL;
                free(ptr);
            }
            else
            printf("key not found\n");
        }
    }
    else
    printf("list is empty\n");
}
void display()
{
    if(header->link!=NULL)
    {
        printf("\nLIST : ");
        ptr=header->link;
        while(ptr!=NULL)
        {
            printf("%d ",ptr->d);
            ptr=ptr->link;
        }
        printf("\n\n");
    }
    else
    printf("LIST IS EMPTY\n");
}
int main()
{
    header=(struct node*)malloc(sizeof(struct node));
    header->link=NULL;
    int c,item,key;
    do
    {
        printf("1-insert at beginning 2-insert at end 3-insert at specific position\n4-delete at beginning 5-delete at end 6-delete at specific position\n7-display 8-exit\nENTER CHOICE : ");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
                    printf("enter item to be inserted: ");
                    scanf("%d",&item);
                    insert_beg(item);
                    display();
                    break;
            case 2 :
                    printf("enter item to be inserted: ");
                    scanf("%d",&item);
                    insert_end(item);
                    display();
                    break;
            case 3 :
                    printf("enter item to be inserted: ");
                    scanf("%d",&item);
                    printf("enter data item after which item to be inserted : ");
                    scanf("%d",&key);
                    insert_pos(key,item);
                    display();
                    break;
            case 4 :
                    delete_beg();
                    display();
                    break;
            case 5:
                    delete_end();
                    display();
                    break;
            case 6:
                    printf("enter element to be deleted : ");
                    scanf("%d",&key);
                    delete_pos(key);
                    display();
                    break;
            case 7:
                    display();
                    break;
            case 8:
                    while(header->link!=NULL)
                    {
                        delete_beg();
                    }
                    free(header);
                    break;
            default :
                    printf ("invalid choice\n");
                    break;
        }
    }while(c!=8);
    return 0;
}
