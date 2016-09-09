#include<stdio.h>
#include<stdlib.h>

void merge(int arr[],int a[],int b[],int l,int aSize,int bSize){
	int i=0,j=0,k=l;
	//printf("here");
	int size=aSize+bSize+1;
	while(i<aSize && j<bSize){
		if(a[i]<b[i])
			arr[k++]=a[i++];
		else 
			arr[k++]=b[j++];
	}
	while(i<=aSize)
		arr[k++]=a[i++];
	while(j<=bSize)
		arr[k++]=b[j++];
}

void mergeSort(int arr[],int l,int r){
	if(l<r){
		int n=(l+r)/2;
		int a[n+1];
		int b[n-l];
		int aSize=n+1,bSize=n-l;
		//printf("%d %d \n",aSize,bSize);
		int i,j;
		for(i=0;i<aSize;i++){
			a[i]=arr[i];
			if(i==0)
				printf("\n");
			printf(" %d \n",arr[i]);
		}
		printf("\n");
		for(j=0;j<bSize;j++){
			b[j]=arr[i+j];
			if(i==0)
				printf("\n");
			printf(" %d \n",arr[i+j]);
		}
		mergeSort(a,l,n);
		mergeSort(b,n+1,r);
		merge(arr,a,b,l,aSize,bSize);
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
	
	mergeSort(arr,0,n-1);
	for(i=0;i<n;i++){
		printf(" %d ",arr[i]);
	} 
	
	
}
