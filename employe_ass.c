#include<stdio.h>


typedef struct{
    int empid;
    char name[50];
}Employee;
int employee_search(Employee employees[], int Size , int key)
{

    for(int i=0 ; i<Size ; i++){
        if(employees[i].empid == key){
           return i;
        }
    }
    return -1;

}



int main(){

//int arr[]={11,22,33,44,55,66,77,88,99};
int key;
Employee employees[] = {
    {11,"gayu"},{22,"Rani"},{33,"Pooja"},{44,"Rashi"},{55,"Kushi"}

};

printf("Enter the key\n");
scanf("%d",&key);


int index = employee_search(employees,5,key);

//index = binary_search_recursive(arr,0,8,key);

if(index != -1){
printf("key is found index = %d\n",index);
printf("ID: %d, Name: %s\n", employees[index].empid, employees[index].name);
}
else
printf("key is not found\n");

return 0;
}