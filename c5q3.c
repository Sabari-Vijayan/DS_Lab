#include<stdio.h>
#include<stdlib.h>
struct node
{
    int d;
    struct node* link;
};
struct node* top;
struct node* header;
int flag;
void push(int a)
{
    struct node* t=(struct node*)malloc(sizeof(struct node));
    if(t!=NULL)
    {
        t->d=a;
        t->link=top;
        top=t;
        header->link=top;
    }
    else
    printf("\nMEMORY FULL\n");
}
int pop()
{
    flag=0;
    int item;
    if(top!=NULL)
    {
        flag=1;
        struct node* t=top;
        item=t->d;
        top=t->link;
        header->link=top;
        free(t);
    }
    else
    printf("\nSTACK UNDERFLOW\n");
    return item;
}
void peek()
{
    if(top!=NULL)
    {
        printf("\nITEM AT TOP IS : %d\n",top->d);
    }
    else
    printf("\nSTACK IS EMPTY\n");
}
int main()
{
    header=(struct node*)malloc(sizeof(struct node));
    header->link=NULL;
    top=header->link;
    int c,item;
    do
    {
        printf("1-push 2-pop 3-peek 4-exit\nENTER CHOICE : ");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
                    printf("enter item to be inserted: ");
                    scanf("%d",&item);
                    push(item);
                    peek();
                    break;
            case 2 :
                    item=pop();
                    if(flag==1)
                    printf("\npoped item is %d\n",item);
                    peek();
                    break;
            case 3 :peek();
                    break;
            case 4:
                    while(top!=NULL)
                    {
                        pop();
                    }
                    free(header);
                    break;
            default :
                    printf ("invalid choice\n");
                    break;
        }
    }while(c!=4);
    return 0;
}
