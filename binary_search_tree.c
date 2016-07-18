#include <stdio.h>
#include <malloc.h>

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

typedef struct node node;

struct qnode
{
	node* data;
	struct qnode* next;
};


typedef struct qnode qnode;

node* root = NULL;
qnode* head = NULL;

void enqueue(node* val)
{
	struct qnode* p =(qnode*) malloc(sizeof(qnode));
	p->data = val;
	p->next = NULL;
	struct qnode* temp = head;
	if(temp == NULL)
	{
		head = p;
		return;
	}
	while(temp->next != NULL)
		temp = temp->next;
	temp->next = p;
	return;
}

node* dequeue()
{
	node* value;
	if(isEmpty())
	{
		printf("Queue is empty\n");
		return NULL;
	}
	value = head->data;
	head = head->next;
	return value;
}

int isEmpty()
{
	if(head == NULL)
		return 1;
	return 0;
}

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

void levelOrderTraversal(node* root)
{
	enqueue(root);
	while(!isEmpty())
	{
		node* p = dequeue();
		printf("%d\n", p->data);
		if(p->left != NULL)
			enqueue(p->left);
		if(p->right != NULL)
			enqueue(p->right);
	}	
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
	addNode(1,root);
	printf("Inorder Traversal\n");
	inorderTraversal(root);
	printf("Preorder Traversal\n");
	preOrderTraversal(root);
	printf("Postorder Traversal\n");
	postOrderTraversal(root);
	printf("Levelorder Traversal\n");
	levelOrderTraversal(root);
	return 0;

}