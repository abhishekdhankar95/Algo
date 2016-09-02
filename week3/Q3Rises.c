#include<stdio.h>
#include<stdlib.h>

int permutationFound=0;

void swap(int a[],int i,int j){
	int t=a[i];
	a[i]=a[j];
	a[j]=t;
}

int findingNemo(int a[],int total){
	int i,sum=0;
	for(i=0;i<total;i++){
		sum=sum+a[i];
	}
	int sumByTwo=0,j=0;
	for(i=0;i<total;i++){
		j=0;
		sumByTwo+=a[i];
		if(sumByTwo==sum/2){
			printf("\nPartition 1: ");
			while(j<=i){
				
				printf(" %d ",a[j]);
				j++;
			}
			printf("\n");
			printf("\nPartition 2: ");
			while(j<total){
				printf(" %d ",a[j]);
				j++;
			}
			printf("\n\n");
			return 1;
		}
	}
	return 0;
}

void permute(int a[],int total,int i){
	int k;
	
	if(i==total){
		permutationFound=findingNemo(a,total);
		return;
	}
	if(permutationFound)
		return;
	int j;
	for(j=i;j<total;j++){
		swap(a,i,j);
		
		permute(a,total,i+1);
		swap(a,i,j);
	}
}

void main(){
	int total,i;
	printf("Enter the number of numbers: ");
	scanf("%d",&total);
	int a[total];
	for(i=0;i<total;i++){
		printf("\nEnter the %d th number: ",i);
		scanf("%d",&a[i]);
	}
	permute(a,total,0);
	if(!permutationFound)
		printf("No permutation possible!!!");
}
