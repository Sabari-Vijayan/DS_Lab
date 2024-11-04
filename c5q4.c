#include<stdio.h>
#include<stdlib.h>
struct node
{
    int d;
    struct node* link;
};
struct node* front;
struct node* rear;
int flag;
void enqueue(int a)
{
    struct node* t=(struct node*)malloc(sizeof(struct node));
    if(t!=NULL)
    {
        t->d=a;
        t->link=NULL;
        if(rear!=NULL)
        {
            rear->link=t;
            rear=t;
        }
        else
        {
            rear=t;
            front=rear;
        }
    }
    else
    printf("\nMEMORY FULL\n");
}
int dequeue()
{
    flag=0;
    int item;
    if(rear!=NULL)
    {
        flag=1;
        struct node* t=front;
        front=front->link;
        item=t->d;
        free(t);
        if(front==NULL)
        rear=NULL;
    }
    else
    printf("\nQUEUE UNDERFLOW\n");
    return item;
}
void display()
{
    if(rear!=NULL)
    {
        printf("\nQUEUE : ");
        struct node* ptr=front;
        while(ptr!=NULL)
        {
            printf("%d ",ptr->d);
            ptr=ptr->link;
        }
        printf("\n\n");
    }
    else
    printf("\nQUEUE IS EMPTY\n");
}
int main()
{
    front=NULL;
    rear=NULL;
    int c,item;
    do
    {
        printf("1-enqueue 2-dequeue 3-display 4-exit\nENTER CHOICE : ");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
                    printf("enter item to be inserted: ");
                    scanf("%d",&item);
                    enqueue(item);
                    display();
                    break;
            case 2 :
                    item=dequeue();
                    if(flag==1)
                    printf("\n dequeued item is %d\n",item);
                    display();
                    break;
            case 3 :
                    display();
                    break;
            case 4:
                    while(rear!=NULL)
                    {
                        dequeue();
                    }
                    break;
            default :
                    printf ("invalid choice\n");
                    break;
        }
    }while(c!=4);
    return 0;
}
