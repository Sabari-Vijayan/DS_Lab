#include <stdio.h>
int BinarySearch(int arr[],int size,int target)
{

        int mid,low=0,high=size-1;
        while(low<=high)
        {
                mid=(low+high)/2;
                if(arr[mid]==target)
                {
                        return mid;
                }
                else if(arr[mid]<target)
                {
                        low=mid+1;
                }
                else
                {
                        high=mid-1;
                }
        }
        printf("\nItem Not Present\n");
        return -1;
}
int main()
{
        int n,a[40];
        printf("enter size of array: ");
	scanf("%d",&n);
	printf("enter elements to array in ascending order :\n");
        for(int i=0;i<n;i++)
        {
                scanf("%d",&a[i]);
        }
        int target;
        printf("Enter Item to be searched: ");
        scanf("%d",&target);
        int index=(BinarySearch(a,n,target));
        if(index!=-1)
        {
                printf("\nElement %d found at index %d\n",target,index);
        }

        return 0;
}
