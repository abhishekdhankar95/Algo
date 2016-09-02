#include<stdio.h>
#include<stdlib.h>



int isPrime(int num){
	int i=2;
	for(i=2;i<num;i++){
		if(num%i==0){
			return 0;
		}
	}
	return 1;
}

int fibo(int num){
	if(num==0)
		return 0;
	else if(num==1){
		return 1;
	}
	return fibo(num-1)+fibo(num-2);
}

void gcd(int a,int b){
	int min=((a<b)?a:b);
	int count=2,gcd=1;
	int countOuter=0,countInner=0;
	
	printf("\n***GCD of %d and %d is: ",a,b);
	while(count<=min){
		if(isPrime(count)){
			while(a%count==0 && b%count==0){
		
				gcd*=count;
				a/=count;
				b/=count;
				countInner++;
			}
		}
			countOuter++;
		count++;
	}
	
	
	printf("\nThe gcd is: %d\n",gcd);
	int maxCount=(countInner>countOuter)?countInner:countOuter;
	printf("\nThe max number of comparisions is: %d\n",maxCount);
}

void main(){
	int i;
	
   for(i=0;i<30;i+=2){
   		gcd(fibo(i),fibo(i+1));
   }
	
}
