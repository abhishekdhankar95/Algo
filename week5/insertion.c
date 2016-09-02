#include<stdio.h>
#include<stdlib.h>

void insertionSort(int arr[],int n){
	
	int i,j;
	int max;
	for(i=1;i<n;i++){
		max=arr[i];
		for(j=i-1;j>=0;j--){
			if(arr[j]>max){
				arr[j+1]=arr[j];
			}
			else 
				break;
		}
		arr[j+1]=max;
	}
	for(i=0;i<n;i++){
		printf(" %d ",arr[i]);
	}
}

void main(){
	int n;
	printf("Enter the number of elements: ");
	scanf("%d",&n);
	
	int i,arr[n];
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	
	insertionSort(arr,n);
}
