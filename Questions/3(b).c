#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data; 
    struct node *right; 
    struct node *left; 
};

int search(struct node* root, int value) 
{ 
    while (root != NULL){

        if (value > root->data) 
            root = root->right; 

        else if (value < root->data)
            root = root->left; 
        else
            return 1; 
    } 
    return 0; 
} 

struct node* new_node(int x)
{
    struct node *p;
    p = malloc(sizeof(struct node));
    p->data = x;
    p->left = NULL;
    p->right = NULL;

    return p;
}

struct node* insert(struct node *root, int x)
{
    
    if(root==NULL)
        return new_node(x);
    else if(x>root->data) 
        root->right = insert(root->right, x);
    else
        root->left = insert(root->left,x);
    return root;
}

void print_nodes(struct node *root)
{
    if(root!=NULL)
    {
        /* The pointer points to the node on the left */
        print_nodes(root->left); 
        /* The pointer points to the parent node. */
        printf(" %d ", root->data); 
        /* The pointer points to the node on the right */
        print_nodes(root->right);
    }
}

int main()
{
    int item = 3;
    struct node *root;
    int found = 0;
    root = new_node(20);
    insert(root,3);
    insert(root,2);
    insert(root,12);
    insert(root,6);
    insert(root,9);
    insert(root,1);
    insert(root,45);
    insert(root,21);
    found = search(root, item);
    print_nodes(root);
    printf("\n");

    

    if(found)
        printf("\n %d value is found in the tree \n", item);
    else
        printf("\n %d value is not found in the tree \n", item);
    return 0;
}