#include<stdio.h>

int binary_search(int arr[], int Size , int key)
{
    int left=0 ,right = Size-1, mid;

    while(left <= right){

        //mid = left + (right - left) /2;
         mid = (left + right)/2;


        if(key == arr[mid])
        return mid;

        //else if(key < arr[mid])
        else if(key > arr[mid])
         right = mid - 1;

        else
        left = mid + 1;
    }
    return -1;
}



int main(){

//int arr[]={11,22,33,44,55,66,77,88,99};
int arr[] = {99,88,77,66,55,44,33,22,11};
int key;

printf("Enter the key\n");
scanf("%d",&key);


int index = binary_search(arr,9,key);

//index = binary_search_recursive(arr,0,8,key);

if(index != -1){
printf("key is found index = %d\n", index);
//printf("");
}

else
printf("key is not found\n");

return 0;
}