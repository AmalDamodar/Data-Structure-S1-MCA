#include<stdio.h>
#include<conio.h>
void insert();
void delete();
void display();
struct node
{
 int data;
 struct node *link;
 };
struct node *front,*rear,*ptr;
void main()
{
int ch,n;
clrscr();
front=NULL;
rear=NULL;
printf("Enter the no of elements:");
scanf("%d",&n);
while(ch!=4)
{
printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit");
printf("\nEnter the choice:");
scanf("%d",&ch);
switch(ch)
{
 case 1:{
	insert();
	break;
	}
 case 2:{
	delete();
	break;
	}
 case 3:{
	display();
	break;
	}
 case 4:{
	printf("\nExiting");
	break;
	}
 default:printf("\Invalid");
 }
 };
 getch();
 }
 void insert()
 {
 struct node *newNode;
 newNode=(struct node *)malloc(sizeof(struct node));
 printf("\nEnter the element to insert:");
 scanf("%d",&newNode->data);
 newNode->data=newNode->data;
 newNode->link=NULL;
 if(rear==NULL)
 {
  front=newNode;
  rear=newNode;
  }
  else
  {
  rear->link=newNode;
  rear=newNode;
  printf("\nElement inserted");
  }
  }
  void delete()
  {
  struct node *dele;
  if(front==NULL)
   printf("\nUnderflow");
  else
  {
  dele=front;
  front=front->link;
  if(front==NULL)
   rear=NULL;
  printf("\nElement deleted %d",dele->data);
  free(dele);
  }
  }
  void display()
  {
  struct node *temp=front;
  if(front==NULL && rear==NULL)
  {
   printf("\nQueue is empty");
   }
  printf("\nThe elements are:");
  while(temp!=NULL)
  {
   printf("%d\t",temp->data);
   temp=temp->link;
  }
  }




