#include<stdio.h>
struct treenode
{
    int val;
    struct treenode* left;
    struct treenode* right;
};

struct treenode* createNode(int x)
{
    struct treenode* a = (struct treenode*)malloc(sizeof(struct treenode));
    a->val=x;
    a->left=NULL;
    a->right=NULL;

    return a;
}

void postorder(struct treenode* ptr)
{
    if(ptr != NULL)
    {
        postorder(ptr->left);
        postorder(ptr->right);
        printf("%d ",ptr->val);
    }
}
void preorder(struct treenode* ptr)
{
    if(ptr != NULL)
    {
        printf("%d ",ptr->val);
        preorder(ptr->left);
        preorder(ptr->right);
    }
}
void inorder(struct treenode* ptr)
{
    if(ptr != NULL)
    {
        inorder(ptr->left);
        printf("%d ",ptr->val);
        inorder(ptr->right);
    }
}
int main()
{  
    struct treenode* root;

    root = createNode(1);                      // level 0

    root->left=createNode(2);                  // level 1
    root->right=createNode(3);

    root->left->left=createNode(4);            // level 2
    root->left->right=createNode(5);
    root->right->left=createNode(6);

    root->right->left->right=createNode(7);    // level 3

    preorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    inorder(root);
    printf("\n");

    return 0;

}