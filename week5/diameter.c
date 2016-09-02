#include<stdio.h>
#include<stdlib.h>

typedef struct st1{
	int l;
	struct st1 *ptr;
}anoNode;

anoNode *getAnoNode(){
	anoNode *newNode=malloc(sizeof(anoNode));
	newNode->ptr=NULL;
	return newNode;
}

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

void push(anoNode **header,int l){
	anoNode *temp=*header;
	anoNode *newNode=getAnoNode();
	newNode->l=l;
	newNode->ptr=temp->ptr;
	temp->ptr=newNode;
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

int maxNumber(node *header){
	if(header==NULL)
		return 0;
	int a=1+maxNumber(header->lchild);
	int b=1+maxNumber(header->rchild);
	return a>b?a:b;
}

void inorder(node *header,anoNode **head){
	if(header==NULL)
		return;
	int a=maxNumber(header->lchild);
	int b=maxNumber(header->rchild);
	inorder(header->lchild,head);
	inorder(header->rchild,head);
	push(head,a+b+1);
}

void main(){
	node *header=NULL;
	int n=1;
	
	while(n){
		printf("\nEnter\n1 for insert\n0 for exit and diameter: ");
		scanf(" %d",&n);
		switch(n){
			case 1:
					insert(&header);
					break;
			
		}
	}
	anoNode *head=getAnoNode();
	inorder(header,&head);
	anoNode *t=head->ptr;
	int max=0;
	while(t){
		printf(" %d ",t->l);
		if(t->l>max)
			max=t->l;
		t=t->ptr;
		
	}
	printf("\nThe diameter is: %d\n",max);
	
}
