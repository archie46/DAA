#include<stdio.h>
void linearsearch(int a[],int l){
int n;
printf("Enter The Element You Want To Search For: ");
scanf("%d",&n);
for(int i=0;i<l;i++){
	if(a[i]==n){
		printf("Target Found at Index %d",i);
		return;
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
 linearsearch(arr,n);
	return 0;
}
