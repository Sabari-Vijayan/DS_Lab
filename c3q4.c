#include<stdio.h>
int front = -1;
int rear = -1;
int size,flag=0;
int q[15];
void  display()
{
 if( front ==-1)
 {
	printf("queue is empty\n");
 }
 else
 {
	int i;
	printf("\nqueue : ");
	for(i=front;i<=rear;i++)
	{
		printf("%d ",q[i]);
	}
	printf("\n");
 }
}

void enqueue(int item)
{
 if(rear==size-1)
 {
  printf("queue overflow\n");
  display();
 }
 else
 {
  rear++;
  q[rear]=item;
  if(rear==0)
  { front++; }
   display();
 }
}

int dequeue()
{
//	flag=0;
	int item;
	if(front==-1)
	{
	flag=2;
	printf("queue underflow\n");
	}
	else
	{
 	 item=q[front];
	 front++;
	 display();
	 if(front>rear)
	  {
		front =-1;
		rear=-1;
	  }
	return item;
	}

}

int main(){
 int item;
 int c;
 printf("enter size of queue\n");
 scanf("%d",&size);
 do
 {
  printf("1-enqueue\t2-dequeue\t3-display queue\t4.exit\nenter choice\n");
  scanf("%d",&c);
  switch(c)
  {
	case 1: printf("enter item\n");
	scanf("%d",&item);
	enqueue(item);
	break;
	case 2:int ret=dequeue();
	if(flag!=2)
	printf("item is %d\n",ret);
	break;
	case 3: display();
	break;
	case 4: break;
 }
}while(c!=4);
return 0;
}
