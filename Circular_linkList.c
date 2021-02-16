#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node *next;
};
 typedef struct node node;
 node *getnode();
int main()
  {
  node *start,*end;
  int ch,item,pos,n;
  InitializeCLL(&start,&end);
  clrscr();
  printf("\nEnter the number of elements : ");
  scanf("%d",&n);
  CreateCLL(&start,&end);
  while(ch!=4)
  {
     printf("\n 1.Insert");
     printf("\n 2.Delete");
     printf("\n 3.Display");
     printf("\n 4.exit");
   printf("\nEnter the choice : ");
   scanf("%d",&ch);
   switch(ch)
    {
    case 1:{
	   printf("\nEnter the element : ");
	   scanf("%d",&item);
	   printf("\nEnter the position : ");
	   scanf("%d",&pos);
	   InsertCLL(&start,&end,item,pos);
	   break;
	   }
    case 2:{
	    printf("\nEnter the node to delete : ");
	    scanf("%d",&pos);
	    DeleteCLL(&start,&end,pos);
	    break;
	    }
    case 3:DisplayCLL(start,end);
	   break;
    case 4:printf("\nClosing...");
	   exit(0);
    default:printf("Invalid");
    }
    }
    getch();
    }
InitializeCLL(node **start,node **end)
  {
  (*start)=NULL;
  (*end)=NULL;
  }
CreateCLL(node **s,node **e,int n)
 {
 node *temp,*current;
 int i,item;
 for(i=1;i<=n;i++)
  {
   printf("\nEnter the element at position %d : ",i);
   scanf("%d",&item);
   temp=getnode();
   temp->data=item;
   if(*s==NULL)
     *s=temp;
   else
     (*e)->next=temp;
   (*e)=temp;
   }
    }
DisplayCLL(node *start,node *end)
 {
  if(start==NULL)
   {
   printf("\nList is empty");
   return;
   }
  printf("\nThe elements in the list are \n");
  do
  {
   printf("%d ",start->data);
   start=start->next;
   }while(end->next!=start);
  printf("\n");
   }
InsertCLL(node **start,node **end,int item,int pos)
 {
  node *current,*previous,*temp;
  int i;
  temp=getnode();
  if(temp==NULL)
   {
   printf("\nError");
   return;
   }
  if((*start==NULL)||(pos==1))
  {
  temp->data=item;
  temp->next=(*start);
  if(*end==NULL)
    (*end)=temp;
  else
    (*end)->next=temp;
  (*start)=temp;
  return;
  }
  current=(*start);
  i=2;
  while(current->next!=NULL)
  {
  if(i==pos)
   {
    temp->data=item;
    temp->next=current->next;
    current->next=temp;
    return;
   }
  else
   {
   i++;
   current=current->next;
   }
   }
   temp->data=item;
   temp->next=current->next;
   current->next=temp;
   (*end)=temp;
   }
DeleteCLL(node **start,node **end,int pos)
   {
   node *current,*temp;
   int item,i;
   if(*start==NULL)
    {
    printf("\nEmpty List");
    return;
    }
   if(pos==1)
    {
    current=(*start);
    item=current->data;
    if((*start)->next==(*start))
      (*start)=(*end)=NULL;
    else
      {
      (*start)=(*start)->next;
      (*end)->next=(*start);
      }
    freenode(current);
    printf("\nDeleted element is %d",item);
    }
    current=(*start);
    i=2;
    while(current->next!=(*start))
     {
     if(i==pos)
      {
      temp=current->next;
      item=temp->data;
      current->next=temp->next;
      freenode(temp);
      printf("\nDeleted element is %d",item);
      return;
      }
     else
       current=current->next;
     i++;
      }
     printf("\nInvalid Value");
     }
     node *getnode()
     {
     node *t;
     t=(node *)malloc(sizeof(node));
     return t;
     }
     freenode(node *t)
     {
     free(t);
     }