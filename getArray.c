#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int frequency[256];
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
    int i;
    char x[]="ILoveYou";
    int n = getNum(x);
 //   printf("%d",n);
    char arr[n];
    int fre[n];
    getArray(arr,fre,n);
    for(i=0;i<n;i++){
        printf("%c %d\n",arr[i],fre[i]);
    }
    return 0;
}