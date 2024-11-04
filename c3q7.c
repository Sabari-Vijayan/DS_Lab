#include<stdio.h>
int dq[50];
int f=-1,r=-1,size,flag=0,item;
void display()
{
	if(f==-1)
	printf("Queue is empty\n");
	else
	{
		printf("Double ended queue is\n");
		for(int i=f;i<=r;i++)
		printf("%d ",dq[i]);
	}
	printf("\n");
}
void enqueueR(int item)
{
	if(r==size-1)
	printf("rear end is full\n");
	else
	{
		r++;
		dq[r]=item;
		if(f==-1)
		f++;
	}
}

void enqueueF(int item)
{
	if(f==0)
	printf("front end is full\n");
	else if(f==-1)
	{
		f++;
		r++;
		dq[f]=item;
	}
	else
	{
		f--;
		dq[f]=item;
	}
}

int dequeueF()
{
	flag=0;
	if(f==-1){
	flag=2;
	printf("Queue underflow\n");}
	else
	{
		item=dq[f];
		f++;
		if(f>r)
		{
		f=-1;
		r=-1;
		}
		return item;
	}
}

int dequeueR()
{
	flag=0;
	if(r==-1){
	flag=2;
	printf("Queue underflow\n");}
	else
	{
		item=dq[r];
		r--;
		if(f>r)
		{
			f=-1;
			r=-1;
		}
		return item;
	}
}


int main()
{
        int item,res;
        int choice;
        printf("Enter Size of Queue: ");
        scanf("%d",&size);
        do
        {
                printf("\n1.Enqueue Front\n2.Enqueue Rear\n3.Dequeue Front\n4.Dequeue Rear\n5.Display Queue\n6.Exit\n\nEnter Choice: ");
                scanf("%d",&choice);
                switch(choice)
                {
                        case 1: printf("Enter Item: ");
                                scanf("%d",&item);
                                enqueueF(item);
				display();
                                break;

                        case 2: printf("Enter Item: ");
                                scanf("%d",&item);
				enqueueR(item);
				display();
                                break;

                        case 3: res=dequeueF();
				if(flag!=2)
				{
				printf("item is %d\n",res);
				display();
				}
                                break;

                        case 4: res=dequeueR();
				if(flag!=2)
				{
                                printf("item is %d\n",res);
				display();
				}
				break;

                        case 5:display();
                                break;
			case 6: break;
                }
        }while(choice!=6);

        return 0;
}

