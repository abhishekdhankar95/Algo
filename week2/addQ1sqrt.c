
#include<stdio.h>
#include<stdlib.h>

float squareRoot(float n)
{
 
  float x = n;
  float y = 1;
  float e = 0.000001; 
  while(x - y > e)
  {
    x = (x + y)/2;
    y = n/x;
  }
  return x;
}

void main(){
	float num;
	printf("\nEnter the number: \n");
	scanf("%f",&num);
	float sqrt=squareRoot(num);
	printf("\nThe square root of %f is: %f\n",num,sqrt);
}
