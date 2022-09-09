#include<stdio.h>
#define INF 999
void print(int n,int m[][n]){
     for(int i=0;i<n;i++){
          for(int j=0;j<n;j++){
               printf("%10d ",m[i][j]);
          }
          printf("\n");
     }
}
void printArr(int n, int a[]){
	for (int i = 0; i < n; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
}
int getMin(int n,int a[],int arr[]){
         int min=INF,index;
       //  printf("%d",INF);
     for(int i=0;i<n;i++){
           if(min>a[i] && arr[i]==0){
                min=a[i];
                index=i;
           }
     }
  //   printf("min = %d\n",min);
     return index;
}
void repath(int arr[],int end){
	if(arr[end]!=-1){
		repath(arr,arr[end]);
		printf("%d->",arr[end]+1);
	 //  place(arr[end]+1);
	//   printf("->");
	}
	else
	return;
}
void dij(int start,int end,int n,int graph[][n]){
     int a[n];   // Distance Array
     int arr[n];   // Path Array
     int array[n];   //Parent Array
     array[0]=-1;
     for(int i=start;i<n;i++){
          if(i==start)
              a[i]=0;
          else
              a[i]=INF;
          arr[i]=0;
     }
     // printNum(15);
     // printArr(15,a);
    //  printArr(15,arr);
    //  printArr(15,array);
    for(int i=start;i<n-1;i++){
         int spoint = getMin(n,a,arr);
      //   printf("\ns = %d\n",spoint);
         arr[spoint]=1;
         for(int j=0;j<n;j++){
            //  printf("\np = %d\n",graph[spoint][j]);
              if(!arr[j] && graph[spoint][j] && a[spoint]!=INF && (a[spoint]+graph[spoint][j])<a[j]){
                   a[j]=graph[spoint][j] + a[spoint];
                   array[j]=spoint;
              }
         }
    //     printArr(n,a);
     //    printArr(6,arr);
    }
   // printArr(15,a);
   // printArr(15,arr);
    repath(array,end);
            printf("%d",end+1);
}
int main(){
	int n;
     printf("Enter The Size Of Adjacency Matrix :");
     scanf("%d",&n);
     int graph[n][n];
     printf("For Infinite Values ,Enter 999\n");
     printf("Enter The Matrix Below\n");
     for(int i=0;i<n;i++){
          for(int j=0;j<n;j++){
               scanf("%d",&graph[i][j]);
          }
     }
     int src,dest;
     printf("Enter Source :");
     scanf("%d",&src);
     printf("Enter Destination :");
     scanf("%d",&dest);
   // print(6,graph);
   printf("Shortest Path Is ");
   dij(src-1,dest-1,n,graph);
   return 0;
}
// 0 2 4 999 999 999
// 999 0 1 7 999 999
// 999 999 0 999 3 999
// 999 999 999 0 999 1
// 999 999 999 2 0 5
// 999 999 999 999 999 0