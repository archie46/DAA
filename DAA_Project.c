#include<stdio.h>
#include<stdlib.h>
#define INF 999
int graph[15][15] = {
{0, 1, 6, INF, INF, INF, INF, 5, INF, INF,INF, INF, INF, INF, INF},
{INF, 0, INF, INF, INF, INF, INF, 5, INF, INF,INF, 5, 8, INF, 9},
{6, INF, 0, 6, 8, INF, INF, 5, INF, INF, INF, INF, INF, 8,INF},
{INF, INF, 6, 0, 3, INF, INF, 5, INF, 7, INF, INF, INF,INF, INF},
{INF, INF, 8, 3, 0, 2, INF, INF, INF, 8, INF, INF, INF, 4,INF},
{INF, INF, INF, INF, 2, 0, 12, INF, INF, 9, INF, INF,INF, 5, INF},
{INF, INF, INF, INF, INF, 12, 0, INF, 4, 6, 5, INF, INF,INF, INF},
{5, 5, 5, 5, INF, INF, INF, 0, INF, 6, INF, 4, INF, INF,INF},
{INF, INF, INF, INF, INF, INF, 4, INF, 0, 5, 3, INF,INF, INF, 5},
{INF, INF, INF, 7, 8, 9, 6, 6, 5, 0, INF, 5, INF, INF, 8},
{INF, INF, INF, INF, INF, INF, 5, INF, 3, INF, 0,INF, INF, INF, 3},
{INF, 5, INF, INF, INF, INF, INF, 4, INF, 5, INF, 0,INF, INF, 6},
{INF, 8, INF, INF, INF, INF, INF, INF, INF, INF,INF, INF, 0, INF, 4},
{INF, INF, 8, INF, 4, 5, INF, INF, INF, INF, INF,INF, INF, 0, INF},
{INF, 9, INF, INF, INF, INF, INF, INF, 5, 8, 3, 6, 4, INF,0}} ;
void place(int place){
	switch (place) {
  	case 1: printf(" FRONT GATE ");
  	break;
  	case 2 : printf(" Accounts building ");
  	break;
  	case 3: printf(" Old apartment ");
  	break;
  	case 4 : printf(" OBH ");
  	break;
  	case 5 : printf (" Canteen ");
  	break;
  	case 6: printf(" NBH ");
  	break ;
  	case 7: printf(" Girl's Hostel ");
  	break ;
  	case 8 : printf(" DSW ");
  	break;
  	case 9 : printf(" CSE BUILDING ");
  	break;
  	case 10 : printf(" Mechanical Building ");
  	break;
  	case 11 : printf(" Electrical Building ");
  	break;
  	case 12 : printf(" Library ");
  	break;
  	case 13 : printf(" Backgate ");
  	break;
  	case 14 : printf(" Civil Building ");
  	break;
  	case 15 : printf(" Admission Cell ");
  	break ;
  }
}
int getMin(int n,int a[],int arr[]){
         int min=INF,index;
     for(int i=0;i<n;i++){
           if(min>a[i] && arr[i]==0){
                min=a[i];
                index=i;
           }
     }
     return index;
}
void repath(int arr[],int end){
	if(arr[end]!=-1 && arr[end]!=end ){
		repath(arr,arr[end]);
	   place(arr[end]+1);
	   printf(" -> ");
	}
}
void repathe(int arr[],int start,int end){
    int i = start;  
    int j = end;    
     while(arr[i]!=j && arr[i]!=-1){
         place(arr[i]+1);
         printf("->");
         i=arr[i];
     }
}

void dij(int start,int end,int n,int graph[][n]){
	int l=0,m=end;
	if(end>start){
		l=start;
		m=end;
	}
     int a[n];   // Distance Array
     int arr[n];   // Path Array
     int array[n];   //Parent Array
     array[0]=-1;
     for(int i=0;i<n;i++){
          if(i==l)
              a[i]=0;
          else
              a[i]=INF;
          arr[i]=0;
          array[i]=-1;
     }
    for(int i=l;i<n-1;i++){
         int spoint = getMin(n,a,arr);
         arr[spoint]=1;
         for(int j=0;j<n;j++){
              if(!arr[j] && graph[spoint][j] && a[spoint]!=INF && (a[spoint]+graph[spoint][j])<a[j]){
                   a[j]=graph[spoint][j] + a[spoint];
                   array[j]=spoint;
              }
         }
    }
    if(end>start){
    	repath(array,end-1);
	}
    else{
    	repathe(array,start,end-1);
	}
   place(end);
   printf("\n\n\t\t\t\t\t\tYou Reached!");
   printf("\n\n\t\t\t\t\t\tHave A Nice Day!");
}
void interface(){
    int place1, place2;
    do{
        printf("\n\n\n\n\n");
        printf("\t\t\t\t\t\t\t\t|| Let Us Find You A Short Path ||\n\n\n");

        printf("\t\t\t\t\tThe List of Places are:\n\n");
        printf("\t\t\t\t\t   1. Front Gate \n");
        printf("\t\t\t\t\t   2. Account Building \n");
        printf("\t\t\t\t\t   3. Old Apartment \n");
        printf("\t\t\t\t\t   4. OBH \n");
        printf("\t\t\t\t\t   5. Canteen \n");
        printf("\t\t\t\t\t   6. NBH \n");
        printf("\t\t\t\t\t   7. Girl's Hostel \n");
        printf("\t\t\t\t\t   8. DSW \n");
        printf("\t\t\t\t\t   9. CSE Building \n");
        printf("\t\t\t\t\t  10. Mechanical Building \n");
        printf("\t\t\t\t\t  11. Electrical Building \n");
        printf("\t\t\t\t\t  12. Library \n");
        printf("\t\t\t\t\t  13. BackGate \n");
        printf("\t\t\t\t\t  14. Civil Building \n");
        printf("\t\t\t\t\t  15. Admission Cell \n");

        printf("\n\n\t\t\t\t\t\tWhere you are Now: ");
        scanf("%d", &place1);

        printf("\n\t\t\t\t\t\tWhere do you Want to Go: ");
        scanf("%d", &place2);

        if((place1 <= 15 && place2 <= 15)){ // implement Dijikstra Here..
      
          printf("\n\t\t\t\t\t\tShortest Path to reach from '");
          place(place1);
          printf("' To '");
          place(place2);
          printf("' is:\n\t\t\t\t\t\t\t");// answer from Dijikstra..
          if(place1>place2){
          place(place1);
          printf(" -> ");
          }
          dij(place1-1,place2,15,graph);
          
        }
        else if(place1 == place2){
        	printf("\n\n\t\t\t\t\tTurn Around And Find Yourself At The Place , Voila ! ");
        }
        else{
            printf("\n\n\t\t\t\t\t\tEnter the correct places :( ");
        }
        int op;
     	  printf("\n\n\n\n %76s \n", "PRESS ANY KEY TO CONTINUE");
		    printf("\n %66s \n", "PRESS 2 TO EXIT");
		    printf("\n\n %80s  ", " What is your option (1 OR 2)?");
		    scanf("%d",&op);   
		    if(op==2){
			  printf("\n\n\n\t\t\t\t\t\tQuick Tip ! Do Not Take Shortcuts In Life !!!");
			  printf("\n\t\t\t\t\t\tBye Bye, See you next time :)");
			  exit(0);
		}
    }while(place1 <= 15 && place2 <= 15);
}

int main(){
  printf("\t\t\t\t  **********************************************************************************************  \n");
	printf("\t\t\t\t  ----------------------------------------------------------------------------------------------  \n\n");
	printf("%101s \n\n", "Welcome To C.V. Raman Global University ");
	printf("\t\t\t\t  ----------------------------------------------------------------------------------------------  \n");
	printf("\t\t\t\t  **********************************************************************************************  \n\n\n\n");
	int option;
	do {
		printf("%118s","-------------<: Find The Shortest Path to Reach AnyWhere in CGU :>-------------");

		printf("\n\n\n\n %80s \n", "PRESS 1 TO CONTINUE");
		printf("\n %76s \n", "PRESS 2 TO EXIT");
		printf("\n\n %90s  ", " What is your option (1 OR 2)?");
		scanf("%d", &option);

		switch (option) {
		case 1:
			interface();
			break;
		case 2:
			printf("\nQuick Tip ! Do Not Take Shortcuts In Life !!!");
			printf("\nBye Bye, See you next time :)");
			
			exit(0);
			break;
		default:
			printf("Please select a correct number (1 OR 2)!\n");
		}
	} while (option != 2);
    return 0;
}