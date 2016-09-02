#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int count;

int searchPattern(char text[],char pattern[]){
	int i=0,j=0;
	count=0;
	while(i<strcspn(text,"\n")){
		int k=0;
		count++;
		while((i+k)<strcspn(text,"\n") && k<strcspn(pattern,"\n") && text[i+k]==pattern[k]){
			k++;
			count++;
			}
		
			if(k==strcspn(pattern,"\n")){
				return i;
			}
			i++;
	}
	return -1;
}

void main(){
	char text[100],pattern[100];
	printf("\nEnter the text: ");
	fgets(text,100,stdin);
	
	printf("\nEnter the pattern to be searched for: ");
	fgets(pattern,100,stdin);
	
	int start=searchPattern(text,pattern);
	
	int end=start+strcspn(pattern,"\n")-1;
	if(start!=-1){
		printf("\nThe pattern is found in the  from %d to %d\n",start,end);
	}
	else 
		printf("\nThe pattern is not present in the text!!!");
		
	printf("\nNumber of comparisons: %d",count);
}
