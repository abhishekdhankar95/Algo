#include<stdio.h>
#include<stdlib.h>

int counter;

void swap(int arr[],int i,int j){
	int temp=arr[i];
	arr[i]=arr[j];
	arr[j]=temp;
}

void selectionSort(int arr[],int size){
	int i,j,min;
	counter=1;
	for(i=0;i<size-1;i++){
	min=i;
		for(j=i+1;j<size;j++){
			counter++;
			if(arr[min]>arr[j])
				min=j;
		}
		swap(arr,min,i);
	}
}

void main(){
	int n;
	printf("\nEnter the number of numbers: ");
	scanf("%d",&n);
	
	int arr[n],i;
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	
	selectionSort(arr,n);
	for(i=0;i<n;i++){
		printf(" %d ",arr[i]);
	}
	printf("\n%d\n",counter);
}
