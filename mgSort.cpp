//Name		:	Dinesh Suthar
//regNo	:	2022ca108
//Aim		:	Implementation of merge sort and plot a graph using GNUPLOT

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void merge(long int* arr, int s,int e)
{
	int mid  = s + (e-s)/2;
	int len1 = mid - s + 1;
	int len2 = e - mid;
	
	int * first= (int*) malloc(len1*sizeof(int));
	int * second = (int*)malloc(len2*sizeof(int));
	
	int mainArrayIndex = s,i = 0;
	for(i = 0 ; i < len1; i++)
		first[i] = arr[mainArrayIndex++];
	i = 0;
	for(i = 0; i < len2;i++)
		second[i] = arr[mainArrayIndex++];

	i = 0,mainArrayIndex = s;
	int j = 0;
	
	while( i < len1 && j < len2)
	{
		if(first[i] < second[j])
		{
			arr[mainArrayIndex++] = first[i];
			i++;
		}
		else {
			arr[mainArrayIndex++] = second[j];
			j++;	
		}
	}
	
	while(i < len1)
	{
			arr[mainArrayIndex++] = first[i];
			i++;
	}
	
	while(j < len2)
	{
		arr[mainArrayIndex++] = second[j];
			j++;
	}
}
void ms(long int* arr,int s,int e)
{
	if(s >= e)
		return;
	
	int mid  = s + (e-s)/2;
	
	ms(arr,s,mid);
	ms(arr,mid+1,e);
	merge(arr,s,e);	
}

int main()
{
	
	long int n = 10000,n1 = 11000,n2 = 12000;
	double time [3];
     	int index = 0;	
	       long int * arr = (long int*) malloc(n*sizeof(long int));
	       long int * arr1 = (long int*) malloc(n*sizeof(long int));
	       long int * arr2 = (long int*) malloc(n*sizeof(long int));
	       long int i = 0;
		for(i = 0; i < n;i++)
			  	arr[i] = i+1; 
		
		for(i = 0; i <n1;i++)
			arr1[i] = rand() % n1 + 1;
	        
	        for(i = 0; i< n2; i++)
	        	arr2[i] = n2 - i - 1;

	clock_t start, end;
	
	int s = 0,e = n -1;
 	start = clock();
        ms(arr, s,e);
        end = clock();
	
	time[index] = (double) (end - start);
	printf("%li %li\n",n,(long int)time[index]);
	index++;

	
	s = 0,e = n1 -1;
 	start = clock();
        ms(arr1, s,e);
        end = clock();
	
	time[index] = (double) (end - start);
	printf("%li %li\n",n1,(long int)time[index]);
	index++;

	s = 0,e = n2 -1;
 	start = clock();
        ms(arr2, s,e);
        end = clock();
	
	time[index] = (double) (end - start);
	printf("%li %li\n",n2,(long int)time[index]);
	return 0;
}
