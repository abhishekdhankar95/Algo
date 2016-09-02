#include<stdio.h>
#include<stdlib.h>

void gcd(int a,int b){
int count=1;
	int min=(a<b)?a:b;
	if(a==0 || b==0)
		min=1;	
	
	while(min>0){
		if(a%min==0 && b%min==0)
			break;
		min--;
		count++;
	}
	printf("\n*** Gcd of %d and %d ***\n",a,b);
	printf("The gcd is: %d\n",min);
	printf("\nThe number of times that basic operation was executed: %d\n",count);
}

/*int fibo(int num){
	if(num==0)
		return 0;
	else if(num==1){
		return 1;
	}
	return fibo(num-1)+fibo(num-2);
}*/

void main(){
	
	//printf("\nEnter the first number: ");
	//scanf("%d",&a);
	//printf("\nEnter the second number: ");
	//scanf("%d",&b);
	
	int numbers[7][2];
	int i=0,j=0;
	for(i=0;i<7;i++){
		for(j=0;j<2;j++){
			printf("\nEnter number %d: \n",(j+1));
			scanf("%d",&numbers[i][j]);
		}
	}
	
	for(i=0;i<7;i++){
		gcd(numbers[i][0],numbers[i][1]);
	}
}
	
	

