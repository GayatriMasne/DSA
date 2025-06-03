#include<stdio.h>
#define SIZE  6

void print_array( int arr[], int N)
{
  for(int i = 0; i < N ; i++)
  printf("%-4d",arr[i]);

  printf("\n");
}

void insertion_sort(int arr[] , int N){
int temp,j;

for(int i =N-2; i >=0 ; i--){
temp = arr[i];
 for(j = i+1; j > i; j++){
  if(arr[j]>temp){
    arr[j-1] = arr[j];

  }

    else 
     break ;
}
   arr[j-1] = temp;
}

}

int main(){

int arr[SIZE] = {55,44,22,66,11,33};
printf("Before Array\n");
print_array(arr,SIZE);

insertion_sort(arr,SIZE);

printf("After Array\n");
print_array(arr,SIZE);

    return 0;
}