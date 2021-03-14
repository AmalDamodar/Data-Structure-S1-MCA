#include<stdio.h>
#include<conio.h>
#define maxsize 25
void cqinsert();
void cqdelete();
void cqdisplay();
void cqfele();
void cqrele();
int front=-1,rear=-1;
int q[maxsize];
void main()
{
  int ch,n;
  clrscr();
  printf("Enter the no of elements:");
  scanf("%d",&n);
  printf("\nOperations on circular queue:");
  while(ch!=6)
  {
   printf("\n1.INSERT\n2.DELETE\n3.DISPLAY\n4.FRONT ELEMENT\n5.REAR ELEMENT\n6.EXIT");
   printf("\nEnter the choice:");
   scanf("%d",&ch);
   switch(ch)
    {
    case 1:{
	    cqinsert();
	    break;
	    }
    case 2:{
	    cqdelete();
	    break;
	    }
    case 3:{
	    cqdisplay();
	    break;
	    }
    case 4:{
	    cqfele();
	    break;
	    }
    case 5:{
	    cqrele();
	    break;
	    }
    case 6:{
	   printf("\nExiting");
	   break;
	   }
    default:printf("\nInvalid choice");
    }
    };
    getch();
    }
    void cqinsert()
    {
     int item;
     printf("\nEnter the element:");
     scanf("%d",&item);
     if(front==0 && rear==(maxsize-1))
      {
      printf("\nOverflow");
      return;
      }
      else
      {
      rear=(rear+1) % maxsize;
      q[rear]=item;
      }
      if(front==-1)
       front=0;
     printf("\nElement inserted");
     }
     void cqdelete()
     {
      int item;
      if(front==-1)
      {
      printf("\nUnderflow");
      return;
      }
      else
      {
      item=q[front];
      if(front==rear)
      {
      front=-1;
      rear=-1;
      }
      else
       front=(front+1) % maxsize;
       }
      printf("Element deleted is %d",item);
      }
      void cqdisplay()
      {
       int i;
       if(rear==-1)
	printf("\nEmpty queue");
       else
	{
	 printf("\nThe elements are:");
	 for(i=front;i<=rear;i++)
	 {
	  printf("%d\t",q[i]);
	  }
	 }
	 }
	void cqfele()
	{
	int item;
	if(front==-1)
	 printf("\nEmpty queue");
	else
	{
	item=q[front];
	printf("\nThe front element is %d",item);
	}
	}
	void cqrele()
	{
	int item;
	if(rear==-1)
	printf("\nEmpty queue");
	else
	{
	item=q[rear];
	printf("The rear element is %d",item);
	}
	}

