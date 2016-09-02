#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//int permutationFound;
int count;


typedef struct st{
	int data;
	struct st *ptr;
}node;

node *getNode(){
	node *newNode=malloc(sizeof(node));
	newNode->ptr=NULL;
	newNode->data=0;
	return newNode;
}

void push(node **header,int data){
	node *temp=*header;
	node *newNode=getNode();
	newNode->data=data;
	newNode->ptr=temp->ptr;
	temp->ptr=newNode;
	(*header)->data++;
}

void swap(int arr[],int i,int j){
	int temp=arr[i];
	arr[i]=arr[j];
	arr[j]=temp;
}


void findingNemo(int arr[],int total){
	int size=total,sum=0,i,j;
	for(i=0;i<size;i++){
		sum+=arr[i];
	}
	//printf("\n\n%d",sum);
	if(sum%2!=0){
		return;
	}
	int sumByTwo=0;
	for(i=0;i<size;i++){
		sumByTwo+=arr[i];
		if(sumByTwo==sum/2){
		int j;
			printf("\n\nFirst Partition: ");
			for(j=0;j<(i+1);j++)
				printf(" %d ",arr[j]);
			printf("\n\nSecond Partition: ");
			for(j=i+1;j<size;j++)
				printf(" %d ",arr[j]);
	}
	}
}

void permute(int a[],int total,int i){
	int k;
	count++;
	if(i==total){
		
		findingNemo(a,total);
		return;
	}
	
	int j;
	for(j=i;j<total;j++){
		swap(a,i,j);
		
		permute(a,total,i+1);
		swap(a,i,j);
	}
}

void findingBatman(node **header){

	int arr[(*header)->data];
	node *temp=*header;
	temp=temp->ptr;
	int i=0;
	
	if(temp==NULL)
		return;
	while(temp!=NULL){
		//printf("here");
		arr[i++]=temp->data;
		temp=temp->ptr;
	}
	permute(arr,(*header)->data,0);
	
	
	
}

void disp(node *header){
	node *temp=header->ptr;
	while(temp){
		printf(" %d ",temp->data);
		temp=temp->ptr;
	}
}

void powerSet(int v[],int vSize){
	int powSize=pow(2,vSize);
	//printf(" %d ",powSize);
	int i,j,k=0;
	node *header;
	count=0;
	for(i=0;i<powSize;i++){
	
		header=NULL;
		header=getNode();
		for(j=0;j<vSize;j++){
		//printf(" %d ",(i & (1<<j)));
		count++;
			if(i & (1<<j)){
			//printf(" %d ",v[j]);
				//printf(" %d ",v[j]);
				push(&header,v[j]);
				
			}
			
		}
		//disp(header);
		findingBatman(&header);
		printf("\n");
	}
	
}

void main(){
	int n,isIt=0; 
	printf("\nEnter the number of numbers: ");
	scanf("%d",&n);
	
	int arr[n],i;
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	
	powerSet(arr,n);
	
	printf("\n\nThe number of comparisons: %d",count);
	
}
	

