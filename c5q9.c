//student details
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
    int num;
    char name[15];
    int mark;
    struct node* link;
};
struct node* ptr;
struct node* header;
void insert_beg(int a,char b[],int c)
{
    struct node* t=(struct node*)malloc(sizeof(struct node));
    t->num=a;
    strcpy(t->name,b);
    t->mark=c;
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
void delete_pos(int key)
{
    int f=0;
    if(header->link!=NULL)
    {
        ptr=header->link;
        if(ptr->link!=NULL)
        {
            if(ptr->num==key)
            delete_beg();
            else
            {
                while(ptr->link!=NULL && (ptr->link)->num != key)
                {
                    ptr=ptr->link;
                }
                if(ptr->link==NULL)
                printf("\nSTUDENT NOT FOUND\n");
                else
                {
                    struct node* t=ptr->link;
                    ptr->link=t->link;
                    free(t);
                }
            }
        }
        else
        {
            if(ptr->num==key)
            {
                header->link=NULL;
                free(ptr);
            }
            else
            printf("\nSTUDENT NOT FOUND\n");
        }
    }
    else
    printf("list is empty\n");
}
void display()
{
    if(header->link!=NULL)
    {
        printf("\nSTUDENTS' DETAILS :\n\n");
        ptr=header->link;
        while(ptr!=NULL)
        {
            printf("NAME :%s\nNUMBER :%d\nTOTAL MARKS :%d\n\n",ptr->name,ptr->num,ptr->mark);
            ptr=ptr->link;
        }
        printf("\n\n");
    }
    else
    printf("LIST IS EMPTY\n");
}
void search()
{
    int a,c,r;
    char b[20];
    if(header->link!=NULL)
    {
        printf("1- SEARCH BY NAME\n2-SEARCH BY NUMBER\nENTER CHOICE : ");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
            printf("enter name : ");
            scanf("%s",b);
            ptr=header->link;
            if(ptr->link!=NULL)
            {
                r=strcmp(ptr->name,b);
                while(ptr->link!=NULL && r!=0)
                {
                    ptr=ptr->link;
                    r=strcmp(ptr->name,b);
                }
                if(r!=0)
                printf("\nSTUDENT NOT FOUND\n");
                else
                {
                    printf("\nSTUDENT DETAILS:\nNAME :%s\nNUMBER :%d\nTOTAL MARKS :%d\n\n",ptr->name,ptr->num,ptr->mark);
                }
            }
            else
            {
                r=strcmp(ptr->name,b);
                if(r==0)
                {
                    printf("\nSTUDENT DETAILS:\nNAME :%s\nNUMBER :%d\nTOTAL MARKS :%d\n\n",ptr->name,ptr->num,ptr->mark);
                }
                else
                printf("\nSTUDENT NOT FOUND\n");
            }
            break;
            case 2:
            printf("enter number : ");
            scanf("%d",&a);
            ptr=header->link;
            if(ptr->link!=NULL)
            {
                 if(ptr->num==a)
                 printf("\nSTUDENT DETAILS:\nNAME :%s\nNUMBER :%d\nTOTAL MARKS :%d\n\n",ptr->name,ptr->num,ptr->mark);
                 else
                 {
                    while(ptr->link!=NULL && (ptr->link)->num!=a)
                    {
                        ptr=ptr->link;
                    }
                    if(ptr->link==NULL)
                    printf("\nSTUDENT NOT FOUND\n");
                    else
                    {
                        ptr=ptr->link;
                        printf("\nSTUDENT DETAILS:\nNAME :%s\nNUMBER :%d\nTOTAL MARKS :%d\n\n",ptr->name,ptr->num,ptr->mark);
                    }
                 }
            }
            else
            {
                if(ptr->num==a)
                {
                    printf("\nSTUDENT DETAILS:\nNAME :%s\nNUMBER :%d\nTOTAL MARKS :%d\n\n",ptr->name,ptr->num,ptr->mark);
                }
                else
                printf("\nSTUDENT NOT FOUND\n");
            }
            break;
        }
    }
    else
    printf("\nLIST IS EMPTY\n");
}
void sort()
{
    int t1;
    char t2[20];
    if(header->link!=NULL)
    {
        ptr=header->link;
        struct node* t;
        if(ptr->link!=NULL)
        {
            if((ptr->link)->link==NULL)
            {
                t=ptr->link;
                if(ptr->num > t->num)
                    {
                        t1=ptr->num;
                        ptr->num=t->num;
                        t->num=t1;
                        strcpy(t2,ptr->name);
                        strcpy(ptr->name,t->name);
                        strcpy(t->name,t2);
                        t1=ptr->mark;
                        ptr->mark=t->mark;
                        t->mark=t1;
                    }
            }
            while(ptr->link!=NULL)
            {
                t=ptr->link;
                while(t!=NULL)
                {
                    if(ptr->num > t->num)
                    {
                        t1=ptr->num;
                        ptr->num=t->num;
                        t->num=t1;
                        strcpy(t2,ptr->name);
                        strcpy(ptr->name,t->name);
                        strcpy(t->name,t2);
                        t1=ptr->mark;
                        ptr->mark=t->mark;
                        t->mark=t1;
                    }
                    t=t->link;
                }
                ptr=ptr->link;
            }
        }
        printf("\nSORTED SUCCESSFULLY\n");
    }
}
int main()
{
    header=(struct node*)malloc(sizeof(struct node));
    header->link=NULL;
    int c,num,mark,key;
    char name[15];
    do
    {
        printf("\n1-insert student details \n2-delete student details based on number \n3-search student \n4-display \n5-sort \n6-exit \nENTER CHOICE : ");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
                    printf("Enter student name,number,and total marks in order:\n");
                    scanf("%s%d%d",name,&num,&mark);
                    insert_beg(num,name,mark);
                    break;
            case 2 :
                    printf("enter number of student whose details to be deleted : ");
                    scanf("%d",&key);
                    delete_pos(key);
                    display();
                    break;
            case 3:
                    search();
                    break;
            case 4:
                   display();
                   break;
            case 5:
                   sort();
                   break;
            case 6:
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
    }while(c!=6);
    return 0;
}
