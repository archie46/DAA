#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int getMin(int n,int a[],int arr[]){
         int min=INT_MAX,index;
     for(int i=0;i<n;i++){
           if(min>a[i] && arr[i]==0){
                min=a[i];
                index=i;
           }
     }
     return index;
}
void printMST(int n,int parent[],int graph[][n])
{
    printf("Edge \tWeight\n");
    for (int i = 1; i < n; i++)
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
}
void prims(int n,int graph[][n]){
	int parent[n];
	int key[n];
	int mstSet[n];
	for(int i=0;i<n;i++){
		key[i]=INT_MAX;
		mstSet[i]=0;
	}
	key[0]=0;
	parent[0]=-1;
	for(int i=0;i<n-1;i++){
		int u = getMin(n,key,mstSet);
		mstSet[u]=1;
		for(int v =0;v<n;v++){
			 if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]){
			 	key[v] = graph[u][v];
			 	parent[v] = u;
			 }
                 
    }
		}
		printMST(n,parent,graph);
	}

int main(){
	int n;
	printf("Enter The Number Of Vertices:");
	scanf("%d",&n);
	printf("Enter The Adjacency Matrix :\n");
	int graph[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&graph[i][j]);
		}
	}
    prims(n,graph);
	return 0;
}
