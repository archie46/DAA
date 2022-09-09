#include<stdio.h>
void print(int size,int arr[]){
	int i;
	for (i = 0; i <size; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void heapify(int i,int n,int arr[]){
  int largest =i;
  if(2*i+1<n && arr[2*i+1] > arr[largest])
  	   largest = 2*i+1;
  if(2*i+2<n && arr [2*i+2] > arr[largest])
       largest = 2*i+2;
  if(largest!=i){
  	    int c = arr[largest];
		arr[largest] = arr[i];
		arr[i] = c;
		heapify(largest,n,arr);
  }
}
void heapsort(int size,int arr[]){
      int i;
 for(i=size/2-1;i>=0;i--){
		heapify(i,size,arr);
	}
	for(i=size-1;i>=0;i--){
		int c = arr[0];
		arr[0] = arr[i];
		arr[i] = c;
		heapify(0,i,arr);
	}
}
int main(){
printf("Enter The Size Of Array :");
 int n,i;
 scanf("%d",&n);
  int arr[n];
 printf("Enter The Elements Of Array :\n");
 for(i=0;i<n;i++){
 	scanf("%d",&arr[i]);
 }
//        7 11 90 2 81 10 19 30 101 97 61
 //    print_heap(n,arr);
     heapsort(n,arr);
     print(n,arr);
	 return 0;
}
