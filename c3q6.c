#include<stdio.h>
#include<string.h>
#define MAXP 5
int pq[MAXP][50];
int r[50];
int f[50];
int i,size,p,flag=0,item;
void display()
{
	p=0;
	printf("priority queue is:\n");
	while(p<MAXP)
	{
		if(f[p]==-1) {
		p=p+1; }
		else
		{
			printf("priority %d : ",p);
			for(i=f[p];i<=r[p];i++)
			{
			printf("%d ",pq[p][i]);
			}
			printf("\n");
			p++;
		}
	}
}

void enqueue(int item)
{
	printf("enter priority\n");
	scanf("%d",&p);
	if(r[p]==size-1){
	printf("queue at priority level is full\n"); }
	else
	{
		r[p]=r[p]+1;
		pq[p][r[p]]=item;
		if(r[p]==0){
		f[p]=0; }
		display();
	}
}

int dequeue()
{
	flag=0;
	int e,p=0;
	while(p<MAXP)
	{
		if(f[p]==-1){
		p=p+1; }
		else
		{
			e =pq[p][f[p]];
			f[p]=f[p]+1;
			if(f[p]>r[p]){
			f[p]=-1;
			r[p]=-1;
			}
	        	break;
		}
	}
		if((p==MAXP-1 && f[p]==-1) || (p==MAXP)){
		printf("Q underflow\n");
		flag=2; }

		return e;
}

int main()
{
 int item;
 int c;
 memset(f,-1,sizeof(f));
 memset(r,-1,sizeof(r));

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
	if(flag!=2){
        printf("item is %d\n",ret); }
	display();
        break;
        case 3: display();
        break;
        case 4: break;
 }
}while(c!=4);
return 0;
}
