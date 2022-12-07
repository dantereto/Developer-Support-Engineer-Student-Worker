#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data; 
    struct node *right; 
    struct node *left; 
};



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
    struct node *root;
    root = new_node(20);
    insert(root,3);
    insert(root,2);
    insert(root,12);
    insert(root,6);
    insert(root,9);
    insert(root,1);
    insert(root,45);
    insert(root,21);
       
    print_nodes(root);
    printf("\n");
    return 0;
}
