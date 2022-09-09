#include<stdio.h>
#include<stdlib.h>
typedef struct huffd{
    char character;
    int frequency;
}huffd;
typedef struct node{
    huffd data; 
    struct node* left;
    struct node* right;
}node;
node* root =NULL;
void bubblesort(node a[],int start,int end){
	int i, count;
//    printf("%d %d\n",start,end);
	do{
		count = 0;
		for (i = start; i < (end - 1); i++)
		{
			if (a[i].data.frequency > a[i + 1].data.frequency)
			{
				node c = a[i];
				    a[i] = a[i+1];
				    a[i+1] = c;
				count++;
			}
		}
	}while (count > 0);
}
 void print(node a[],int start,int end){
     int i;
     for(i=start;i<end;i++){
         printf("%c %d\n",a[i].data.character,a[i].data.frequency);
     }
     printf("\n");
 }
  node findmin(int start,int length,node arr[]){
      int i;
      node min = arr[start];
      for(i=start+1;i<length;i++){
          if(min.data.frequency>arr[i].data.frequency){
//              printf("%d>%d\n",min.data.frequency,arr[i].data.frequency);
                min = arr[i];
          }
      }
      return min;
  }
  node insert(node a,node b){
      node new;
      new.data.frequency=a.data.frequency+b.data.frequency;
      new.data.character='z';
      new.left=&a;
      new.right=&b;
      return new;
  }
 void buildhuff(huffd arr[],int n,node a[]){
     int i;
        for(i=0;i<n;i++){
            a[i].data=arr[i];
            a[i].left=NULL;
            a[i].right=NULL;
        }
       i*=2;
 //             printf("%d %d",i,n);
    //   node* as =malloc(n*sizeof(node));
       int start=0;
       int lo =0;
        while(i>n){
//            print(a,n+lo);
        //    node temp1=findmin(start,n+lo,a);
            node temp1=a[start];
        //    printf("%d ",temp1.data.frequency);
 //           node temp2=findmin(start+1,n+lo,a);
           node temp2=a[start+1];
//            printf("%d %d\n",start+1,n+lo);
        //   printf("%d\n",temp2.data.frequency);
            a[n+lo]=insert(temp1,temp2);
            start+=2;
                        lo++;
                        bubblesort(a,start,n+lo);
                       // print(a,start,n+lo);

            i--;
        }
        root=&a[start-2];
       // printf("%d",a[start-2].data.frequency);
 }
// void pre(node* root){
//     if(root!=NULL){
//         printf("%d ",(*root).data.frequency);
//         pre((*root).left);
//         pre((*root).right);
//     }
// }
int main(){
     huffd array[]={{'f',5},{'e',9},{'c',12},{'b',13},{'d',16},{'a',45}};
     int size =6;
     node arr[2*size];
     buildhuff(array,6,arr);
//     print(arr,6);
 //  printf("%d",findmin(6,arr).data.frequency);
    pre(root);
    return 0;
}