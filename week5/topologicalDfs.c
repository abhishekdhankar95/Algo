#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct st{
	int v;
	struct st *ptr;
}node;

node * getNode(){
	node *newNode=malloc(sizeof(node));
	newNode->ptr=NULL;
	return newNode;
}

node *header;

void push(int v,node **header){
	node *newNode=getNode();
	newNode->v=v;
	node *temp=*header;
	
	while(temp->ptr){
		temp=temp->ptr;
	}
	temp->ptr=newNode;
}

void disp(node **header){
	node *temp=(*header)->ptr;
	while(temp){
		printf(" %d ",((temp->v)+1));
		temp=temp->ptr;
	}
}

void dfs(int **adMat,int visited[],int vertices,int start,node **header){
	int i;
	for(i=0;i<vertices;i++){
		if(adMat[start][i] && !visited[i]){
			
			int flag=1;
			int j;
			for(j=0;j<vertices;j++){
				if(j!=i)
					if(adMat[j][i] && !visited[j]){
						flag=0;
						break;
					}
			}
			
			if(flag){
				printf(" %d ",(i+1));
				visited[i]=1;
			}
			dfs(adMat,visited,vertices,i,header);
		}
	}
	//push(start,header);
	
}

void main(){
	int i,j;
	int vertices;
	printf("\nEnter the number of vertices: ");
	scanf("%d",&vertices);
	//node *header[vertices];
	
	int **adMat=malloc(vertices*sizeof(int *));
	
	
	for(i=0;i<vertices;i++){
		*(adMat+i)=malloc(vertices*sizeof(int));
	}
	for(i=0;i<vertices;i++)
		for(j=0;j<vertices;j++)
			adMat[i][j]=0;
	char c;
	int edges[vertices+1];
	for(i=0;i<vertices;i++){
		
				printf("\nEnter all the edges with directed vertices from %d (Enter -1 to exit): ",(i+1));
				for(j=0;j<vertices+1;j++){
					scanf("%d",&edges[j]);
					
					if(edges[j]==-1)
						break;
					edges[j]=edges[j]-1;
				}
				
				for(j=0;j<vertices && edges[j]!=-1;j++){
					
						
						adMat[i][edges[j]]=1;
					
				}
		
	}
	int visited[vertices];
	int color[vertices];
	for(i=0;i<vertices;i++)
		visited[i]=0;
	//int start;
	header=getNode();
	
	 node *free=getNode();
	
	for(i=0;i<vertices;i++){
		for(j=0;j<vertices;j++){
			if(j!=i && adMat[j][i]==1){
				break;
			}
		}
		if(j==vertices){
			visited[i]=1;
			push(i,&free);
			printf(" %d ",i+1);
		}
			
	}
	
	node *temp=free->ptr;
	while(temp){
		dfs(adMat,visited,vertices,temp->v,&header);
		temp=temp->ptr;
	}
	
}
