#include<stdio.h>
// void printArr(float arr[],int n){
//     	int i;
// 	for(i=0;i<n;i++){
// 		  printf("%f ",arr[i]);
// 	}	
// 	printf("\n");
// }
// void print(float a1[],float a2[],float a3[],int n){
// 	int i;
// 	for(i=0;i<n;i++){
// 		  printf("%f ",a3[i]);
// 	}
// 	printf("\n");
// 	for(i=0;i<n;i++){
// 		  printf("%f ",a1[i]);
// 	}
// 	printf("\n");
// 		for(i=0;i<n;i++){
// 		  printf("%f ",a2[i]);
// 	}
// 	printf("\n");
// }
void bubblesort(float p[],float w[],int n){
	int i,j;
	  for(i=0;i<n-1;i++){
	  	  for(j=0;j<n-i-1;j++){
	  	  	  if((p[j]/w[j])<(p[j+1]/w[j+1])){
//	  	  	  	printf("%d %d\n",(p[j]/w[j]),(p[j+1]/w[j+1]));
	  	  	  	  int c =p[j];
	  	  	  	  p[j]  =p[j+1];
	  	  	  	  p[j+1]=c;
	  	  	  	  int e =w[j];
	  	  	  	  w[j]  =w[j+1];
	  	  	  	  w[j+1]=e;
									}
						}
			}
}
void total(float arr[],float p[],float w[],int n){
	int i;
	float sum=0;
	for(i=0;i<n;i++){
	  sum+=arr[i]*w[i];	
	}
	printf("Total Weight = %f\n",sum);
	sum=0;
		for(i=0;i<n;i++){
	  sum+=arr[i]*p[i];	
	}
	printf("Total Profit = %f\n",sum);
}
void knapsack(float p[],float w[],int n,int b){
	int bag =0;
	int i=0,k;
	float arr[n];
   for(i=0;i<n && b-bag>0;i++){
//		printf("%f %f\n",p[i]/w[i],b-bag);
		if(w[i]<(b-bag)){
			bag+=w[i];
			arr[i]=1;
		}
		else {
//			printf("Case");
			   int ratio=0;
//			   printf("%f\n",p[i]/w[i]);
             while(bag!=b){
             	bag+=(p[i]/w[i]);
 //            			printf("%d \n",bag);
             	ratio++;
			 }
//			 printf("%d %d",ratio,w[i]);
          arr[i]= ratio/w[i];
		}

//		printf("%d \n",bag);
//    k=i;
	}
	for(;i<n;i++){
		arr[i]=0;
	}
//	printArr(arr,n);
    total(arr,p,w,n);
}
int main(){
	int n,bag,i;
	printf("Enter Number Of Objects :");
	scanf("%d",&n);
	float profits[n],weights[n];
	printf("Enter Profit Of Objects :");
	for(i=0;i<n;i++){
	//	objects[i]=i+1;
		scanf("%f",&profits[i]);
	}
		printf("Enter Weight Of Objects :");
	for(i=0;i<n;i++){
		scanf("%f",&weights[i]);
	}
	printf("Enter Bag Capacity :");
    scanf("%d",&bag);
// float     objects[]={1,2,3,4,5,6,7};
//    float  profits[]={10,5,15,7,6,18,3};
//     float weights[]={2,3,5,7,1,4,1};
//	print(profits,weights,objects,3);
	bubblesort(profits,weights,n);
//	print(profits,weights,objects,n);
	knapsack(profits,weights,n,bag);
	return 0;
}
