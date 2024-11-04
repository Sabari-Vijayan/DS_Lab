#include<stdio.h>
#include<stdlib.h>
int array[50];
int i;
struct Node
{
    struct Node* lchild;
    int data;
    struct Node* rchild;
}node;
void buildtree(struct Node* ptr,int item)
{
    int option;
    int newitem;
    if(ptr!=NULL)
    {
        ptr->data=item;
        printf("Does node %d have left child\nIf yes enter 1 else any other\n",ptr->data);
        scanf("%d",&option);
        if(option==1)
        {
            struct Node* lc=(struct Node*)malloc(sizeof(struct Node));
            ptr->lchild=lc;
            printf("Enter data\n");
            scanf("%d",&newitem);
            buildtree(lc,newitem);
        }
        else
        {
            buildtree(NULL,-99999);
        }
        printf("Does node %d have right child\nIf yes enter 1 else any other\n",ptr->data);
        scanf("%d",&option);
        if(option==1)
        {
            struct Node* rc=(struct Node*)malloc(sizeof(struct Node));
            printf("Enter data\n");
            scanf("%d",&newitem);
            ptr->rchild=rc;
            buildtree(rc,newitem);
        }
        else
        {
            buildtree(NULL,-99999);
        }
    }
}

void preorder(struct Node* ptr)
{
    if(ptr!=NULL)
    {
	printf("%d ",ptr->data);
        preorder(ptr->lchild);
        preorder(ptr->rchild);
    }
}

void inorder(struct Node* ptr)
{
    if(ptr!=NULL)
    {
        inorder(ptr->lchild);
        printf("%d ",ptr->data);
        inorder(ptr->rchild);
    }
}

void postorder(struct Node* ptr)
{
    if(ptr!=NULL)
    {
        postorder(ptr->lchild);
        postorder(ptr->rchild);
	printf("%d ",ptr->data);
    }
}

int main()
{
    int item;
    struct Node* root=(struct Node*)malloc(sizeof(struct Node));
    printf("enter item to root node : ");
    scanf("%d",&item);
    buildtree(root,item);
    printf("Inorder traversal : ");
    inorder(root);
    printf("postorder traversal : ");
    postorder(root);
    printf("Preorder traversal : ");
    preorder(root);
    return 0;
}
