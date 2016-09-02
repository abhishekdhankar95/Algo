#include<stdio.h>
#include<stdlib.h>


int fibo(int num){
	if(num==0)
		return 0;
	else if(num==1){
		return 1;
	}
	return fibo(num-1)+fibo(num-2);
}

void gcdEuclid(int a,int b){
	int rem,n,temp,count=1;
	if(a>b){
		rem=a;
		n=b;
	}
	else{
		rem=b;
		n=a;
	}
		
	while(n){
		rem%=n;
		temp=n;
		n=rem;
		rem=temp;
		count++;
	}
	printf("\n*** GCD of %d and %d ***",a,b);
	printf("\nThe gcd is: %d\n",rem);
	printf("\nThe number of comparisions is: %d\n",count);
}

void main(){
	int i;
	for(i=0;i<30;i+=2){
		gcdEuclid(fibo(i),fibo(i+1));
	}
}
