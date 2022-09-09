#include<stdio.h>
void print(int a1[],int a2[],int a3[],int n){
	for(int i=0;i<n;i++){
		  printf("%d ",a3[i]);
	}
	printf("\n");
	for(int i=0;i<n;i++){
		  printf("%d ",a1[i]);
	}
	printf("\n");
		for(int i=0;i<n;i++){
		  printf("%d ",a2[i]);
	}
	printf("\n");
}
void bubblesort(int a1[],int a2[],int a3[],int n){
	  for(int i=0;i<n-1;i++){
	  	  for(int j=0;j<n-i-1;j++){
	  	  	  if(a2[j]>a2[j+1]){
	  	  	  	  int c =a2[j];
	  	  	  	  a2[j]  =a2[j+1];
	  	  	  	  a2[j+1]=c;
	  	  	  	  int d =a1[j];
	  	  	  	  a1[j]  =a1[j+1];
	  	  	  	  a1[j+1]=d;
	  	  	  	  int e =a3[j];
	  	  	  	  a3[j]  =a3[j+1];
	  	  	  	  a3[j+1]=e;
									}
						}
			}
}
void asp(int a1[],int a2[],int a3[],int n){
     int i=0;
     printf("%d ",a3[0]);
    for(int j=1;j<n;j++){
    	if(a2[i]<=a1[j]){
    		printf("%d ",a3[j]);
    		i=j;
		}
	}
}
int main(){
	int n;
	printf("Enter Number Of Activities :");
	scanf("%d",&n);
	int arr1[n],arr2[n],arr[n];
	printf("Enter Starting Time Of Activities :\n");
	for(int i=0;i<n;i++){
		 arr[i]=i+1;
		 scanf("%d",&arr1[i]);
	}
	printf("Enter Ending Time Of Activities :\n");
		for(int i=0;i<n;i++){
		 scanf("%d",&arr2[i]);
	}
    printf("The Activities With Start and Finish Time:\n");
	print(arr1,arr2,arr,n);
	bubblesort(arr1,arr2,arr,n);
	printf("The Activities In Sorted Order:\n");
	print(arr1,arr2,arr,n);
	printf("Order Of Activities:\n");
	asp(arr1,arr2,arr,n);
	return 0;
}
