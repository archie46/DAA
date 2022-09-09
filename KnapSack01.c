#include<stdio.h>
// void print(int r,int c,int m[][c]){
// 	for(int i=0;i<r;i++){
// 		for(int j=0;j<c;j++){
// 			printf("%d ",m[i][j]);
// 		}
// 		printf("\n");
// 	}
// }
 void printArr(int size,int arr[]){
 	int i;
 	for (i = 0; i <size; i++){
 		printf("%d ", arr[i]);
 	}
 	printf("\n");
 }
void knapsack(int n,int w,int we[],int v[]){
    int p[n+1][w+1];
    for(int i=0;i<w+1;i++){
           p[0][i]=0;
    }
    for(int i=0;i<n+1;i++){
           p[i][0]=0;
    }
  //  print(n+1,w+1,p);
    for(int i=1;i<n+1;i++){
            int p1=0,p2=0;
        for(int j=1;j<w+1;j++){
            if((i-1)>=0 && j>=0)
                p1 = p[i-1][j];
            if((i-1)>=0 && (j-we[i-1])>=0)
               p2 = v[i-1]+p[i-1][j-we[i-1]];
            p[i][j]= p1>p2 ? p1 : p2;
        }
    }
  //  print(n+1,w+1,p);
      int sum = 0;
printf("Picked items\n");
    for(int i=n;i>0;i--){
        if(p[i][w] != p[i-1][w] && (w-sum)>=we[i-1] ){
                       sum+=we[i-1];
                       printf("Item %d : %d\n",i,we[i-1]);
        }
    }

    printf("Total Weight : %d\n",sum);
    printf("Total Value : %d",p[n][w]);
   // printArr(n,arr);
}
int main(){
    int n;
    printf("Enter The Number Of Items : ");
    scanf("%d",&n);
    int w;
    printf("Enter Bag Capacity : ");
    scanf("%d",&w);
    int weights[n],values[n];
    printf("Enter The Weights : ");
    for(int i=0;i<n;i++){
      scanf("%d",&weights[i]);
    }
    printf("Enter The Values : ");
    for(int i=0;i<n;i++){
        scanf("%d",&values[i]);
    }
    knapsack(n,w,weights,values);
    return 0;
}
