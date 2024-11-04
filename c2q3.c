#include<stdio.h>
int st[50],flag=0,size,top=-1,item;
void push(int item)
{
	if(top==size-1)
	printf("stack overflow\n");
	else
	{
		top++;
		st[top]=item;
	}
}

int pop()
{
	if(top==-1)
	{
	  flag=-1;
	  printf("stack underflow\n");
	}
	else
	{
		item=st[top];
		top--;
		return item;
	}
}
int peek()
{
	flag=0;
	if(top==-1)
	{
	flag=-1;
	printf("stack is empty\n"); }
	else
	return st[top];
}
int main(){
int c;
printf("enter size of stack\n");
scanf("%d",&size);
do
{
 printf("1.push\n2.pop\n3.peek\n4.exit\nenter choice : ");
 scanf("%d",&c);
 switch(c)
   {
	case 1: printf("enter item\n");
	scanf("%d",&item);
	push(item);
	break;
	case 2: int ret=pop();
	if(flag!=-1)
	printf("item is %d\n",ret);
	break;
	case 3 :peek();
	if(flag!=-1)
        printf("item at top is %d\n",peek());
        break;
	case 4: break;
	default:printf("INVALID CHOICE\n");
	break;

   }
}while(c!=4);
}
