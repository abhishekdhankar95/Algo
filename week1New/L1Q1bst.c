
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct st{
struct st *lchild,*rchild;
char data;}node;

node *getNode(){
    node *newNode=malloc(sizeof(node *));
    newNode->lchild=NULL;
    newNode->rchild=NULL;
    return newNode;
}

void insert(node **header,char data){
    node *temp=*header,*prev=*header;
    if(*header==NULL){
        *header=getNode();
        (*header)->data=data;
        printf("\nEntered in root\n");
        return;
    }
    while(temp){
    prev=temp;
        if(data==temp->data){
            printf("\nKey Found\n");
            return;
        }
        else if(data>temp->data)
            temp=temp->rchild;
        else if(data<temp->data){
            temp=temp->lchild;
        }
    }
    if(data>prev->data){
        prev->rchild=getNode();
        (prev->rchild)->data=data;
    }
    else if(data<prev->data){
        prev->lchild=getNode();
        (prev->lchild)->data=data;
    }

    printf("\nInserted\n");
}

void inDisp(node *header){
    if(header==NULL){
        return;
    }
    inDisp(header->lchild);
    printf(" %c ",header->data);
    inDisp(header->rchild);
}

void preDisp(node *header){
    if(header==NULL){
        return;
    }
     printf(" %c ",header->data);
    preDisp(header->lchild);

    preDisp(header->rchild);
}

void postDisp(node *header){
    if(header==NULL){
        return;
    }

    postDisp(header->lchild);

    postDisp(header->rchild);
    printf(" %c ",header->data);
}

void main(){
int n=1;
char data;
node *header=NULL;
while(n!=0){
    printf("\nEnter\n1 for insert or search\n2 for display\n0 for exit: \n");
    scanf(" %d",&n);
    switch(n){
        case 1:
                printf("\nEnter the data: ");
                scanf(" %c",&data);
                insert(&header,data);
                break;
        case 2:
                printf("\nInorder: \n");
                inDisp(header);
                printf("\nPreorder: \n");
                preDisp(header);
                printf("\nPostorder: \n");
                postDisp(header);
                break;
    }
}
}
