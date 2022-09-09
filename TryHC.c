#include<stdio.h>
#include<stdlib.h>
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
node* findmin(heap* he){
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
void buildhuff(char a[],int f[],int n){
    huff = createHeap(a,f,n);
    int i;
    node* left;
    node* right;
    // for(int i=0;i<n;i++){
    //     printf("%c %d\n",huff->array[i]->character,huff->array[i]->frequency);
    // }
     while(huff->size>1){
           left=findmin(huff);
           right=findmin(huff);
        //    printf("\n%d %c\n",left->frequency,left->character);
        //    printf("\n%d %c\n",right->frequency,right->character);
        //    printf("Next");
        //  printf("%d\n",huff->size);
           insert(huff,left,right,'*',left->frequency+right->frequency);
     }
     root = findmin(huff);
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
        printf("%c :",root->character);
        print(top,arr);
    }
}
int main(){
    int i,n;
    printf("Enter The Number Of Characters :");
    scanf("%d",&n);
    char arr[n]; // = { 'f', 'e', 'c', 'b', 'd', 'a' };
    int freq[n];  // = { 5, 9, 12, 13, 16, 45 };
    printf("Enter Their Frquencies In Increasing Order :");
        for(i=0;i<n;i++){
        scanf("%d",&freq[i]);
    }
    printf("Enter The Characters In  Order :");
    for(i=0;i<n;i++){
        getchar();
        scanf("%c",&arr[i]);
    }
    buildhuff(arr,freq,n); 
//  pre(root);
    int array[100];
    printCodes(root,array,0);
    return 0;
}