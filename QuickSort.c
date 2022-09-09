#include<stdio.h>
#include<stdlib.h>
void print(int n, int a[]){
	int i;
	for (i = 0; i < n; i++)	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
int partition(int low,int high,int a[]){
    int i=low+1;
    int j=high;
    int pivot=a[low];
    do{
        while(a[i]<=pivot && i<j )
            i++;
        while(a[j]>pivot)
            j--;
        if(j>i){
        	int c = a[j];
        	a[j] = a[i];
        	a[i] =c ;
		}
    }while(j>i);
    int c = a[j];
    a[j] = a[low];
    a[low] =c ;
    return j;
}
void quicksort(int a[],int i,int j)
{
    if(i>=j)
        return;
    int p;
    if(i<j){
       p=partition(i,j,a);
    }
    quicksort(a,i,p-1);
    quicksort(a,p+1,j);
}
int main(){
printf("Enter The Size Of Array :");
 int n,i;
 scanf("%d",&n);
  int a[n];
 printf("Enter The Elements Of Array :\n");
 for(i=0;i<n;i++){
 	scanf("%d",&a[i]);
 }
 quicksort(a,0,n-1);
 print(n,a);
 return 0;
}
