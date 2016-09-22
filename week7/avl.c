#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int flag=0;

typedef struct st{
	int num;
	int bal;
	struct st *lchild,*rchild;
}node;

node * getNode(){
	node * newNode=malloc(sizeof(node));
	newNode->lchild=NULL;
	newNode->rchild=NULL;
	newNode->bal=0;
	return newNode;
}

void disp(node *header){
	if(header==NULL)
		return;
	
	disp(header->lchild);
	
	disp(header->rchild);
	printf(" %d(%d) ",header->num,header->bal);
}


int maxNumber(node *header){
	if(header==NULL)
		return 0;
	int a=1+maxNumber(header->lchild);
	int b=1+maxNumber(header->rchild);
	return a>b?a:b;
}


void balCal(node **header,int num){
	if((*header)==NULL)
		return;
	node *temp=*header;
	balCal(&(temp->lchild),num);
	balCal(&(temp->rchild),num);
	
	(*header)->bal=maxNumber(temp->lchild)-maxNumber(temp->rchild);
	
	
	if(((*header)->bal>=2 || (*header)->bal<=-2)){
		printf("%d\n",(*header)->num);
		if(num>(*header)->num){
			node *temp1=((*header)->rchild);
			if(num>temp1->num){
				node *temp2=((temp1)->rchild);
				disp(*header);
				
				printf("\n");
				
				int swap=temp->num;
				temp->num=(temp1)->num;
				(temp1)->num=swap;
				
				disp(*header);
				
				printf("\n");
				
				temp->rchild=temp2;
				temp1->rchild=temp1->lchild;
				temp1->lchild=temp->lchild;
				temp->lchild=temp1;
				
				
				disp(*header);
				
				(*header)->bal=maxNumber(temp->lchild)-maxNumber(temp->rchild);
				temp1->bal=maxNumber(temp1->lchild)-maxNumber(temp1->rchild);
				temp2->bal=maxNumber(temp2->lchild)-maxNumber(temp2->rchild);
				
			}
			
			else if(num<temp1->num){
				node *temp2=((temp1)->lchild);
				
				int swap=temp->num;
				temp->num=(temp2)->num;
				(temp2)->num=swap;

				temp1->lchild=temp2->rchild;
				temp2->rchild=temp2->lchild;
				temp2->lchild=temp->lchild;
				temp->lchild=temp2;
				
				(*header)->bal=maxNumber(temp->lchild)-maxNumber(temp->rchild);
				temp1->bal=maxNumber(temp1->lchild)-maxNumber(temp1->rchild);
				temp2->bal=maxNumber(temp2->lchild)-maxNumber(temp2->rchild);
				
			}
		}
		
		else if(num<(*header)->num){
			node *temp1=((*header)->lchild);
			if(num<temp1->num){
				node *temp2=((temp1)->lchild);
				
				int swap=temp->num;
				temp->num=(temp1)->num;
				(temp1)->num=swap;
				
				temp->lchild=temp2;
				temp1->lchild=temp1->rchild;
				temp1->rchild=temp->rchild;
				temp->rchild=temp1;
				
				(*header)->bal=maxNumber(temp->lchild)-maxNumber(temp->rchild);
				temp1->bal=maxNumber(temp1->lchild)-maxNumber(temp1->rchild);
				temp2->bal=maxNumber(temp2->lchild)-maxNumber(temp2->rchild);
				
			}
			
			else if(num>temp1->num){
				node *temp2=((temp1)->rchild);
				
				int swap=temp->num;
				temp->num=(temp2)->num;
				(temp2)->num=swap;

				temp1->rchild=temp2->lchild;
				temp2->lchild=temp2->rchild;
				temp2->rchild=temp->rchild;
				temp->rchild=temp2;
				
				(*header)->bal=maxNumber(temp->lchild)-maxNumber(temp->rchild);
				temp1->bal=maxNumber(temp1->lchild)-maxNumber(temp1->rchild);
				temp2->bal=maxNumber(temp2->lchild)-maxNumber(temp2->rchild);
				
			}
		}
		
		//balCal(header,num);
	}
	
	
	
}


void insert(node **header,int num){
	
	if((*header)==NULL){
		(*header)=getNode();
		(*header)->num=num;
		return;
	}
	
	node *temp=*header;
	node *prev=temp;
	while(temp!=NULL){
		prev=temp;
		if(num>temp->num){
			temp=temp->rchild;
		}
		else {
			temp=temp->lchild;
		}
	}
	if(num>prev->num){
		prev->rchild=getNode();
		prev=prev->rchild;
		prev->num=num;
	}
	else{
		prev->lchild=getNode();
		prev=prev->lchild;
		prev->num=num;
	}
	
	balCal(header,num);
	
}



void main(){
	node *header=NULL;
	int n=1,num;
	
	while(n){
		printf("\nEnter\n1 for insert\n2 for display: ");
		scanf(" %d",&n);
		switch(n){
			case 1:
					printf("\nEnter the number: ");
					scanf(" %d",&num);
					insert(&header,num);
					break;
			case 2:
					disp(header);
					break;
		}
	}
}