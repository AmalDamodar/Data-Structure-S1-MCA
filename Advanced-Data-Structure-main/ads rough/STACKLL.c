#include <stdio.h>
#include <stdlib.h>
void push();
void pop();
void display();
struct node
{
int data;
struct node *link;
};
struct node *top;
void main()
{
    int ch,n;
    while(ch != 4)
    {
	printf("\n1.Push\n2.Pop\n3.Display\n4.Exit");
	printf("\n Enter your choice:");
	scanf("%d",&ch);
	switch(ch)
	{
	    case 1:{
		    push();
		    break;
		    }
	    case 2:  {
		      pop();
		      break;
		      }
	    case 3:  {
		     display();
		     break;
		     }
	    case 4:{
		    printf("\nExiting");

	    default:printf("Invalid choice ");
    }

};
getch();
}
void push()
{
    int item;
    struct node *newptr;
    newptr= (struct node*)malloc(sizeof(struct node));
    if(newptr== NULL)
	printf("\nUnable to insert");
    else
    {
	printf("Enter the element:");
	scanf("%d",&item);
	newptr->data =item;
	if(top==NULL)
	{
	    newptr -> link = NULL;
	}
	else
	{
	    newptr->link = top;
	}
	top=newptr;
    }
}

void pop()
{
    int item;
    struct node *temp;
    if (top == NULL)
    {
	printf("\nUnderflow");
    }
    else
    {
	item = top->data;
	temp = top;
	top = top->link;
	free(temp);
	printf("%d is deleted",item);

    }
}
void display()
{
    int i;
    struct node *ptr;
    if(top == NULL)
    {
	printf("Stack is empty\n");
    }
    else
    {
	 ptr=top;
	printf("Stack elements are:");
	while(ptr!=NULL)
	{
	    printf("\t%d\t",ptr->data);
	    ptr = ptr->link;
	}
    }
}