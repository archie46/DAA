#include<stdio.h>
#include<stdlib.h>
typedef struct set{
    int data;
    struct set* rep;
    struct set* next;
}set;
void printset(set* ptr){
    if(ptr==NULL){
        printf("Given Set Is Empty\n");
        return;
    }
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}
set* makeset(int data){
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
int findset(int n,set * a){
    set * temp = a;
   while(temp!=NULL){
       if(temp->data==n){
          return a->data;
       }
       temp=temp->next;
   }
   return 0;
}
int main(){
 set * a = makeset(1);
 set * b = makeset(2);
 set * c = makeset(3);
 set * d = makeset(4);
  a = unionset(a,&b);
  c = unionset(c,&d);
  a = unionset(a,&c);
 // printf("%d",a->next->data);
 printset(a);
   printset(b);
  printset(c);
  printset(d);
  printf("%d",findset(4,a));
    return 0;
}
