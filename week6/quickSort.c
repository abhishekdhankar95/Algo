#include<stdio.h>
#include<stdlib.h>

void swap(int arr[],int i,int j){
	int temp=arr[i];
	arr[i]=arr[j];
	arr[j]=temp;
}

int pivot(int arr[],int l,int r){
	int p=arr[l];
	int i=l;
	int j=r+1;
	//printf("%d",l);
	do{
		do{
			++i;
		}while(i<=r && arr[i]<p);
		do{
			--j;
		}while(j>=l && arr[j]>p);
		swap(arr,i,j);
	}while(i<j);
	
	swap(arr,i,j);
	swap(arr,l,j);
	return j;
}

void quickSort(int arr[],int l,int r){
	if(l<r){
		//printf("here1");
		int p=pivot(arr,l,r);
		quickSort(arr,p+1,r);
		quickSort(arr,l,p-1);
	}
}

void main(){
	int n;
	printf("\nEnter the number of elements: ");
	
	scanf("%d",&n);
	
	printf("\n Start entering: ");
	int i,j,arr[n];
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	
	quickSort(arr,0,n-1);
	for(i=0;i<n;i++){
		printf(" %d ",arr[i]);
	}
}
