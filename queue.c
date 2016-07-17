#include <stdio.h>
#include <malloc.h>
#include <limits.h>

struct node
{
	int data;
	struct node* next;
};

struct node* head = NULL;

void enqueue(int val)
{
	struct node* p =(struct node*) malloc(sizeof(struct node));
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
	return;
}

int dequeue()
{
	int value;
	if(head == NULL)
	{
		printf("Queue is empty\n");
		return INT_MIN;
	}
	value = head->data;
	head = head->next;
	return value;
}

int main()
{
	/*
	*Implementation of Queue 
	*FIFO Property
	*/
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		enqueue(i);
	}
	for (i = 0; i < 6; i++)
	{
		printf("%d\n",dequeue());
	}
	return 0;
}