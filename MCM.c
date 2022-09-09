#include<stdio.h>
#include<limits.h>
void print(int r,int c,int m[][c]){
	for(int i=0;i<r;i++){
		for(int j=0;j<r;j++){
			printf("%10d ",m[i][j]);
		}
		printf("\n");
	}
}
void brackets(int i,int j,int n,int km[][n]){
	 if(i==j){
	printf("%d ",i);
     return;
	 }
     printf("( ");
	 brackets(i,km[i][j],n,km);
	 brackets(km[i][j]+ 1,j,n,km);
	 printf(" )");
}
void mcm(int d[],int n){
	int c[n][n];
	int km[n][n];
	int j,temp=0;
	for(int i=1;i<n;i++){
        c[i][i]=0;
        km[i][i]=0;
	}
    for(int l=2;l<n;l++){
    	for(int i=1;i<(n-l+1);i++){
    		j=i+l-1;
    		c[i][j]=INT_MAX;
       for(int k=i;k<=j-1;k++){
       	   temp = c[i][k]+c[k+1][j] +(d[i-1]*d[k]*d[j]);
       	    if(temp<c[i][j]){
       	           	    c[i][j]=temp;
					    km[i][j]=k;
			   }
	   }
		}
	}
	printf("Minimum Number Of Calculations Required Is %d\n",c[1][n-1]);
	printf("The Order Of Multiplication Is ");
 brackets(1,n-1,n,km);
}
int main(){
	printf("Enter Number Of Matrices :");
	int n;
	scanf("%d",&n);
	int arr[n+1];
	printf("Enter The Dimensions :");
	for(int i=0;i<=n;i++){
		scanf("%d",&arr[i]);
	}
	mcm(arr,n+1);
	return 0;
}
