#include <stdio.h>
#include <malloc.h>
#include <limits.h>

struct node
{
	int data;
	struct node* next;
};

struct node* top_of_stack;

void push(int val)
{
	struct node* p = (struct node*) malloc(sizeof(struct node));
	p->data = val;
	p->next = NULL;
	struct node* temp = top_of_stack;
	if(isEmpty())
	{
		top_of_stack = p;
		return;
	}
	p->next = top_of_stack;
	top_of_stack = p;
	return;
}

int pop()
{
	int val;
	if(isEmpty())
	{
		printf("Stack is empty\n");
		return INT_MIN;
	}
	val = top_of_stack->data;
	top_of_stack = top_of_stack->next;
	return val;
}

int isEmpty()
{
	if(top_of_stack == NULL)
		return 1;
	return 0;
}

int main()
{
	/*
	*Implementation of Stack
	*LIFO Property
	*/
	int i;
	top_of_stack = NULL;
	for (i = 0; i < 5; i++)
	{
		push(i);
	}
	for (i = 0; i < 6; i++)
	{
		printf("%d\n", pop());
	}
	return 0;
}