#include <stdio.h>
void LinearSearch(int a[],int size,int target)
{
        int n=size,flag=0;
        for(int i=0;i<n;i++)
        {
                if(a[i]==target)
                {
                        printf("Element %d found at index %d\n",target,i);
			flag=1;
                        break;
                }
        }
	if(flag==0)
	printf("element not found\n");
}
int main()
{
        int a[50];
        int size;
        int target,i;
        printf("Enter size of Array: ");
        scanf("%d",&size);
        printf("Enter Array: \n");
        for(i=0;i<size;i++)
        {
                scanf("%d",&a[i]);
        }
        printf("Enter Target: ");
        scanf("%d",&target);
        LinearSearch(a,size,target);
        return 0;
}
