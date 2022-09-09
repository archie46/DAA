#include<stdio.h>
#include<string.h>
int hash(int s,int e,char x[]){
	int sum=0;
	for(int i = s;i<=e;i++){
		sum+=(int)x[i];
	//	printf("%d ",sum);
	}
	return sum;
}
void rkarp(char x[],char y[]){
	int val = hash(0,strlen(y)-1,y);
//	printf("%d\n",val);
	int v = strlen(y)-1;
//	printf("%d\n",v);
	for(int i = 0;i<(strlen(x)-v);i++){
			int flag = 1;
		int h = hash(i,i+v,x);
	//	printf("%d ",h);
		if(h==val){
		//	printf("hello");
			int si = 0;
			for(int j =i;j<i+strlen(y);j++){
			//	printf("\n%c %d %c %d\n",x[j],j,y[si],si);
				if(x[j]!=y[si]){
					flag = 0;
					break;
				}
				si++;
			}
			if(flag){
				printf("Pattern Found At Index %d\n",i);
			}
		}
	//	printf("\nend\n");
     //   printf("%d\n",i);
	}
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
//char x[]="AABAACAADAABAABA";
//char y[]="AABA";
	rkarp(x,y);
//	printf("%c",y[strlen(y)-1]);
	return 0;
}
