#include<stdio.h>
    int n=0;
    int m[4][4]={
    {0,0,0,0},
    {0,0,0,0},
    {0,0,0,0},
    {0,0,0,0}};
    void print(){
    	for(int i=0;i<4;i++){
    		for(int j=0;j<4;j++){
    			printf("%d ",m[i][j]);
			}
			printf("\n");
		}
	}
void nq(int r,int c){
    int flag = 1;
    int b = 1;
    int e = 1;
    int d = 1;
    for(int i=0;i<4;i++){
        if(m[i][c]==1){
            b=0;
            break;
        }
    }
    for(int i=0;i<4;i++){
        if(m[r][i]==1){
            e=0;
            break;
        }
    }
    int i=r,j=c;
    while(i>=0 && j>=0){
          if(m[i][j]==1){
              d=0;
              break;
          }
          i--;
          j--;
    }
         i=r,j=c;
    while(i<4 && j<4){
          if(m[i][j]==1){
              d=0;
              break;
          }
          i++;
          j++;
    }
    if(b==1 && e ==1 && d==1){
        printf("Queen Is Placed At Row %d Column %d\n",r+1,c+1);
        m[r][c]=1;
        n++;
        print();
    }
    else
    printf("Queen Cannot Be Placed At Row %d Column %d\n",r+1,c+1);
    printf("%d %d %d\n",b,e,d);
}
int main(){
    int row,column;
  //  printf("Queen Is Placed At Row 1 and Column 1\n");
    do{
        printf("Enter Row :");
        scanf("%d",&row);
        printf("Enter Column :");
        scanf("%d",&column);
        nq(row-1,column-1);
    }while(n<4);
    return 0;
}
