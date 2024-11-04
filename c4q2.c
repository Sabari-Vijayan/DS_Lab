#include<stdio.h>
struct tuple
{
    int r;
    int c;
    int value;
};
void read( int a[][20],int m,int n)
{
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
}
void convert(struct tuple* t,int a[][20],int r,int c,int* n)
{
    t[0].r=r;
    t[0].c=c;
    int k=1;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(a[i][j]!=0)
            {
                t[k].r=i;
                t[k].c=j;
                t[k].value=a[i][j];
                k++;
            }
        }
    }
    t[0].value=k-1;
    *n=k;
}
void display(struct tuple* t,int num)
{
      for(int i=0;i<num;i++)
      {
          printf("%d %d %d\n",t[i].r,t[i].c,t[i].value);
      }
      printf("\n");
}
void sort(struct tuple* b,int n)
{
    int i=1,j,t1,t2,t3;
    while(i<n-1)
    {
        for(j=i+1;j<n;j++)
        {
            if(b[i].r>b[j].r)
            {
                t1=b[i].r;
                t2=b[i].c;
                t3=b[i].value;
                b[i].r=b[j].r;
                b[i].c=b[j].c;
                b[i].value=b[j].value;
                b[j].r=t1;
                b[j].c=t2;
                b[j].value=t3;
            }
        }
        i++;
    }
    i=1;
    while(i<n-1)
    {
        for(j=i+1;j<n;j++)
        {
            if(b[i].r==b[j].r)
            {
                if(b[i].c > b[j].c)
                {
                    t1=b[i].c;
                    t2=b[i].value;
                    b[i].c=b[j].c;
                    b[i].value=b[j].value;
                    b[j].c=t1;
                    b[j].value=t2;
                }
            }
        }
        i++;
    }
}
void transpose(struct tuple* a,struct tuple* b,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
       b[i].r=a[i].c;
       b[i].c=a[i].r;
       b[i].value=a[i].value;
    }
    sort(b,n);
}

void sum(struct tuple* a,struct tuple* b,struct tuple* c,int n1,int n2,int* n)
{
    int k=1,i,j;
    c[0].r=a[0].r;
    c[0].c=a[0].c;
    for(i=1;i<n1;i++)
    {
        for(j=1;j<n2;j++)
        {
            if(a[i].r == b[j].r && a[i].c == b[j].c)
            {
                c[k].r=a[i].r;
                c[k].c=a[i].c;
                c[k].value=a[i].value + b[j].value;
                k++;
                break;
            }
        }
        if(j==n2)
        {
            c[k].r=a[i].r;
            c[k].c=a[i].c;
            c[k].value=a[i].value;
            k++;
        }
    }
    for(i=1;i<n2;i++)
    {
        for(j=1;j<k;j++)
        {
            if(c[j].r == b[i].r && c[j].c == b[i].c)
            {
                break;
            }
        }
        if(j==k)
        {
            c[k].r=b[i].r;
            c[k].c=b[i].c;
            c[k].value=b[i].value;
            k++;
        }
    }
    c[0].value=k-1;
    sort(c,k);
    *n=k;
}
int main()
{
    int m1[20][20],m2[20][20];
    struct tuple t1[20],t2[20],t3[50],T1[20],T2[20],T3[20];
    int r,c,n1,n2,n3;
    printf("NUMBER OF ROWS AND COLUMNS OF MATRIX 1 SHOULD BE EQUAL TO NUMBER OF ROWS AND COLUMNS OF MATRIX 2 TO PERFORM ADDITION \n");
    printf("enter the no of rows and columns of matrix 1 and 2: ");
    scanf("%d%d",&r,&c);
    printf("enter elements to matrix 1:\n");
    read(m1,r,c);
    printf("enter elements to matrix 2:\n");
    read(m2,r,c);
    convert(t1,m1,r,c,&n1);
    convert(t2,m2,r,c,&n2);
    printf("\ntuple form of matrix 1 is :\n");
    display(t1,n1);
    printf("tuple form of matrix 2 is :\n");
    display(t2,n2);
    sum(t1,t2,t3,n1,n2,&n3);
    printf("tuple form of sum is :\n");
    display(t3,n3);
    transpose(t1,T1,n1);
    transpose(t2,T2,n2);
    transpose(t3,T3,n3);
    printf("\ntuple form of transpose of matrix 1 is:\n");
    display(T1,n1);
    printf("tuple form of transpose of matrix 2 is:\n");
    display(T2,n2);
    printf("tuple form of transpose of sum is:\n");
    display(T3,n3);
    return 0;
}
