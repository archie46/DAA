#include<stdio.h>
#include<string.h>
// Upper is u
// Diagonal is d
// Left is l
// Nothing is n
void printchar(int r,int c,char matrix[][c]){
	int i,j;
	for (i=0;i<r;i++){
    for (j=0;j<c;j++){
       printf("%c ",matrix[i][j]);
      }
           printf("\n");
}
     printf("\n");
}
void print(int r,int c,int matrix[][c]){
	int i,j;
	for (i=0;i<r;i++){
    for (j=0;j<c;j++){
       printf("%d ",matrix[i][j]);
      }
           printf("\n");
}
     printf("\n");
}
void printlcs(int m,int n,char matrix[m][n],char a[],int i,int j){
  if(i==0||j==0)
     return;
    if(matrix[i][j]=='d'){
      printlcs(m,n,matrix,a,i-1,j-1);
      printf("%c ",a[i-1]);
    }
    else if(matrix[i][j]=='u')
      printlcs(m,n,matrix,a,i-1,j);
    else
      printlcs(m,n,matrix,a,i,j-1);
}
void lcs(char a[],char b[]){
    int c[strlen(a)+1][strlen(b)+1];
    char d[strlen(a)+1][strlen(b)+1];
    int i,j;
    for(i=0;i<=strlen(a);i++){
       c[i][0]=0;
       d[i][0]='n';
    }
    for(j=0;j<=strlen(b);j++){
       c[0][j]=0;
       d[0][j]='n';
    }
    for(i=1;i<=strlen(a);i++){
      for(j=1;j<=strlen(b);j++){
            if(a[i-1]==b[j-1]){
               c[i][j]=c[i-1][j-1]+1;
               d[i][j]='d';
            }
         else if(c[i-1][j]>=c[i][j-1]){
           c[i][j]=c[i-1][j];
           d[i][j]='u';
         }
         else{
           c[i][j]=c[i][j-1];
           d[i][j]='l';
         }
      }
    }
printlcs(strlen(a)+1,strlen(b)+1,d,a,strlen(a),strlen(b));
}
int main(){
	int m,n;
	printf("Enter Length Of First String:");
	scanf("%d",&m);
	  char x[m];
	printf("Enter First String :");
	scanf("%s",x);
	printf("Enter Length Of Second String:");
	scanf("%d",&n);
	  char y[n];
	printf("Enter Second String :");
	scanf("%s",y);
	printf("Longest Common Subsequence is ");
  lcs(x,y);
  return 0;
}
