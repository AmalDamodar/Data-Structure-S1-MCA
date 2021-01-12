#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct dnode
{
 struct dnode *left;
 int data;
 struct dnode *right;
};
typedef struct dnode dnode;
dnode *getnode();
int main()
    {
    dnode *first;
    int n,pos,item,ch;
    clrscr();
    InitializeDLL(&first);
    printf("Creation of Doubly Linked List");
    printf("\nEnter the no of elements:");
    scanf("%d",&n);
    CreateDLL(&first,n);
    while(ch!=9)
    {
     printf("\n1.Insert at first\n2.Insert at last\n3.Insert at any  Position");
     printf("\n4.Delete from first\n5.Delete from last\n6.Delete from any position");
     printf("\n7.Display the list\n8.Searching an element\n9.Exit");
     printf("\nEnter the choice:");
     scanf("%d",&ch);
     switch(ch)
     {
     case 1:{
	     printf("\nEnter the element:");
	     scanf("%d",&item);
	     InsertDLLf(&first,item);
	     break;
	     }
     case 2:{
	     printf("\nEnter the element:");
	     scanf("%d",&item);
	     InsertDLLl(&first,item);
	     break;
	     }
     case 3:{
	     printf("\nEnter the element:");
	     scanf("%d",&item);
	     printf("\nEnter the position to insert:");
	     scanf("%d",&pos);
	     InsertDLLpos(&first,pos,item);
	     break;
	     }
     case 4:{
	     DeleteDLLf(&first);
	     break;
	     }
     case 5:{
	     DeleteDLLl(&first);
	     break;
	     }
     case 6:{
	     printf("\nEnter the position to delete:");
	     scanf("%d",&pos);
	     DeleteDLLpos(&first,pos);
	     break;
	     }
     case 7:DisplayDLL(first);
	    break;
     case 8:{
	     SearchDLL();
	     break;
	     }
     case 9:exit(0);
	    break;
     default:printf("\nInvalid");
      }
      }
      getch();
      }
InitializeDLL(dnode **first)
{
 (*first)=NULL;
}
DisplayDLL(dnode *first)
{
 if(first==NULL)
  printf("\nList is empty");
 else
  {
  printf("\nDisplaying in forward direction");
  printf("\nFirst<->");
  while(first!=NULL)
   {
   printf("%d<->",first->data);
   first=first->right;
   }
   printf("Last\n");
   }
   }
CreateDLL(dnode **f,int n)
{
 dnode *temp,*current;
 int i,item;
 for(i=1;i<=n;i++)
  {
  printf("\nEnter the element %d",i);
  scanf("%d",&item);
  temp=getnode();
  temp->data=item;
  temp->right=NULL;
  if((*f)==NULL)
   {
   (*f)=temp;
   temp->left=NULL;
   }
  else
  {
   current->right=temp;
   temp->left=current;
  }
  current=temp;
  }
  }
InsertDLLf(dnode **first,int item)
{
 dnode *temp;
 temp=getnode();
 temp->data=item;
 temp->left=NULL;
 if(*first==NULL)
  temp->right=NULL;
 else
 {
  temp->right=(*first);
  (*first)->left=temp;
 }
 (*first)=temp;
}
InsertDLLl(dnode **first,int item)
{
 dnode *current,*temp;
 temp=getnode();
 temp->data=item;
 temp->right=NULL;
 if((*first)==NULL)
  {
  temp->left=NULL;
  (*first)=temp;
  }
 else
  {
  current=(*first);
  while(current->right!=NULL)
  current=current->right;
  temp->left=current;
  current->right=temp;
  }
 }
InsertDLLpos(dnode **first,int pos,int item)
{
 dnode *temp,*current;
 int i;
 temp=getnode();
 temp->data=item;
 if(pos==1)
  {
  if(*first!=NULL)
    (*first)->left=temp;
  temp->right=(*first);
  temp->left=NULL;
  (*first)=temp;
  }
  else
  {
  i=2;
  current=(*first);
  while((i<pos)&&(current->right!=NULL))
   {
   i++;
   current=current->right;
   }
  temp->left=current;
  temp->right=current->right;
  if(current->right!=NULL)
   temp->right->left=temp;
  current->right=temp;
  }
 }
SearchDLL(dnode **first)
{
 dnode *temp;
 int item;
 if(*first==NULL)
  {
   printf("\nList is empty");
   return;
  }
  printf("\nEnter the element to search:");
  scanf("%d",&item);
  temp=getnode();
  temp=(*first);
 while(temp!=NULL)
 {
  if(temp->data==item)
  {
   printf("\nElement %d found in the list",item);
   return;
   }
   else
    temp=temp->right;
    }
    printf("\n%d not found",item);
  }
DeleteDLLf(dnode **first)
 {
 dnode *current;
 int item;
 if(*first==NULL)
  {
  printf("\nList is empty");
  return;
  }
 current=(*first);
 (*first)=(*first)->right;
 if(*first!=NULL)
 (*first)->left=NULL;
 item=current->data;
 freenode(current);
 printf("\nDeleted element = %d",item);
 }
DeleteDLLl(dnode **first)
 {
 dnode *current;
 int item;
 if(*first==NULL)
  {
  printf("\nList is empty");
  return;
  }
 current=(*first);
 while(current->right!=NULL)
  current=current->right;
 if(current->left!=NULL)
  current->left->right=current->right;
 else
  (*first)=NULL;
 item=current->data;
 freenode(current);
 printf("\nDeleted element = %d",item);
 }
DeleteDLLpos(dnode **first,int pos)
 {
 dnode *current,*prev;
 int i=1,item;
 if(*first==NULL)
  {
  printf("\nList is empty");
  return;
  }
 current=(*first);
 while(current!=NULL)
  {
  if(i==pos)
   {
   item=current->data;
   if(current->left==NULL)
    {
     current->right->left=NULL;
     (*first)=current->right;
     freenode(current);
    }
    else if(current->right=NULL)
     {
      current->left->right=current->right;
      freenode(current);
     }
   else
   {
   current->left->right=current->right;
   current->right->left=current->left;
   freenode(current);
   }
   printf("\nDeleted element = %d",item);
   return;
   }
   i++;
   current=current->right;
  }
  printf("\nInvalid");
  }
  dnode *getnode()
  {
  dnode *p;
  p=(dnode *)malloc(sizeof(dnode));
  return (p);
  }
  freenode(dnode *p)
  {
  free(p);
  }



