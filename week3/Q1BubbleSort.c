#include<stdio.h>
#include<stdlib.h>

int counter;

void swap(int arr[],int i,int j){
	int temp=arr[i];
	arr[i]=arr[j];
	arr[j]=temp;
}

void bubbleSort(int arr[],int size){
	int i,j;
	counter=0;
	for(i=0;i<size-1;i++){
		for(j=i+1;j<size;j++){
			counter++;
			if(arr[j]>arr[j+1]){
				swap(arr,i,j);
			}
		}
	}
}

void main(){
	int n;
	printf("\nEnter the number of numbers: \n");
	scanf("%d",&n);
	
	int arr[n],i;
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	
	bubbleSort(arr,n);
	
	for(i=0;i<n;i++){
		printf(" %d ",arr[i]);
	}
	
	printf("\n\n%d\n",counter);
}
