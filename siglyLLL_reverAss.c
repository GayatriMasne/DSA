#include<stdio.h>
#include<stdlib.h>

typedef struct node{
   int data;
   struct node *next;
}node_t;

typedef struct list
{
    node_t *head;
    node_t *tail;
}list_t;


void init_list(list_t *list){
    list->head =NULL;
}

int isEmpty(list_t *list){
    return list->head == NULL;
}

node_t *create_node(int value)
{
    node_t *newnode = (node_t *)malloc(sizeof(node_t));
    newnode->data = value;
    newnode->next = NULL;
    return newnode;
}

void add_first(list_t *list, int value){
    node_t *newnode = create_node(value);
    
    newnode->next = list->head;

    list->head = newnode;
}

void add_last(list_t *list, int value){
    node_t *newnode = create_node(value);

    if(list->head == NULL)
    list->head = newnode;

    else  
    {
       node_t *trav = list->head;
     while (trav->next != NULL)
     trav = trav->next;
        
     trav->next = newnode;
   }
}



void display_list(list_t *list){
    node_t *trav = list->head;
    printf("List : ");

    while (trav != NULL){
     printf("%-4d",trav->data);

     trav = trav->next;
    }
    printf("\n");
}

node_t *reverse_list(list_t *list){
    node_t *t1 = NULL;
    node_t *t2 = list->head;
    node_t *t3;

    while (t2 != NULL)
    {
      t3 = t2->next;
      t2->next = t1;
      t1 = t2;
      t2 = t3;
    }

     return list->head = t1;
}

void delete_list(list_t *list){

    node_t *trav = list->head;
    while (trav != NULL)
    {
        node_t *temp = trav;

        trav = trav->next;
        free(temp);
    }
    list->head = NULL;
}

int main()
{
    list_t l1;

    init_list(&l1);
    add_first(&l1,40);
    add_first(&l1,30);
    add_first(&l1,20);

   printf("before reverse \n");
    display_list(&l1);
   
    int  res = reverse_list(&l1);
   printf("after reverse \n");
    display_list(&l1);

    delete_list(&l1);
    
    return 0;
}