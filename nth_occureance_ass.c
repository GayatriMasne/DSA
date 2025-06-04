#include<stdio.h>
#define SIZE   6

//int comparisons;

//int linear_search(int arr[SIZE] , int key);


int linear_search(int arr[SIZE] ,int n ,int size , int key){
    int count = 0;
    int index = -1;

    for(int i=0 ; i<SIZE ; i++){
        
        if(key == arr[i]){
           count ++;
            if(count == n){
                index = i;
            }
        }
    }
    return index;

}

int main(){

int arr[SIZE]={2,8,2,5,2,2};
int n = 4;
int key,size;

printf("Enter the key\n");
scanf("%d",&key);

int result = linear_search(arr,n,size,key);

if(result == -1)
printf("key is not found\n");

else{
printf("key is found result : %d\n",result);
printf("key is found result : %d  for nth occurence : %d \n",result,n);
}
//printf("comparisons = %d\n",comparisons);

return 0;
}

