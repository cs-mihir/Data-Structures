#include <stdio.h>
#include <malloc.h>

struct node
{
	int data;
	struct node* next;
};

struct node* head = NULL;

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
	while(temp != NULL)
	{	
		printf("%d\n", temp->data);
		temp = temp->next;
	}
}

int main()
{
	insertEnd(1);
	insertEnd(2);
	insertEnd(3);
	insertEnd(4);
	insertEnd(5);
	insertFront(0);
	delete(0);
	delete(6);
	printLinkedList();
	return 0;
}