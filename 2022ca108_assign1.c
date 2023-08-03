//--------------------BUBBLE SORT-------------------------
//Name	:	Dinesh Suthar
//RegNo:	2022ca108
//Aim	:	Bubble Sort
#include<stdio.h>

void main()
{
	int n;
	printf("Enter n: ");
	scanf("%d",&n);
	int arr[n];
	int i,j;
	//Enter the values of an array
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	//Bubble sort swapping
	for(i=0;i<n;i++)
	{
		for(j=i;j<n-1;j++)
		{
			if(arr[j+1]<arr[j])
			{
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	//printing the ascending 
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
	for(i=n-1;i>=0;i--)
		printf("%d ",arr[i]);
	
}

//--------------------SELECTION SORT-------------------------
//Name	:	Dinesh Suthar
//RegNo:		2022ca108
//Aim	:	Selection Sort
#include<stdio.h>

void main()
{
	int n;
	printf("Enter n: ");
	scanf("%d",&n);
	int arr[n];
	int i,j,min;
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	for(i=0;i<n;i++)
	{
		min=i;
		for(j=i;j<n;j++)
			if(arr[j]<arr[min])
				min=j;
		if(min!=i)
		{
			int temp=arr[i];
			arr[i]=arr[min];
			arr[min]=temp;		
		}
	}
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
} 

//--------------------INSERTION SORT-------------------------
//Name	:	Dinesh Suthar
//RegNo:	2022ca108
//Aim	:	Insertion Sort

#include<stdio.h>

void main()
{
	int n;
	printf("Enter n: ");
	scanf("%d",&n);
	int arr[n];
	int i,j,min;
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	int key;
	for(i=1;i<n;i++)
	{
		key=arr[i];
		j=i-1;
		while(j>=0 && arr[j]>key)
		{
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=key;
	}
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
}

//--------------------QUICK SORT-------------------------
//Name	:	Dinesh Suthar
//RegNo:	2022ca108
//Aim	:	Quick Sort

#include<stdio.h>

int pdx(int *arr,int low,int high)
{
	int pivot=arr[high];
	int j,i=low-1;
	for(j=low;j<high;j++)
	{
		if(arr[j]<pivot)
		{
			i++;
			int temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
	}	
	int temp=arr[i+1];
	arr[i+1]=arr[high];
	arr[high]=temp;
	return i+1;
}

void quickSort(int *arr,int low,int high)
{
	if(low<high)
	{
		int pi=pdx(arr,low,high);
		quickSort(arr,low,pi-1);
		quickSort(arr,pi+1,high);
	}
}

void main()
{
	int n;
	printf("Enter n: ");
	scanf("%d",&n);
	int arr[n],i,j;
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	quickSort(arr,0,sizeof(arr)/sizeof(arr[0])-1);
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);		
}

//--------------------MERGE SORT-------------------------
//Name	:	Dinesh Suthar
//RegNo:	2022ca108
//Aim	:	Merge Sort

#include<stdio.h>

void conqour(int *arr,int low,int mid,int high)
{
	int x1=mid-low+1;
	int x2=high-mid;
	int x=low;
	int left[x1],right[x2];
	int i,j;
	for(i=0;i<x1;i++)
		left[i]=arr[low+i];
	for(i=0;i<x2;i++)
		right[i]=arr[mid+1+i];
	i=0;
	j=0;
	while(i<x1 && j<x2)
	{
		if(left[i]<=right[j])
			arr[x++]=left[i++];
		else
			arr[x++]=right[j++];
	}
	while(i<x1)
			arr[x++]=left[i++];
			
	while(j<x2)
			arr[x++]=right[j++];
}
void divide(int *arr,int low,int high)
{
	if(low<high)
	{
		int mid=low+(high-low)/2;
		divide(arr,low,mid);
		divide(arr,mid+1,high);
		conqour(arr,low,mid,high);
	}
}

void main()
{
	int n;
	printf("Enter n: ");
	scanf("%d",&n);
	int arr[n],i,j;
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	divide(arr,0,sizeof(arr)/sizeof(arr[0])-1);
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);		
}

//--------------------HEAP SORT-------------------------
//Name	:	Dinesh Suthar
//RegNo:	2022ca108
//Aim	:	Heap Sort

#include <stdio.h>

void heapify(int arr[], int n, int i)
{
	int largest=i;
      int left=2*i+1;
      int right=2*i+2;
 
	if(left<n && arr[left]>arr[largest])
	      largest=left;
 
     if(right<n && arr[right]>arr[largest])
            largest=right;
 
    if(largest!=i) 
    {
		int temp=arr[i];
		arr[i]=arr[largest];
		arr[largest]=temp;

		heapify(arr,n,largest);
    }
}
 
void heapSort(int arr[], int n)
{
	int i;
	for(i=n/2-1;i>=0;i--)
      	heapify(arr,n, i);
      for(i=n-1;i>=0;i--) 
      {
      	int temp=arr[0];
		arr[0]=arr[i];
		arr[i]=temp;
      	
      	heapify(arr,i,0);
    	}
} 

int main()
{
    	int n;
	printf("Enter n: ");
	scanf("%d",&n);
	int arr[n],i,j;
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
    	heapSort(arr,n);
    	for(i=0;i<n;i++)
    		printf("%d ",arr[i]);   	
}
