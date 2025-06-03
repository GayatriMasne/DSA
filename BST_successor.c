#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct  node *left;
    struct node*right;
}node_t;

typedef struct bst{
    node_t *root;
}bst_t;


void init_bst(bst_t *bst)
{
    bst->root = NULL;
}

int isEmpty(bst_t *bst){
    return bst->root == NULL;
}
node_t *create_node(int value){
    node_t *nn = (node_t *)malloc(sizeof(node_t));
    nn->data = value;
    nn->left = nn->right = NULL;
    return nn;
}

void add_node(bst_t *bst, int value)
{
    //1. create newnode 
    node_t *newnode = create_node(value);
    //2. if bst is empty
    if(bst->root == NULL)
        // add newnode into root itself
        bst->root = newnode;
    //3. if bst is not empty
    else{
        //3.1 create trav and start at root node
        node_t *trav = bst->root;
        while(1){
            //3.2 if value is less than current node data
            if(value < trav->data){
                //3.2.1 if left of current node is empty
                if(trav->left == NULL){
                    trav->left = newnode;
                    break;
                }
                //3.2.2 if left of current node is not empty
                else
                    trav = trav->left;
            }
            //3.3 if value is greater or equal than current node data
            else{
                //3.2.1 if right of current node is empty
                if(trav->right == NULL){
                    trav->right = newnode;
                    break;
                }
                //3.2.2 if right of current node is not empty
                else
                    trav = trav->right;
            }
        }//3.4 repeat step 3.2 and 3.3 untill node is added into bst
    }
}



void inorder(node_t *trav){
    if(trav == NULL)
    return;
    inorder(trav->left);
    printf("%-4d",trav->data);
    inorder(trav->right);
}


void delete_Node(bst_t *bst, int key)
{
    //1. search key node along with its parent
    node_t *trav = bst->root;
    node_t *parent = NULL;
    while(trav != NULL){
        if(key == trav->data)
            break;
        parent = trav;
        if(key < trav->data)
            trav = trav->left;
        else
            trav = trav->right;
    }
    //2. if node to be deleted is not found
    if(trav == NULL)
        return;
    //3. Node to be deleted has two childs
    if(trav->left != NULL && trav->right != NULL){
        //3.1 find successor
        node_t *suces = trav->right;
        parent = trav;
        while(suces->left != NULL){
            parent = suces;
            suces = suces->left;
        }
        //3.2 update the value of node to be deleted by its successor
        trav->data = suces->data;
        //3.3 mark successor for deletion
        trav = suces;
    }
    //4. Node to be deleted has single child (left)
    if(trav->left != NULL){
        if(trav == bst->root)
            bst->root = trav->left;
        else if(trav == parent->left)
            parent->left = trav->left;
        else if(trav == parent->right)
            parent->right = trav->left;
    }
    //5. Node to be deleted has single child (right)
    else //if(trav->right != NULL){
    {
        if(trav == bst->root)
            bst->root = trav->right;
        else if(trav == parent->left)
            parent->left = trav->right;
        else if(trav == parent->right)
            parent->right = trav->right;
    }
    free(trav);
}




void delete_all(node_t *trav)
{
    if(trav == NULL)
        return;
    delete_all(trav->left);
    delete_all(trav->right);
    free(trav);
}

int main(){
bst_t bst;
init_bst(&bst);

    add_node(&bst, 8);
    add_node(&bst, 3);
    add_node(&bst, 10);
    add_node(&bst, 2);
    add_node(&bst, 15);
    add_node(&bst, 6);
    add_node(&bst, 14);
    add_node(&bst, 4);
    add_node(&bst, 7);

    printf("INorder :");
    inorder(bst.root);
    printf("\n");

delete_Node(&bst,8);

printf("INorder :");
    inorder(bst.root);
    printf("\n");

delete_all(bst.root);
 bst.root = NULL;
    return 0;
}