#include<stdio.h>
void bubblesort(int a[],int n){
	for(int i=0;i<n-1;i++){
		for(int j =0;j<n-i-1;j++){
			if(a[j]>a[j+1]){
				int c = a[j];
				    a[j] = a[j+1];
				    a[j+1] = c;
			}
		}
	}
}
void binarysearch(int a[],int n){
		bubblesort(a,n);
	int target;
	printf("Enter Item To Search : ");
	scanf("%d",&target);
	int first = 0;
	int last  = n-1;
	while(first<=last){
		int mid = (first + last) / 2;
		if(a[mid]==target){
			printf("Target Found at %d",mid);
			return;
		}
		if(a[mid]<target){
			first = mid+1;
		}
		if(a[mid]>target){
		     last = mid-1;	
		}
	}
	printf("Target Not Found");
}

int main(){
printf("Enter The Size Of Array :");
 int n;
 scanf("%d",&n);
  int arr[n];
 printf("Enter The Elements Of Array :\n");
 for(int i=0;i<n;i++){
 	scanf("%d",&arr[i]);
 }
	binarysearch(arr,n);
	return 0;
}
