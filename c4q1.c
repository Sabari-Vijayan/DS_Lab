#include<stdio.h>
#include<stdlib.h>
//void sort(struct poly* a,int n);
struct poly
{
    int c;
    int e;
};
void sort(struct poly* a,int n);
void read(struct poly a[],int n)
{
    int i=0,j;
     while(i<n)
     {
       printf("enter the coefficient and exponent of term %d : ",i+1);
       scanf("%d%d",&a[i].c,&a[i].e);
       i++;
     }
     for(i=0;i<n;i++)
     {
         if(a[i].c==0)
         {
             a[i].e==0;
         }
     }
     sort(a,n);
     for(i=0;i<n-1;i++)
     {
         for(j=i+1;j<n;j++)
         {
             if(a[i].e==a[j].e)
             {
                 a[i].c+=a[j].c;
                 a[j].e=0;
                 a[j].c=0;
             }
         }
     }
     sort(a,n);
}

void display(struct poly a[],int n)
{
    int i=0;
    while(i<n)
    {
         if(a[i].c!=0)
         {
             if(a[i].e!=0)
             {
                 printf("+[%d(X^%d)]",a[i].c,a[i].e);
             }
             else
             {
                 printf("+[%d]",a[i].c);
             }
         }
         i++;
    }
     printf("\n");
}

void sort(struct poly* a,int n)
{
    int i=0,j;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i].e<a[j].e)
            {
                int temp1=a[i].e;
                int temp2=a[i].c;
                a[i].e=a[j].e;
                a[i].c=a[j].c;
                a[j].e=temp1;
                a[j].c=temp2;
            }
        }
    }
}

void sum(struct poly* a,struct poly* b, struct poly* c,int n1,int n2,int* ptr)
{
     int k=0,j,i=0;
     while(i<n1)
     {
         for(j=0;j<n2;j++)
         {
             if(a[i].e==b[j].e)
             {
                 c[k].e=a[i].e;
                 c[k].c=a[i].c+b[j].c;
                 k++;
                 break;
             }
         }
         if(j==n2)
         {
             c[k].e=a[i].e;
             c[k].c=a[i].c;
             k++;
         }
         i++;
     }
     i=0,j=0;
     while(i<n2)
     {
         for(j=0;j<k;j++)
         {
             if(b[i].e==c[j].e)
             {
                 i++;
                 break;
             }
         }
         if(j==k)
         {
             c[k].e=b[i].e;
             c[k].c=b[i].c;
             k++;
             i++;
         }
     }
     *ptr=k;
     for(i=0;i<k;i++)
     {
         if(a[i].c==0)
         {
             a[i].e==0;
         }
     }
     sort(c,k);
}
int main()
{
    int n1,n2,n3;
    int* ptr=&n3;
    printf("enter no of terms of polynomial 1: ");
    scanf("%d",&n1);
    struct poly* a=(struct poly*)malloc(n1*sizeof(struct poly));
    printf("enter the first polynomial \n");
    read(a,n1);
    printf("enter no of terms of polynomial 2: ");
    scanf("%d",&n2);
    struct poly* b=(struct poly*)malloc(n2*sizeof(struct poly));
    printf("enter the second polynomial \n");
    read(b,n2);
    printf("polynomial 1 is\n");
    display(a,n1);
    printf("polynomial 2 is\n");
    display(b,n2);
    struct poly* c=(struct poly*)malloc((n1+n2)*sizeof(struct poly));
    sum(a,b,c,n1,n2,ptr);
    printf("sum of polynomial 1 and 2 is\n");
    display(c,n3);
    free(a);
    free(b);
    free(c);
    return 0;
}
