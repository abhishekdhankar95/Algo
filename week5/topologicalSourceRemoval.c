#include<stdio.h>
#include<stdlib.h>

void topo(int **adMat,int visited[],int vertices){
	int i,j,k;
	while(1){
		int count=0;
		for(i=0;i<vertices;i++){
			if(visited[i])
				count++;
		}
		if(count==vertices)
			break;
	for(i=0;i<vertices;i++){
		if(!visited[i]){
			for(j=0;j<vertices;j++){
				if(j!=i && adMat[j][i]==1){
					break;
			}	
			}
			if(j==vertices){
				visited[i]=1;
				int k;
				for(k=0;k<vertices;k++)
					adMat[i][k]=0;
				//push(i,&free);
				printf(" %d ",i+1);
			
			}
		}
			
	}
	}
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
	
	for(i=0;i<vertices;i++)
		visited[i]=0;
	
	
	
	topo(adMat,visited,vertices);
	
	
}
