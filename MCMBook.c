#include<stdio.h>
#include<limits.h>
void print(int r,int c,int m[][c]){
	int i,j;
	for(i=0;i<r;i++){
		for(j=0;j<r;j++){
			printf("%10d ",m[i][j]);
		}
		printf("\n");
	}
}
void brackets(int i,int j,int n,int km[][n]){
	 if(j>i){
	printf("( ");
	brackets(i,km[i][j],n,km);
	brackets(km[i][j]+ 1,j,n,km);
	printf(" )");
	 	 return;
	 }
	 else{
	printf("%d ",i);
     return;
	 }

}
void mcm(int d[],int n){
	int c[n][n];
	int km[n][n];
	int i,j,k,l,temp=0;
	for(i=1;i<n;i++){
        c[i][i]=0;
        km[i][i]=0;
	}
    for(l=2;l<n;l++){
    	for(i=1;i<(n-l+1);i++){
    		j=i+l-1;
    		c[i][j]=INT_MAX;
       for(k=i;k<=j-1;k++){
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
	int n,i;
	scanf("%d",&n);
	int arr[n+1];
	printf("Enter The Dimensions :");
	for(i=0;i<=n;i++){
		scanf("%d",&arr[i]);
	}
	mcm(arr,n+1);
	return 0;
}
