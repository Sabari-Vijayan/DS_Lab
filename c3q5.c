#include <stdio.h>
int front=-1;
int rear=-1;
int size;
int CircQueue[20];

void display();

void enqueue(int item)
{
        if(front==((rear+1)%size))
        {
                printf("\n Queue Overflow\n");
        }
        else
        {
                rear=(rear+1)%size;
                CircQueue[rear]=item;
                if(front==-1)
                {
                        front++;
                }
                display();
        }
}

int dequeue()
{
        int item;
        if(front==-1)
        {
                printf("Queue Underflow\n");
        }
        else
        {
                item=CircQueue[front];
                front=(front+1)%size;
                if(front==((rear+1)%size))
                {
                        front=-1;
                        rear=-1;
                }
                display();
        }
        return item;
}
void display()
{
	if(front==-1)
	{
		printf("circular queue is empty\n");
	}
	else
	{
		puts("circular queue is :");
		if(rear<front)
		{
			for(int i=front;i<size;i++)
			{
				if(i==size-1){
				printf("%d ",CircQueue[i]);
				i=-1; }
				else if(i==rear){
				printf("%d ",CircQueue[i]);
 				break; }
				else{
				printf("%d ",CircQueue[i]); }
			}
		}
		else
		{
			for(int i=front;i<=rear;i++)
			{ printf("%d ",CircQueue[i]); }
		}
	}

}

int main()
{
        int item;
        int choice;
        printf("Enter Size of Queue: ");
        scanf("%d",&size);
        do
        {
                printf("\n\n\n1.Enqueue\n2.Dequeue\n3.Display Queue\n4.Exit\n\nEnter Choice: ");
                scanf("%d",&choice);
                switch(choice)
                {
                        case 1: printf("Enter Item: ");
                                scanf("%d",&item);
                                enqueue(item);
                                break;

                        case 2:dequeue();
                                break;

                        case 3:display();
                                break;

                        case 4:break;

                        default:printf("Invalid Choice!!");
                                break;
                }
        }while(choice!=4);

        return 0;
}

