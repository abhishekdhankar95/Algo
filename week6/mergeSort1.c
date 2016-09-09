#include<stdlib.h>
#include<stdio.h>
#include<string.h>
void merge(int a[],int low,int mid,int high){
    int b[10];
    int i=low;
    int j=mid+1;
    int k=0;
    while(i<=mid && j<=high){
        if(a[i]>a[j])
            b[k++]=a[j++];
        else
            b[k++]=a[i++];
    }
    while(i<=mid)
        b[k++]=a[i++];
    while(j<=high)
        b[k++]=a[j++];
    for(i=0;i<k;i++)
        a[i+low]=b[i];
}
void mergesort(int* arr,int low,int high){
    if(low<high){
        int mid=(low+high)/2;
        mergesort(arr,low,mid);
        mergesort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}
void main(){

    int n,i,j,temp;
    printf("Number of elements:");
    scanf("%d",&n);
    int *arr=(int*)calloc(sizeof(int),n);
    printf("Start:");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    mergesort(arr,0,n-1);
   
    for(i=0;i<n;i++)
        printf(" %d ",arr[i]);

}
