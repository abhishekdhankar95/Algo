#include<stdio.h>
#include<stdlib.h>
#include<math.h>



int ** powerSet(int v[],int vSize,int **vMod){
	int powSize=pow(2,vSize);
	int i,j,k=0;
	for(i=0;i<powSize;i++){
		k=0;
		for(j=0;j<vSize;j++){
			if(i & (1<<j)){
				vMod[i][k++]=v[j];
				
			}
			
		}
		printf("\n");
	}
	return vMod;
}

int isConnected(int **adMat,int *vMod,int vertices){
	int i=0,j=0,k=0;
	for(i=0;i<vertices && vMod[i];i++);
	printf(" i= %d ",i);
	if(i==1)
		return 1;
	for(j=0;j<i-1;j++){
		for(k=j+1;k<i;k++){
			
			if(!adMat[vMod[j]-1][vMod[k]-1])
				return 0;
		}
	}
	return i;
}

int *maxCliq(int **adMat,int vertices,int **vMod){
	int *maxVertexSet=NULL;
	int powNumber=pow(2,vertices),i,j;
	int yes=0,temp;
	for(i=0;i<powNumber;i++){
			temp=isConnected(adMat,*(vMod+i),vertices);
			if(temp>yes){
				yes=temp;
				maxVertexSet=*(vMod+i);
			}
			
	}
	
	return maxVertexSet;
	
}

void main(){
	int n=10,i=0,j=0,vertices;
	printf("\nEnter the number of vertices: ");
	scanf("%d",&vertices);
	int **vMod=(int **)malloc(pow(2,vertices)*sizeof(int *));
	int v[vertices];
	
	for(i=0;i<pow(2,vertices);i++)
		*(vMod+i)=(int *)malloc(vertices*sizeof(int));
	
	
	
	for(i=0;i<pow(2,vertices);i++){
		for(j=0;j<vertices;j++)
			vMod[i][j]=0;
	}
	
	for(i=0;i<vertices;i++)
		v[i]=i+1;
	
	vMod=powerSet(v,vertices,vMod);

	j=0;
	printf("\n\n\n");
	for(i=0;i<pow(2,vertices);i++){
		for(j=0;j<vertices && vMod[i][j];j++){
			printf(" %d ",vMod[i][j]);
			//j++;
		}
		printf("\n");
	}
	
	int **adMat=(int **)malloc(vertices*sizeof(int *));
	for(i=0;i<vertices;i++)
		*(adMat+i)=malloc(vertices*sizeof(int));
	
	
	for(i=0;i<vertices;i++)
		for(j=0;j<vertices;j++)
			adMat[i][j]=0;
	char c;
	for(i=0;i<vertices;i++){
		for(j=0;j<vertices;j++){
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
	printf("\n\n\n");
	for(i=0;i<vertices;i++){
		for(j=0;j<vertices;j++)
			printf(" %d ",adMat[i][j]);
		printf("\n");
	}
	printf("\n\n\n");
	int *maxClique=maxCliq(adMat,vertices,vMod);
	printf("\nThe vertices are: ");
	for(i=0;i<vertices && maxClique[i];i++)
		printf(" %d ",maxClique[i]);
	
}
