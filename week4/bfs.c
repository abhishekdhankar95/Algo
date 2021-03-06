#include<stdio.h>
#include<stdlib.h>
#include<math.h>


typedef struct st{
	int v;
	struct st *ptr;
}node;

node *getNode(){
	node *newNode=malloc(sizeof(node));
	newNode->ptr=NULL;
	return newNode;
}

void enq(node **header,int v){
	node *temp=(*header);
	node *newNode=getNode();
	newNode->v=v;
	while(temp->ptr){
		temp=temp->ptr;
	}
	
	temp->ptr=newNode;
	newNode->ptr=NULL;
}

int deq(node **header){
	node *temp=(*header)->ptr;
	(*header)->ptr=temp->ptr;
	temp->ptr=NULL;
	return temp->v;
}

void disp(node *header){
	node *temp=header->ptr;
	while(temp){
		printf(" %d ",(temp->v)+1);
		temp=temp->ptr;
	}
}


void bfs(int **adMat,node **header,int n,int visited[]){
	int v,i;
	while((*header)->ptr!=NULL){
		v=deq(header);
		
		printf(" %d ",v+1);
		for(i=0;i<n;i++){
			if(adMat[v][i] && !visited[i]){
				visited[i]=1;
				enq(header,i);
			}
		}
	}
}


void main(){
	int n,i,j;
	printf("\nEnter the number of vertices: ");
	scanf("%d",&n);
	
	int visited[n];
	for(i=0;i<n;i++){
		visited[i]=0;
	}
	
	int **adMat=(int **)malloc(n*sizeof(int *));
	for(i=0;i<n;i++)
		*(adMat+i)=malloc(n*sizeof(int));
	
	
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			adMat[i][j]=0;
	char c;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(j>i){
				printf("\nIs there an edge between %d and %d(y / n): ",(i+1),(j+1));
				scanf(" %c",&c);
				if(c=='y'){
					adMat[i][j]=1;
					adMat[j][i]=1;
				}
				
			}
				
		}
	}
	
	node *header=getNode();
	for(i=0;i<n;i++){
		if(!visited[i]){
			visited[i]=1;
			enq(&header,i);
			bfs(adMat,&header,n,visited);
		}
	}
	printf("\n\n");
}
