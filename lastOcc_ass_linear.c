#include<stdio.h>
#define SIZE   6

//int comparisons;

int linear_search(int arr[SIZE] , int key);

int main(){

int arr[SIZE]={1,2,5,2,6,2};
int key;

printf("Enter the key\n");
scanf("%d",&key);

int result = linear_search(arr,key);

if(result == -1)
printf("key is not found\n");

else
printf("key is found index : %d\n",result);
//printf("comparisons = %d\n",comparisons);

return 0;
}

int linear_search(int arr[SIZE] , int key){

   int lastocuurance = -1;
    for(int i=0 ; i<SIZE ; i++){
        
        //comparisons++;

        if(key == arr[i]){

           lastocuurance = i;
        }
    }
           return lastocuurance;

}