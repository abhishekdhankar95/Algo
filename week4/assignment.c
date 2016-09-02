#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int min;
int count=0;

void findingNemo(int **time,int a[],int ppl,int res[]){
	int sum=0,i;
	//printf("%d",min);
	for(i=0;i<ppl;i++){
		sum+=time[i][a[i]];
	}
	//printf("%d",sum);
	if(sum<min){
		for(i=0;i<ppl;i++){
				res[i]=a[i];
			}
	}
}

void swap(int arr[],int i,int j){
	int temp=arr[i];
	arr[i]=arr[j];
	arr[j]=temp;
}

void permute(int a[],int **time,int total,int res[],int i){
	int k;
    int j;
    count++;
	if(i==total){
	
		findingNemo(time,a,total,res);
		return;
	}
	
	
	for(j=i;j<total;j++){
		swap(a,i,j);
		
		permute(a,time,total,res,i+1);
		swap(a,i,j);
	}
}


void main(){
 	int ppl;
 	min=100000;
	printf("\nEnter the number of people: ");
	scanf("%d",&ppl);
	
	int i,j;
	int **time=malloc(ppl*sizeof(int *));
	for(i=0;i<ppl;i++){
		*(time+i)=malloc(ppl*sizeof(int));
	}
	for(i=0;i<ppl;i++){
		for(j=0;j<ppl;j++){
			printf("\nPerson %d for job %d: ",(i+1),(j+1));
			scanf("%d",&time[i][j]);
		}
	}
	int a[ppl],res[ppl];
	for(i=0;i<ppl;i++){
		a[i]=i;
	}
	permute(a,time,ppl,res,0);
	for(i=0;i<ppl;i++){
		printf("Person  %d= %d ",(i+1),res[i]+1);
		
	}
	printf("\nCount: %d\n",count);
}
