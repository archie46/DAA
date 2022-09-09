#include<stdio.h>
#include<stdlib.h>
typedef struct set{
    char data;
    struct set* rep;
    struct set* next;
}set;
typedef struct edge{
    char u;
        char v;
    int weight;
}edge;
    edge** array;
void bubblesort(edge a[],int n){
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(a[j].weight>a[j+1].weight){
				edge c = a[j];
				    a[j] = a[j+1];
				    a[j+1] = c;
			}
		}
	}
};

void printset(set* ptr){
    if(ptr==NULL){
        printf("Given Set Is Empty\n");
        return;
    }
    while(ptr!=NULL){
        printf("%c ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}
set* makeset(char data){
    set* new = malloc(sizeof(set));
    new->next = NULL;
    new->rep = new;
    new->data = data;
    return new;
}
set* unionset(set * x,set** y){
    set* temp =x;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=*(y);
    temp=*(y);
    while(temp!=NULL){
        temp->rep=x;
        temp=temp->next;
    }
  //  printf("%d\n",*(y)->->data);
//    while(*(y)!=NULL){
//    //	printf("F ");
//        set * p = *y;
//       // set * next = * (y->next) ;
//    	y=y->next; 
//    //	free(p);
//	}
	*y=NULL;
//	free(p);
    return  x;
}
char findset(char n,set ** a){
	for(int i=0;i<)
    set * temp = a;
   while(temp!=NULL){
       if(temp->data==n){
          return a->data;
       }
       temp=temp->next;
   }
   return '*';
}
set** arr;
void kruskal(edge ar[],int e,int n,char v[]){
  //  set * a;
  array = malloc(n*sizeof(edge));
     arr = malloc(n*sizeof(set));
    for(int i=0;i<n;i++){
       arr[i]=makeset(v[i]);
     //  printset(arr[i]);
    }
//    
    for(int i=0;i<e;i++){
    	if(findset(ar[i].u,arr)!=findset(ar[i].v,arr)){
    		
		}
	}

}
int main(){
    int n=7,e=12;
    char v[] ="ABCDEFG";
    edge arr[]={ {'A','B',5},
                 {'A','C',3},
                 {'B','D',6},
                 {'B','E',2},
                 {'B','C',4},
                 {'C','D',5},
                 {'C','F',6},
                 {'D','E',6},
                 {'D','F',6},
                 {'E','F',3},
                 {'E','G',4},
                 {'F','G',4} };
                 bubblesort(arr,e);
                 kruskal(arr,12,7,v);
    return 0;
}
