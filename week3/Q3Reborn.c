#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void bubble(int* arr,int n){
int i,j;
for(i=0;i<n;i++)
for(j=0;j<n-i-1;j++)
if(arr[j]>arr[j+1]){
int temp=arr[j];
arr[j]=arr[j+1];
arr[j+1]=temp;
}
}
void my_func(int* arr,int n){
int i;
 bubble(arr,n);
    int set1[25],set2[25];
    int j=0,k=0;
    int sum1=0,sum2=0;

    for(i=n-1;i>=0;i--)
    if(sum1<=sum2){
    sum1+=arr[i];
    set1[j++]=arr[i];
    }
    else{
    sum2+=arr[i];
    set2[k++]=arr[i];
    }
    if(sum1!=sum2)
    printf("Cannot Split");
    else{
    printf("\n.....case.......\n");
    for(j=j-1;j>=0;j--)
    printf("%d\t",set1[j]);
    printf("\n");
    for(j=k-1;j>=0;j--)
    printf("%d\t",set2[j]);
    printf("\n.............\n");
        }


}
void combination(int* arr, int n){
int j,i,k=0;
int sol[20];
for(j=0;j<pow(2,n);j++){
int temp=j;
k=0;
for(i=0;i<n;i++){
if(temp%2==0){
temp=temp/2;
continue;}
sol[k++]=arr[i];
temp=temp/2;
}
my_func(sol,k);
}

}
int main()
{
    int n,i;
    printf("enter number of elements");
    scanf("%d",&n);
    int* arr=(int*)calloc(sizeof(int),n);
    for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
    combination(arr,n);


    return 0;
}

