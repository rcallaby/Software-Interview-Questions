#include <stdio.h>
#include <stdlib.h>

/*
    This is a solution to the problem of printing all nodes of a given binary tree using inorder transversal without
    using recursion. 
*/
 
struct node 
{
    int data;
    struct node *left;
    struct node *right;
};
 
struct node *newNode(int data) 
{
    struct node *node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
   
    return node;
}
 
void printInorder(struct node* node) 
{
    struct node* current = node;
    struct node* pre;
 
    while (current != NULL) 
    {
        if (current->left == NULL) 
        {
            printf("%d ", current->data);
            current = current->right;
        }
        else
        {
            pre = current->left;
            while (pre->right != NULL && pre->right != current)
                pre = pre->right;
 
            if (pre->right == NULL) 
            {
                pre->right = current;
                current = current->left;
            }
            else 
            {
                pre->right = NULL;
                printf("%d ", current->data);
                current = current->right;
            }
        }
    }
}
 
int main() 
{
    struct node* root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5); 
 
    printf("\nInorder traversal of the binary tree is \n");
    printInorder(root);
 
    getchar();
    return 0;
}