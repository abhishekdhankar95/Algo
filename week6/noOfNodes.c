#include<stdio.h>
#include<stdlib.h>

typedef struct st{
	char c;
	struct st *lchild,*rchild;
}node;

node * getNode(){
	node * newNode=malloc(sizeof(node));
	newNode->lchild=NULL;
	newNode->rchild=NULL;
	return newNode;
}



void insert(node **header){
	char c;
	if((*header)==NULL){
		printf("Enter the char for the root: ");
		scanf(" %c",&c);
		(*header)=getNode();
		(*header)->c=c;
		return;
	}
	int n;
	node *temp=*header,*prev=*header;
	node *newNode=getNode();
	//newNode->c=c;
	
	while(temp){
		prev=temp;
		printf("1 for left 2 for right: ");
		scanf(" %d",&n);
		if(n==1){
			temp=temp->lchild;
		}
		else if(n==2)
			temp=temp->rchild;
	}
	printf("Enter the character: ");
	scanf(" %c",&c);
	newNode->c=c;
	if(n==1){
		prev->lchild=newNode;
	}
	else if(n==2){
		prev->rchild=newNode;
	}
}

int inorder(node *header){
	if(header==NULL)
		return 0;
	return 1+inorder(header->lchild)+inorder(header->rchild);
}

void main(){
	node *header=NULL;
	int n=1;
	
	while(n){
		printf("\nEnter\n1 for insert\n2 for exit and number of nodes: ");
		scanf(" %d",&n);
		switch(n){
			case 1:
					insert(&header);
					break;
			
		}
	}
	
	int nodes=inorder(header);
		printf("\nThe number of nodes are: %d",nodes);
	
}
