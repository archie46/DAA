#include <stdio.h>
#include <stdlib.h>
void print(int n, int a[]){
	int i;
	for (i = 0; i < n; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
}
void merge(int arr[],int l,int mid,int r){
	int b[r+1];
	int i=l;
	int j=mid+1;
	int k = l;
	while(i<=mid && j<=r){
		if(arr[i]<arr[j]){
			b[k]=arr[i];
			i++;
		}
		else{
			b[k]=arr[j];
			j++;
		}
		k++;
	}
	if(i>mid){
		while(j<=r){
			b[k]=arr[j];
			j++;
			k++;
		}
	}
	else{
		while(i<=mid){
			b[k]=arr[i];
			i++;
			k++;
		}
	}
	for(i=l;i<=r;i++){
		arr[i]=b[i];
	}
}
void mergesort(int a[],int l,int r){
	if(l<r){
		int mid = (l+r)/2;
		mergesort(a,l,mid);
		mergesort(a,mid+1,r);
		merge(a,l,mid,r);
	}
}
int main()
{
printf("Enter The Size Of Array :");
 int n,i;
 scanf("%d",&n);
  int arr[n];
 printf("Enter The Elements Of Array :\n");
 for(i=0;i<n;i++){
 	scanf("%d",&arr[i]);
 }
	printf("The Numbers In Ascending Order Are:\n");
//	int arr[]={234,54,12,76,11,87,32,12,45};
	mergesort(arr,0,n-1);
	print(n, arr);
	return 0;
}
