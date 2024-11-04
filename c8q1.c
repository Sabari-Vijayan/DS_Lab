#include<stdio.h>
#include<stdlib.h>

void bubbleSort(int* a,int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
          if(a[j]>a[j+1])
            {
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}

void insertionSort(int* a,int n)
{
    int i,j;
    for(i=1;i<n;i++)
    {
        int key=a[i];
        j=i-1;
        while(j>=0 && a[j]>key)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}

void quickSort(int* a,int low,int high)
{
    if(low<high)
    {
        int pivot=a[low],i=low+1,j=high,temp;
        while(i<=j)
        {
            while(a[i]<=pivot && i<=j)
            i++;

            while(a[j]>pivot && j>=i)
            j--;

            if(i<j)
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
        temp=a[j];
        a[j]=pivot;
        a[low]=temp;
        quickSort(a,low,j-1);
        quickSort(a,j+1,high);
    }
}

void mergeSort(int* a,int* b,int low,int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        mergeSort(a,b,low,mid);
        mergeSort(a,b,mid+1,high);
        int i=low,j=mid+1,k=low;
        while(i<=mid && j<=high)
        {
            if(a[i]<=a[j])
            {
                b[k]=a[i];
                i++;
                k++;
            }
            else
            {
                b[k]=a[j];
                j++;
                k++;
            }
        }
        while(i<=mid)
        {
            b[k]=a[i];
            i++;
            k++;
        }
        while(j<=high)
        {
            b[k]=a[j];
            j++;
            k++;
        }
        i=low;
        while(i<=high)
        {
            a[i]=b[i];
            i++;
        }
    }
}
void selectionSort(int* a,int n)
{
    int i,j,minpos;
    for(i=0;i<n-1;i++)
    {
        minpos=i;
        for(j=i+1;j<n;j++)
        {
            if(a[minpos]>a[j])
            {
                minpos=j;
            }
        }
        if(minpos!=i)
        {
            int temp=a[minpos];
            a[minpos]=a[i];
            a[i]=temp;
        }
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}
void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}


int main()
{
    int n,i,c;
    printf("enter size of array : ");
    scanf("%d",&n);
    int* a=(int*)malloc(n*sizeof(int));
    int* Q=(int*)malloc(n*sizeof(int));
    printf("enter elements to array\n");
    for(i=0;i<n;i++)
    {
         scanf("%d",&a[i]);
         Q[i]=a[i];
    }
    do
    {
        printf("\n\n1-BUBBLESORT 2-SELECTIONORT 3-INSERTIONSORT\n4-QUICKSORT 5-MERGESORT 6-HEAPSORT 7-EXIT\nENTER CHOICE : ");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
            bubbleSort(a,n);
	    printf("\nafter sorting: ");
            for(i=0;i<n;i++)
            printf("%d ",a[i]);
            break;

            case 2:
            selectionSort(a,n);
	    printf("\nafter sorting: ");
            for(i=0;i<n;i++)
            printf("%d ",a[i]);
            break;

            case 3:
            insertionSort(a,n);
	    printf("\nafter sorting: ");
            for(i=0;i<n;i++)
            printf("%d ",a[i]);
            break;

            case 4:
            quickSort(a,0,n-1);
	    printf("\nafter sorting: ");
            for(i=0;i<n;i++)
            printf("%d ",a[i]);
	    break;

            case 5:
	    int* b=(int*)malloc(n*sizeof(int));
            mergeSort(a,b,0,n-1);
	    printf("\nafter sorting: ");
            for(i=0;i<n;i++)
            printf("%d ",a[i]);
	    free(b);
            break;

            case 6:
            //int* b=(int*)malloc(n*sizeof(int));
            heapSort(a,n);
            printf("\nafter sorting: ");
            for(i=0;i<n;i++)
            printf("%d ",a[i]);
            free(b);
            break;


            case 7:
	    free(a);
	    free(Q);
            break;

	    default:
	    printf("INVALID CHOICE");
    	    break;
	}

         for(i=0;i<n;i++)
         a[i]=Q[i];

     }while(c!=7);

    return 0;
}
