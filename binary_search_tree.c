#include <stdio.h>
#include <malloc.h>

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

typedef struct node node;

node* root = NULL;

void addNode(int val,node* temp)
{
	if(temp == NULL)
	{
		root = (node*) malloc(sizeof(node));
		root->data = val;
		root->left = NULL;
		root->right = NULL;
		return;
	}
	if(temp->data > val)
	{
		if(temp->left != NULL)
			addNode(val,temp->left);
		else
		{
			temp->left = (node*) malloc(sizeof(node));
			temp->left->data = val;
			temp->left->left = NULL;
			temp->left->right = NULL;				
		}
	}
	else
	{
		if(temp->right != NULL)
			addNode(val,temp->right);
		else
		{
			temp->right = (node*) malloc(sizeof(node));
			temp->right->data = val;
			temp->right->left = NULL;
			temp->right->right = NULL;				
		}		
	}
}

void inorderTraversal(node* temp) 
{

	if(temp == NULL)
		return;
	inorderTraversal(temp->left);
	printf("%d\n", temp->data);
	inorderTraversal(temp->right);

}

void preOrderTraversal(node* temp)
{

	if(temp == NULL)
		return;
	printf("%d\n",temp->data);
	preOrderTraversal(temp->left);
	preOrderTraversal(temp->right);

}

void postOrderTraversal(node* temp)
{
	
	if(temp == NULL)
		return;
	postOrderTraversal(temp->left);
	postOrderTraversal(temp->right);
	printf("%d\n", temp->data);

}

int main()
{

	/*
	*Implementation of BST
	*Searching improved
	*/
	addNode(4,root);
	addNode(3,root);
	addNode(6,root);
	addNode(5,root);
	printf("Inorder Traversal\n");
	inorderTraversal(root);
	printf("Preorder Traversal\n");
	preOrderTraversal(root);
	printf("Postorder Traversal\n");
	postOrderTraversal(root);
	return 0;

}