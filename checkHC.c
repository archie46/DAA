#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
    char character;
    int frequency; 
    struct node* left;
    struct node* right;
}node;
typedef struct heap{
    int size;
    int capacity;
    node** array;
}heap;
heap* huff;
node* root;
int frequency[256];
node* createNode(char a,int f){
    node* newNode=(node*)malloc(sizeof(node));
    newNode->character=a;
    newNode->frequency=f;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
void insert(heap* h,node* left,node * right,char data,int fre){
    node* newNode = (node*)malloc(sizeof(node));
     newNode->character=data;
     newNode->frequency=fre;
     newNode->left=left;
     newNode->right=right;
      h->size++;
    int i = h->size - 1;
  
    while (i && newNode->frequency < h->array[(i - 1) / 2]->frequency) {
        h->array[i] = h->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    h->array[i] = newNode;
}
void heapify(int i,heap* h){
     node* c;
  int smallest =i;
  if(2*i+1<h->size && h->array[2*i+1]->frequency < h->array[smallest]->frequency)
  	   smallest = 2*i+1;
  if(2*i+2<h->size && h->array [2*i+2]->frequency < h->array[smallest]->frequency)
       smallest = 2*i+2;
  if(smallest!=i){
  	    c = h->array[smallest];
		h->array[smallest] = h->array[i];
		h->array[i] = c;
		heapify(smallest,h);
  }
}
node* getMin(heap* he){
    node* c = he->array[0];
//printf("%c %d\n",c->character,c->frequency);
    he->array[0]=he->array[he->size-1];
    he->size--;
    heapify(0,he);
    return c;
}
heap* createHeap(char a[],int f[],int n){
    int i;
    heap* new =(heap*)malloc(sizeof(heap));
    new->size=0;
    new->capacity=n;
    new->array=(node**)malloc(n*sizeof(node));
    for(i=0;i<n;i++){
        new->array[i]=createNode(a[i],f[i]);
    }
    new->size=n;
    for(i=new->size-2-1;i>=0;i--){
             heapify(i,new);
    }
    return new;
}
void buildHuff(char a[],int f[],int n){
    huff = createHeap(a,f,n);
    int i;
    node* left;
    node* right;
    // for(int i=0;i<n;i++){
    //     printf("%c %d\n",huff->array[i]->character,huff->array[i]->frequency);
    // }
     while(huff->size>1){
           left=getMin(huff);
           right=getMin(huff);
        //    printf("\n%d %c\n",left->frequency,left->character);
        //    printf("\n%d %c\n",right->frequency,right->character);
        //    printf("Next");
        //  printf("%d\n",huff->size);
           insert(huff,left,right,'*',left->frequency+right->frequency);
     }
     root = getMin(huff);
}
// void pre(node* root){
//     if(root!=NULL){
//         printf(" %c %d \n",root->character,root->frequency);
//         pre(root->left);
//         pre(root->right);
//     }
// }
void print(int n,int arr[]){
    int i;
	printf("      ");
    for(i=0;i<n;i++){
        printf("%d",arr[i]);
    }
    printf("\n");
}
void printCodes(node* root,int arr[],int top){
    if(root->left){
        arr[top]=0;
        printCodes(root->left,arr,top+1);
    }
    if(root->right){
        arr[top]=1;
        printCodes(root->right,arr,top+1);
    }
    if(root->left==NULL && root->right==NULL){
        printf("%3c %10d",root->character,root->frequency);
        print(top,arr);
    }
}
int getNum(char str[]){
int i,n=0;
    for(i=0;i<256;i++){
       frequency[i]=0;
    }
    for(i=0;i<strlen(str);i++){
        frequency[str[i]]++;
    }

    for(i=0;i<256;i++){
          if(frequency[i]>0){
             // printf("%c %d\n",i,frequency[i]);
             n++;
          }
    }
    return n;
}
void getArray(char x[],int f[],int n){
    int i,j=0;
    for(i=0;i<256;i++){
    if(frequency[i]>0){
            x[j]=i;
            f[j]=frequency[i];
            j++; 
          }
    }
}
int main(){
    int i,size;
    printf("Enter The Length Of String:");
	scanf("%d",&size);
    char x[size];
	printf("Enter The String:");
	scanf("%s",x);
    int n = getNum(x);
	char arr[n];
    int freq[n];
    getArray(arr,freq,n);
    buildHuff(arr,freq,n); 
//  pre(root);
    int array[100];
	printf("Character Frequency Code\n");
    printCodes(root,array,0);
    return 0;
}