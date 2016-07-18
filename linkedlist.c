#include <stdio.h>
#include <malloc.h>

struct node
{
	int data;
	struct node* next;
};

struct node* head = NULL;

/*
This function inserts a particular data at the end of linkedlist
Complexity O(n)
*/
void insertEnd(int val)
{
	struct node* p = (struct node*) malloc(sizeof(struct node));
	p->data = val;
	p->next = NULL;
	struct node* temp = head;
	if(temp == NULL)
	{
		head = p;
		return;

	}
	while(temp->next != NULL)
		temp = temp->next;
	temp->next = p;
}

/*
This function inserts a particular data at the front of linkedlist
*/
void insertFront(int val)
{
	struct node *p = (struct node *) malloc(sizeof(struct node));
	p->data = val;
	p->next = NULL;
	struct node* temp = head;
	if(temp == NULL)
	{
		head = p;
		return;
	}
	p->next = temp;
	head = p;
}

/*
Linear search is the only possible search in single linked list
This also works if same value is repeated multiple times
Complexity O(n)
*/
void linearSearch(int val)
{
	struct node *temp = head;
	while(temp != NULL)
	{
		if(temp->data == val)
			printf("%d\n", temp->data);
		temp = temp->next;
	}
}

/*
Delete a node with a particular value
Also works if the value is not preset in linked list
*/
void delete(int val)
{
	struct node *temp = head;
	//When temp is head and it is to be deleted
	if(temp->data == val)
	{
		head = temp->next;
		return;
	}
	//When data to delete is not on head and also checks that wheter it is in linked list or not
	while(temp->next->data != val)
	{
		temp = temp->next;
		if(temp->next == NULL)
		{
			printf("Not found\n");
			return;
		}
	}
	temp->next = temp->next->next;
}

void printLinkedList()
{
	struct node* temp = head;
	//Keep on traversing till we dont hit the null of linked list
	while(temp != NULL)
	{	
		printf("%d\n", temp->data);
		temp = temp->next;
	}
}

//Reversing Linkedlist recursively with just 2 pointers
void reverseLinkedList(struct node* previous, struct node* current)
{
	//If we reached last node of not reversed linked list then we will have to make last node head
	//and its next should be previous and its method call should get over
	if(current->next == NULL)
	{
		head = current;
		current->next = previous;
		return;
	}
	//Else we are in middle of linked list then we should keep traversing through it 
	//till we dont reach last node
	reverseLinkedList(current, current->next);
	//Assuming all recursive calls worked fine we will reverse chain for these set of previous
	//and current node pointers 
	current->next = previous;
}

int main()
{
	insertEnd(1);
	insertEnd(2);
	insertEnd(3);
	insertEnd(4);
	insertEnd(5);
	insertFront(0);
	printf("LinkedList is not reversed\n");
	printLinkedList();
	reverseLinkedList(NULL,head);
	printf("Now LinkedList is reversed!\n");
	printLinkedList();
	return 0;
}