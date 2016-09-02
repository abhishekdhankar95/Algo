#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct st{
    struct st *ptr;
    int data;
}node;

node *getNode(){
    node *newNode=(node *)malloc(sizeof(node));
    newNode->ptr=NULL;
    return newNode;
}


void main(){
    int i,vertices,edges,x;

    printf("\nEnter the number of vertices: ");
    scanf("%d",&vertices);

    int graph[vertices][vertices];
    for(i=0;i<vertices;i++){
        for(x=0;x<vertices;x++){
            graph[i][x]=0;
        }
    }

    node *adList[vertices];
    for(i=0;i<vertices;i++){
        adList[i]=getNode();
    }

    printf("\nEnter the number of edges: ");
    scanf("%d",&edges);

    int edgeDetail[edges][2];


    printf("\n*******Enter edges as promptes******** \n");
    for(i=0;i<edges;i++){
        printf("\nEnter the one vertex of the edge %d: ",i);
        scanf("%d",&edgeDetail[i][0]);
        printf("\nEnter the other vertex of the same edge %d: ",i);
        scanf("%d",&edgeDetail[i][1]);
        printf("\n\n****\n\n");
        graph[edgeDetail[i][0]-1][edgeDetail[i][1]-1]=1;
        graph[edgeDetail[i][1]-1][edgeDetail[i][0]-1]=1;

        int a=edgeDetail[i][0];
        int b=edgeDetail[i][1];
printf("\n  %d %d",a,b);

    node *newNode1=getNode();
    newNode1->ptr=adList[a-1]->ptr;
    adList[a-1]->data=adList[a-1]->data+1;
    adList[a-1]->ptr=newNode1;
    newNode1->data=b;

    node *newNode2=getNode();
     newNode2->ptr=adList[b-1]->ptr;
     adList[b-1]->data=adList[b-1]->data+1;
    adList[b-1]->ptr=newNode2;
    newNode2->data=a;
    }

int j;
    for(i=0;i<edges;i++){
        for(j=0;j<2;j++){
            printf(" %d ",edgeDetail[i][j]);
        }
        printf(" \n ");
    }
printf("\n**MATRIX**\n");
    for(i=0;i<vertices;i++){
        for(j=0;j<vertices;j++){
            printf(" %d ",graph[i][j]);
        }
        printf("\n");
    }

    for(i=0;i<vertices;i++){
        node *temp=adList[i];
        printf("For %d: ",i+1);
        printf("Total number of edges: %d",temp->data);
        temp=temp->ptr;
        while(temp!=NULL){
            printf(" %d ",temp->data);
            temp=temp->ptr;
        }
        printf("\n\n");
    }
}
