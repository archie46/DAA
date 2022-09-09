#include<stdio.h>
typedef struct edge{
    char u;
    char v;
    int weight;
}edge;
edge** array;
void bubblesort(edge a[],int n){
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(a[j].weight>a[j+1].weight){
				edge c = a[j];
				    a[j] = a[j+1];
				    a[j+1] = c;
			}
		}
	}
}
edge* makeSet(edge a){
    edge* newEdge= malloc(sizeof(edge));
    newEdge->u=a.u;
    newEdge->v=a.v;
    newEdge->u=a.u;
    return newEdge;
}
void kruskal(edge arr[],int n){
   for(int i=0;i<n;i++){
         array[i]=newEdge(arr[i]);
   }
      for(int i=0;i<n;i++){
         printf("%c %c %d\n",arr[i].u,arr[i].v,arr[i].weight);;
   }
}
int main(){
    int n=7,e=12;
    // printf("Enter Number Of Vertices :");
    // scanf("%d",&n);
    // printf("Enter Number Of Edges :");
    // scanf("%d",&e); 
    edge arr[]={ {'A','B',5},
                 {'A','C',3},
                 {'B','D',6},
                 {'B','E',2},
                 {'B','C',4},
                 {'C','D',5},
                 {'C','F',6},
                 {'D','E',6},
                 {'D','F',6},
                 {'E','F',3},
                 {'E','G',4},
                 {'F','G',4} };
                 bubblesort(arr,e);
                 kruskal(arr,n);
// for(int i=0;i<e;i++){
    //     printf("%c %c %d\n",arr[i].u,arr[i].v,arr[i].weight);
    // }
    return 0;
}