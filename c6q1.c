#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void inorderTraversal(struct Node* node)
{
    if (node == NULL)
    {
        return;
    }
    inorderTraversal(node->left);
    printf("%d ", node->data);
    inorderTraversal(node->right);
}

void preorderTraversal(struct Node* node)
{
    if (node == NULL)
    {
        return;
    }
    printf("%d ", node->data);
    preorderTraversal(node->left);
    preorderTraversal(node->right);
}


void postorderTraversal(struct Node* node)
{
    if (node == NULL)
    {
        return;
    }
    postorderTraversal(node->left);
    postorderTraversal(node->right);
    printf("%d ", node->data);
}

struct Node* insert(struct Node* node, int data)
{
    if (node == NULL)
    {
        node=newNode(data);
        return node;
    }
        if (data <= node->data)
        node->left = insert(node->left, data);
        else
        node->right = insert(node->right, data);
    return node;
}

struct Node* InorderSuccessor(struct Node* node,struct Node** parent)
{
    struct Node*ptr=node;
    if(node->right==NULL)
    return ptr;
    if(node->right !=NULL)
    {
         ptr=ptr->right;
   	 while (ptr!=NULL && ptr->left != NULL)
   	 {
		 (*parent)=ptr;
        	 ptr=ptr->left;
    	 }
    }
    return ptr;
}

void Delete(struct Node* root,int data)
{
     struct Node* ptr=root;
     struct Node* parent=NULL;
    if (ptr == NULL)
    {
        printf("TREE IS EMPTY\n");
	return;
    }
    while(ptr!=NULL && ptr->data!=data)
    {
    	if(data < ptr->data)
	{
		parent=ptr;
		ptr=ptr->left;
	}
	else if(data > ptr->data)
	{
		parent=ptr;
		ptr=ptr->right;
	}
    }

    if(ptr==NULL)
    {
	printf("\nITEM NOT FOUND\n");
    }
    else
    {
	if(ptr->left == NULL && ptr->right == NULL)
	{
		if(parent->right == ptr)
		{
			parent->right=NULL;
			free(ptr);
		}
		else
		{
			parent->left=NULL;
			free(ptr);
		}
	}
	else if(ptr->left!=NULL &&  ptr->right!=NULL)
	{
		struct Node*temp=InorderSuccessor(ptr,&parent);
		ptr->data=temp->data;
		if(parent->right == temp)
                {
                        parent->right=NULL;
                        Delete(ptr,temp->data);
                }
                else
                {
                        parent->left=NULL;
                        Delete(ptr,temp->data);
                }
	}
	else
	{
		if(ptr->left==NULL)
		{
			 if(parent->right == ptr)
    	                 {
                             parent->right=ptr->right;
                             free(ptr);
                         }
                         else
                         {
                              parent->left=ptr->right;
                              free(ptr);
                         }
		}
		else
		{
       			 if(parent->right == ptr)
                         {
                             parent->right=ptr->left;
                             free(ptr);
                         }
                         else
                         {
                              parent->left=ptr->left;
                              free(ptr);
                         }

		}
	}
    }
}
   /* if (data < root->data)
    root->left = Delete(root->left, data);
    else if (data > root->data)
    root->right = Delete(root->right, data);
    else
    {
        if (root->left == NULL)
        {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = InorderSuccessor(root->right);
        root->data = temp->data;
        root->right = Delete(root->right, temp->data);
    }
    return root;*/


int main()
{
    struct Node* root = NULL;
    int c,item;
    do
    {
        printf("\n1-INSERT 2-DELETE 3-INORDER TRAVERSAL\n4-PREORDER TRAVERSAL 5-POSTORDER TRAVERSAL 6-EXIT\nENTER CHOICE : ");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
            printf("Enter item to be inserted : ");
            scanf("%d",&item);
            if(root==NULL)
            root=insert(root,item);
            else
            insert(root,item);
            break;

            case 2:
            printf("Enter item to be deleted : ");
            scanf("%d",&item);
            Delete(root,item);
            break;

            case 3:
            printf("In-order traversal of the tree:\n");
            inorderTraversal(root);
            printf("\n");
            break;

            case 4:
            printf("pre order traversal of the tree:\n");
            preorderTraversal(root);
            printf("\n");
            break;

            case 5:
            printf("post order traversal of the tree:\n");
            postorderTraversal(root);
            printf("\n");
            break;

            case 6 :
          while(root!=NULL)
            {
               Delete(root,root->data);
            }
            break;
        }
    }while(c!=6);
    return 0;
}
