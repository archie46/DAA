#include<stdio.h>
int k = 0;
void ssum(int arr[],int n,int target,int sum,int l){
    if(sum>target || n>l)
     return;
    if(sum==target ){
        k++;
        return;
    }  
    ssum(arr,n+1,target,arr[n]+sum,l);
    ssum(arr,n+1,target,sum,l);
}
int main(){
    int arr[] ={2,3,4,5};
     ssum(arr,0,9,0,4);
     printf("%d",k);
    return 0;
}