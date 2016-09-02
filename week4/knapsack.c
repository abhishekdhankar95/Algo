#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int count=0;

typedef struct st{
	float weight,value;
	//struct st *ptr;
}node;

typedef struct st1{
	node item;
	struct st1 *ptr;
}anoNode;

anoNode * getNode(){
	anoNode *newNode=malloc(sizeof(anoNode));
	(newNode->item).weight=0;
	(newNode->item).value=0;
	newNode->ptr=NULL;
	return newNode;
}

void push(anoNode **header,node item){
	anoNode *newNode=getNode(),*temp=*header;
	(temp->item).weight+=item.weight;
	(temp->item).value+=item.value;
	(newNode->item).weight=item.weight;
	(newNode->item).value=item.value;
	newNode->ptr=temp->ptr;
	temp->ptr=newNode;
	//printf("%f",item.weight);
}

void disp(anoNode *header){
	anoNode *temp=header->ptr;
	
	while(temp){
		printf("\nweight=%f, value=%f \n",(temp->item).weight,(temp->item).value);
		temp=temp->ptr;
	}
}

void findingNemo(node v[],int size,float w){
	float max=0,weightSum=0,valueSum=0;
	int powSize=pow(2,size);
	printf("%d",powSize);
	anoNode *header[powSize];
	int i,j;
	for(i=0;i<powSize;i++){
		header[i]=getNode();
	}
	
	for(i=0;i<powSize;i++){
	weightSum=0;
	valueSum=0;
		count++;
		for(j=0;j<size;j++){
		//printf(" %d ",(i & (1<<j)));
		count++;
		//printf();
			if(i & (1<<j)){
				//printf("wat");
				weightSum+=v[j].weight;
				valueSum+=v[j].value;
				push(&header[i],v[j]);
				//printf("what");
			}
			
			if(weightSum<=w && valueSum>max)
				max=valueSum;
		}
		
		
		}
		
		for(i=0;i<powSize;i++){
			if(max==(header[i]->item).value &&(header[i]->item).weight<=w){
				printf("\n*********\n");
				disp(header[i]);
			}
		}
		
		//disp(header);
		//findingBatman(&header);
		printf("\n");
	
}

void main(){
int n;
	printf("\nEnter the number of items: ");
	
	scanf("%d",&n);
	
	node items[n];
	int i;	
	for(i=0;i<n;i++){
		printf("\nEnter the weight: ");
		scanf("%f",&(items[i].weight));
		printf("\nEnter the value: ");
		scanf("%f",&(items[i].value));
	}
	float w;
	
	printf("\nEnter the max Capacity: ");
	scanf("%f",&w);
	
	findingNemo(items,n,w);
	
	printf("\nCount: %d\n",count);
}
