#include<stdio.h>
int isSafe(int r,int c,int n,int arr[][n]){
	for(int i =0;i<r;i++){
		if(arr[i][c]==1)
		   return 0;
	}
	int i = r;
	int j = c;
	while(i>=0 && j>=0){
		if(arr[i][j]==1)
			return 0;
	  i--;
	  j--;
	}
	i = r;
	j = c;
	while(i>=0 && j<n){
		if(arr[i][j]==1)
			return 0;
	  i--;
	  j++;
	}
	return 1;
}
int nQueen(int r,int n,int arr[][n]){
	if(r>=n){
		return 1;
	}
	for(int i=0;i<n;i++){
		if(isSafe(r,i,n,arr)){
			arr[r][i]=1;
			
			if(nQueen(r+1,n,arr)){
				return 1;
			}
			arr[r][i]=0;
		}
	}
	return 0;
}
int main(){
	int n;
	printf("Enter The Size Of ChessBoard :");
	scanf("%d",&n);
	int arr[n][n];
	for(int i =0;i<n;i++){
		for(int j =0;j<n;j++){
			arr[i][j]=0;
		}
	}
	if(nQueen(0,n,arr)){
	for(int i =0;i<n;i++){
		for(int j =0;j<n;j++){
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
	}
	return 0;
}
